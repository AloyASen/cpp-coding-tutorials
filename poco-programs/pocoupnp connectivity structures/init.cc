/*

in this program the system will communicate with another upnp device in the network. 

this upnp program will follow a simple ssdp protocol

this is the first test program 

hope that all goes well.

*/

#include "Poco/Net/HTTPServer.h"
#include "Poco/Net/HTTPRequestHandler.h"
#include "Poco/Net/HTTPRequestHandlerFactory.h"
#include "Poco/Net/HTTPServerParams.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/HTTPServerParams.h"
#include "Poco/Net/ServerSocket.h"
#include "Poco/Net/IPAddress.h"
#include "Poco/Net/NetworkInterface.h"
#include "Poco/Net/MulticastSocket.h"
#include "Poco/Util/ServerApplication.h"
#include "Poco/Util/Option.h"
#include "Poco/Util/OptionSet.h"
#include "Poco/Util/HelpFormatter.h"
#include "Poco/UPnP/SSDP/SSDPResponder.h"
#include "Poco/UPnP/SSDP/Advertisement.h"
#include "Poco/UPnP/URN.h"
#include "Poco/Timestamp.h"
#include "Poco/DateTimeFormatter.h"
#include "Poco/DateTimeFormat.h"
#include "Poco/StreamCopier.h"
#include "Poco/Exception.h"
#include "Poco/ThreadPool.h"
#include <sstream>
#include <iostream>


using Poco::Net::ServerSocket;
using Poco::Net::SocketAddress;
using Poco::Net::HTTPRequestHandler;
using Poco::Net::HTTPRequestHandlerFactory;
using Poco::Net::HTTPServer;
using Poco::Net::HTTPServerRequest;
using Poco::Net::HTTPServerResponse;
using Poco::Net::HTTPServerParams;
using Poco::Timestamp;
using Poco::DateTimeFormatter;
using Poco::DateTimeFormat;
using Poco::ThreadPool;
using Poco::Util::ServerApplication;
using Poco::Util::Application;
using Poco::Util::Option;
using Poco::Util::OptionSet;
using Poco::Util::HelpFormatter;
using Poco::UPnP::SSDP::SSDPResponder;
using Poco::UPnP::SSDP::Advertisement;


class TimeRequestHandler: public HTTPRequestHandler
{
public:
    TimeRequestHandler(const std::string& format): 
        _format(format)
    {
    }

    void handleRequest(HTTPServerRequest& request, HTTPServerResponse& response)
    {
        Timestamp now;
        std::string dt(DateTimeFormatter::format(now, _format));

        response.setChunkedTransferEncoding(true);
        response.setContentType("text/html");

        std::ostream& ostr = response.send();
        ostr << "<html><head><title>HTTPTimeServer powered by POCO C++ Libraries</title>";
        ostr << "<meta http-equiv=\"refresh\" content=\"1\"></head>";
        ostr << "<body><p style=\"text-align: center; font-size: 48px;\">";
        ostr << dt;
        ostr << "</p></body></html>";
    }

private:
    std::string _format;
};


class DeviceDescriptionRequestHandler: public HTTPRequestHandler
{
    void handleRequest(HTTPServerRequest& request, HTTPServerResponse& response)
    {
        Application& app = Application::instance();

        // NOTE: some "less capable" UPnP stacks have problems handling a HTTP/1.1 chunked response,
        // so we first buffer in a string stream and send the result with content-length header.
        std::stringstream responseStream;
        responseStream << "<?xml version=\"1.0\"?>\n";
        responseStream << "<root xmlns=\"urn:schemas-upnp-org:device-1-0\">\n";
        responseStream << "  <specVersion>\n";
        responseStream << "    <major>1</major>\n";
        responseStream << "    <minor>0</minor>\n";
        responseStream << "  </specVersion>\n";
        responseStream << "  <URLBase>http://" << request.serverAddress().toString() << "</URLBase>\n";
        responseStream << "  <device>\n";
        responseStream << "    <deviceType>urn:schemas-upnp-org:device:Basic:1</deviceType>\n";
        responseStream << "    <friendlyName>" << app.config().getString("upnp.device.friendlyName") << "</friendlyName>\n";
        responseStream << "    <manufacturer>" << app.config().getString("upnp.device.manufacturer") << "</manufacturer>\n";
        responseStream << "    <manufacturerURL>" << app.config().getString("upnp.device.manufacturerURL") << "</manufacturerURL>\n";
        responseStream << "    <modelDescription>" << app.config().getString("upnp.device.modelDescription") << "</modelDescription>\n";
        responseStream << "    <modelName>" << app.config().getString("upnp.device.modelName") << "</modelName>\n";
        responseStream << "    <UDN>uuid:" << app.config().getString("upnp.device.uuid") << "</UDN>\n";
        responseStream << "    <serviceList>\n";
        responseStream << "    </serviceList>\n";
        responseStream << "    <presentationURL>/</presentationURL>\n";
        responseStream << "  </device>\n";
        responseStream << "</root>\n";

        response.setContentType("text/xml");
        response.setContentLength(static_cast<int>(responseStream.tellp()));
        Poco::StreamCopier::copyStream(responseStream, response.send());
    }
};


class TimeRequestHandlerFactory: public HTTPRequestHandlerFactory
{
public:
    TimeRequestHandlerFactory(const std::string& format):
        _format(format)
    {
    }

    HTTPRequestHandler* createRequestHandler(const HTTPServerRequest& request)
    {
        Application& app = Application::instance();
        app.logger().information("Request from " + request.clientAddress().toString());

        if (request.getURI() == "/")
            return new TimeRequestHandler(_format);
        else if (request.getURI() == "/rootdevice.xml")
            return new DeviceDescriptionRequestHandler;
        else
            return 0;
    }

private:
    std::string _format;
};


class HTTPTimeServer: public Poco::Util::ServerApplication
{
public:
    HTTPTimeServer(): _helpRequested(false)
    {
    }

    ~HTTPTimeServer()
    {
    }

protected:
    void initialize(Application& self)
    {
        loadConfiguration(); // load default configuration files, if present
        ServerApplication::initialize(self);
    }

    void uninitialize()
    {
        ServerApplication::uninitialize();
    }

    void defineOptions(OptionSet& options)
    {
        ServerApplication::defineOptions(options);

        options.addOption(
            Option("help", "h", "Display help information on command line arguments.")
                .required(false)
                .repeatable(false));
    }

    void handleOption(const std::string& name, const std::string& value)
    {
        ServerApplication::handleOption(name, value);

        if (name == "help")
            _helpRequested = true;
    }

    void displayHelp()
    {
        HelpFormatter helpFormatter(options());
        helpFormatter.setCommand(commandName());
        helpFormatter.setUsage("OPTIONS");
        helpFormatter.setHeader("A web server that serves the current date and time and announces itself via UPnP SSDP.");
        helpFormatter.format(std::cout);
    }

    Poco::Net::NetworkInterface findActiveNetworkInterface()
    {
        Poco::Net::NetworkInterface::NetworkInterfaceList ifs = Poco::Net::NetworkInterface::list();
        for (Poco::Net::NetworkInterface::NetworkInterfaceList::iterator it = ifs.begin(); it != ifs.end(); ++it)
        {
            if (!it->address().isWildcard() && !it->address().isLoopback() && it->supportsIPv4()) return *it;
        }
        throw Poco::IOException("No configured Ethernet interface found");
    }

    int main(const std::vector<std::string>& args)
    {
        if (_helpRequested)
        {
            displayHelp();
        }
        else
        {
            // get parameters from configuration file
            unsigned short httpPort = static_cast<unsigned short>(config().getInt("http.port", 9980));
            std::string format(config().getString("datetime.format", DateTimeFormat::SORTABLE_FORMAT));

            // Find network interface
            std::string mcastInterfaceName = config().getString("upnp.interface", "");
            Poco::Net::NetworkInterface mcastInterface(mcastInterfaceName.empty() ? findActiveNetworkInterface() : Poco::Net::NetworkInterface::forName(mcastInterfaceName, Poco::Net::NetworkInterface::IPv4_ONLY));
            Poco::Net::IPAddress ipAddress(mcastInterface.address());

            logger().information(Poco::format("Using multicast network interface %s (%s).", mcastInterface.name(), ipAddress.toString()));

            Poco::UUID deviceUUID(config().getString("upnp.device.uuid"));
            int adLifetime = config().getInt("upnp.adLifetime", 60);

            Poco::Net::HTTPServerParams::Ptr pHTTPParams = new Poco::Net::HTTPServerParams;
            pHTTPParams->setSoftwareVersion(config().getString("http.softwareVersion", ""));
            pHTTPParams->setMaxQueued(config().getInt("http.maxQueued", 4));
            pHTTPParams->setMaxThreads(config().getInt("http.maxThreads", 4));
            pHTTPParams->setTimeout(Poco::Timespan(config().getInt("http.timeout", 5), 0));
            pHTTPParams->setKeepAlive(config().getBool("http.keepAlive", false));
            pHTTPParams->setMaxKeepAliveRequests(config().getInt("http.maxKeepAliveRequests", 10));
            pHTTPParams->setKeepAliveTimeout(Poco::Timespan(config().getInt("http.keepAliveTimeout", 10), 0));

            ThreadPool::defaultPool().addCapacity(pHTTPParams->getMaxThreads());

            // set-up a server socket
            SocketAddress httpSA(ipAddress, httpPort);
            ServerSocket httpSocket(httpSA);
            // set-up a HTTPServer instance
            HTTPServer httpServer(new TimeRequestHandlerFactory(format), httpSocket, pHTTPParams);
            // start the HTTPServer
            httpServer.start();

            // set up UPnP
            Poco::Net::SocketAddress ssdpSA(Poco::Net::IPAddress(), SSDPResponder::MULTICAST_PORT);
            Poco::Net::MulticastSocket ssdpSocket(ssdpSA);
            ssdpSocket.setTimeToLive(4);
            ssdpSocket.setInterface(mcastInterface);
            SSDPResponder ssdpResponder(ssdpSocket);
            std::string deviceLocation = "http://" + httpSA.toString() + "/rootdevice.xml";
            ssdpResponder.publish(new Advertisement(Advertisement::AD_ROOT_DEVICE, deviceUUID, deviceLocation, adLifetime));
            ssdpResponder.publish(new Advertisement(Advertisement::AD_DEVICE, deviceUUID, deviceLocation, adLifetime));
            ssdpSocket.joinGroup(ssdpResponder.groupAddress().host(), mcastInterface);
            ssdpResponder.start();

            // wait for CTRL-C or kill
            waitForTerminationRequest();

            // shut down UPnP
            ssdpResponder.stop();
            ssdpSocket.leaveGroup(ssdpResponder.groupAddress().host(), mcastInterface);

            // Stop the HTTPServer
            httpServer.stop();
        }
        return Application::EXIT_OK;
    }

private:
    bool _helpRequested;
};


POCO_SERVER_MAIN(HTTPTimeServer)
