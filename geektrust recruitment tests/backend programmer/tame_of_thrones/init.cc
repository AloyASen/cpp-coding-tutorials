/*
this program has to be submitted into the upload section of geek trust 

maybe it is the best way to let recruiters know about talent 
and not how fast one can code 

my code is my resume 

so be it !!!


*/
#include <iostream>
#include <string>
#include <vector>
#include <cstring>


int processHash(std::string pattern){

	int hash;
	char taken[10]; // the max length of any string that is to be hashed
	strcpy(taken, pattern.c_str());

	for (int i = 0; i < 10; ++i)
	{
		std:: cout << taken[i] << " " ;
	}
	std::cout << " \n";

	//print the ascii values of the respective characters

	for (int i = 0; i < 10; ++i)
	{
		std:: cout << (int)(taken[i]) << " " ;
	}
	std::cout << " \n";
	return hash;
}

int main(int argc, char const *argv[])
{
	std :: string message ;

	//the input has to be taken 
	std :: cout << "  this is the input" <<std :: endl;

	std :: cin >> message;
	//we would use rabin karp pattern matching algorithm to check the validity of the string

	//store all the animal emblems in a vector and consume them simultaneously 
	//to create the hash

	std::vector<std:: string> emblems;

	// this hash has to comprise of the both the uppercase and the lower case 
	// alphabets of each of the animal emblems
	std::vector<int> hash ;

	emblems.push_back("Panda");
	emblems.push_back("Octopus");
	emblems.push_back("Mammoth");
	emblems.push_back("Owl");
	emblems.push_back("Dragon");

	for (std::vector<std::string>::iterator i = emblems.begin(); i != emblems.end(); ++i)
	{
		std::cout<< *i <<std::endl ;

		// this string has to return its hash

		processHash(*i);
	}



	// process the inputs
	return 0;
}



/*int main(int argc, char const *argv[])
{
	using namespace std;  

vector<string> myvector;  // a vector of stings.


// push some strings in the vector.
myvector.push_back("a");
myvector.push_back("b");
myvector.push_back("c");
myvector.push_back("d");


vector<string>::iterator it;  // declare an iterator to a vector of strings
int n = 3;  // nth element to be found.
int i = 0;  // counter.

// now start at from the beginning
// and keep iterating over the element till you find
// nth element...or reach the end of vector.
for(it = myvector.begin(); it != myvector.end(); it++,i++ )    {
    // found nth element..print and break.
    if(i == n) {
        cout<< *it << endl;  // prints d.
        break;
    }
}

// other easier ways of doing the same.
// using operator[]
cout<<myvector[n]<<endl;  // prints d.

// using the at method
cout << myvector.at(n) << endl;  // prints d.
	return 0;
}*/