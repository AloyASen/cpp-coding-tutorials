/*
@dated 05 01 2018 
@author aloy

@matter  basic probability calculator

p(E(a))= n(a)/ n(S);

where probability of an event is the probability of the no of occurances of the data in the set datum

*/
#ifndef zero
#define zero 0
#endif
#include <iostream>
namespace basic {
    template <typename T> // t can be integer or float or double but string or bytes are not useful 
    class probability{
        private:
            T universe;
            T event;
        public:
            void private_setuniverse();
            T private_getuniverse();
            void set_event();
            T get_event();
            double get_probalbility();
    };
}

//the function declarations are to follow

template <typename T>
void basic::probability<T>::private_setuniverse(){

    //first check if the universre is empty
    if(private_getuniverse()== (T)zero){
            std::cout<< "this is the universe where the calculations will operate" <<std::endl;

        std::cin>> universe ;
        std::cout<< "this is the event that will cause the calculation of the probability " <<std::endl;
        std::cin>> event ;
    }else{
        std::cout << "the value is  already set "<<std::endl;

    }
    


}

template <typename T>
T basic::probability<T>::private_getuniverse(){
    return universe;
}


template <typename T>
void basic::probability<T>::set_event(){
    
    //first check if the universre is empty
    if(get_event()== (T)zero){
        std::cout<< "this is the event that will cause the calculation of the probability " <<std::endl;    
        std::cin>> event ;
    }else{
        std::cout << "the value is  already set "<<std::endl;

    }
}
template <typename T>
T basic::probability<T>::get_event(){
    return event;
}

template <typename T>
double basic::probability<T>::get_probalbility(){
    return event /universe; 
}
int main(){
    basic::probability<int> probabilities;
    probabilities.private_setuniverse();
    std::cout<< probabilities.get_probalbility() << std::endl;

}