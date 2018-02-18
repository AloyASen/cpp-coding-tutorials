#include "Brain.hpp"
/*

the name of the objects along with its object  defination is 
to be stored on the disk ... and later serialized into raw disk files 

*/
namespace Brain {
    class Memorize : public Memory {
    public:
        virtual int panic() const{
            //when this code is run the source of the
            //compiler would try to store the object into the braib for furthur 
            //references 
        } 
    }
}