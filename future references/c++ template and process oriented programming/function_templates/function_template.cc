#include "function_template.hpp"

#include <iostream>
#include <string>
int main(int argc, char const *argv[])
{
	int i = 42;
	std ::cout << ::max (7,i)<<std:: endl;
	std ::string s1= "mathematics";
	std:: string s2 = "maths";
	std ::cout << ::max (s1,s2)<<std:: endl;
	 /// ---------


	std :: cout << max(static_cast<double>(4), 4.4)<< std :: endl;
	// -------


	std :: cout <<"is similar to the previous answer "  << max<double>(4, 4.4)<< std :: endl;


	//------

	/*

	it is also possible to specify an empty template argument list . this syntax indicates that only templates may resolve the call , but the template parameter must  be deduced from the from the call arguments

	*/
	
	

	std :: cout   << max< >(4, 4)<< std :: endl;

	
	return 0;
}

/*
this :: in front of max template function is used because 
the standard library also contains max function ... to distinguish this from 
this template we stecify the global context in front of  the template



hope this explaination is enough for you to understand
*/