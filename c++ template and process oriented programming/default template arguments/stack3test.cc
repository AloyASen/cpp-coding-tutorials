#include <iostream>
#include <deque>
#include <cstdlib>
#include "basics/stack3.hpp"
int main(){

    try{ 

        //stack of ints
    Stack<int> intStack;

    //stack of doubles which use deque s to manage the elems
    Stack<double, std::deque<double> > dblStack;

    //manipulate int stack
    intStack.push(10);
    // print the contents
    std::cout<< intStack.top() <<std::endl;
    intStack.pop();

    //manipulate double stack
    dblStack.push(42.24);
    // print the contents
    std::cout<< dblStack.top() <<std::endl;
    dblStack.pop();
    dblStack.pop();

    }catch(std::exception const& ex){
        std::cerr << "exception " <<ex.what() << std::endl;
    }
    
    return EXIT_FAILURE;
}