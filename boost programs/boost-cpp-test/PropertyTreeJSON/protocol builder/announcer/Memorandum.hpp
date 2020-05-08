/***

this is the final product that is expected from  the mashine that is in phase beta of 

development

**/
// all the components of the totol protocol suite
#pragma once
#include "objects/Includes.hpp"
#include <iostream>
namespace protocol{
    class Memorandum{
    public:
    // this is to be the final product that is a deliverable 
        protocol::internal::Message *message;
        void specification(){
            std::cout << "the message" <<std::endl;
        }
    };
}
