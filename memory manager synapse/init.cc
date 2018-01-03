#include <iostream>
#include <string>
/*

this memory manager is according to the proxy design pattern
the objects are to follow visitor pattern
*/
namespace AAS{
class Learn 	// proxy interface
{
public:
	Learn();
	~Learn();
	virtual int store()= 0; // pure virtual function
	
};
class Study : public Learn
{
public:
	Study();
	~Study();

	//inherited method store 
	int store (){
		// make a max heap of hashed keys of the internet 
		
	}
	
};
}
int main(int argc, char const *argv[])
{
	//create a memory instance 
	
	return 0;
}