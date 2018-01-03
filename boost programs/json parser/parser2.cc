#ifdef _MSC_VER
#include <boost/config/compiler/visualc.hpp>
#endif
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <cassert>
#include <exception>
#include <iostream>
#include <sstream>
#include <string>

int main()
{
    try
    {
        std::stringstream ss;
        // send your JSON above to the parser below, but populate ss first

        ss << "{ \"particles\": [ { \"electron\": { \"pos\": [ 0, 0, 0 ], \"vel\": [ 0, 0, 0 ] }, \"proton\": { \"pos\": [ -1, 0, 0 ], \"vel\": [ 0, -0.1, -0.1 ] } } ]}";


        boost::property_tree::ptree pt;
        boost::property_tree::read_json(ss, pt);

        BOOST_FOREACH(boost::property_tree::ptree::value_type &v, pt.get_child("particles"))
        {
            assert(v.first.empty()); // array elements have no names
            print(v.second);
        }
        return EXIT_SUCCESS;
    }
    catch (std::exception const& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return EXIT_FAILURE;
}
