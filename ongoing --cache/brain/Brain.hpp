/*

this file is the interface between brain and the compiler
which will be extended in several reasons for the betterment of the userspace 

*/
#pragma once
#include "Includes.hpp"
#include <memory>

namespace Brain{
    class Memory{
    public:
        Memory(){

        }
        virtual ~Memory() = default ; // the default destructor 
        virtual int panic() const = 0 ;
    protected:
       static  const auto base = std::make_unique<treeNode>  ;
       //this is the only test case available that is not working in the class 
    };
}