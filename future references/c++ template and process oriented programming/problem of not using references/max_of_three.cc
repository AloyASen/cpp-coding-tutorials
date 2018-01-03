#include <iostream>
#include <cstring>
#include <string>
 

//max of two values of any type 
 //pass by refernce 
template <typename t>
inline t const& max(t const& a, t const& b){
	return a< b ? b : a;

}
//max of 2 c strings (call by value)
inline char const* max(char const *a , char const *b){
	return std :: strcmp(a,b)<0 ?b:a;
}

//maximum of three values of any type

template <typename t>
inline t const& max (t const& a, t const& b,t const& c){
	return max(max(a,b),c);
	//error if max (a,b) uses call by value

}

int main(int argc, char const *argv[])
{
	std::cout << ::max(7,42,68)<< std::endl;;
		//this is ok
	//std::cout << ::max("friedric", "anica", "lucas") << std ::endl;
		//this is not going to compile



	return 0;
}