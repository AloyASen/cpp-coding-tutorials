#ifndef WebSocketTest_INCLUDED
#define WebSocketTest_INCLUDED


#include "Poco/Net/Net.h"
#include "Poco/CppUnit/TestCase.h"


class WebSocketTest: public CppUnit::TestCase
{
public:
	WebSocketTest(const std::string& name);
	~WebSocketTest();

	void testWebSocket();
	void testWebSocketLarge();
	void testWebSocketLargeInOneFrame();

	void setUp();
	void tearDown();

	static CppUnit::Test* suite();

private:
	void testOneLargeFrame(int msgSize);
};


#endif // WebSocketTest_INCLUDED
