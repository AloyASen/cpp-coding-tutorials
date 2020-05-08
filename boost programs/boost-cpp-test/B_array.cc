#include <iostream>
#include <boost/array.hpp>
using namespace std;
int main(int argc, char const *argv[])
{
    boost::array<int, 4> arr ={{1,2,3,4}};
    cout<<"hi this is a boost array programme "<<arr[0];
    return 0;
}
