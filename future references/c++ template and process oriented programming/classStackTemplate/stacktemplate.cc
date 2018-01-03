#include <vector>
#include <stdexcept>
#include <string>
#include <iostream>
#include <cstdio>
template <typename t>
class Stack
{
private:
	std::vector<t> elems; //elements
public:
	Stack();
	~Stack();

	void push(t const&);  //push elements
	void pop();
	t top() const ;
	bool empty() const {
		return elems.empty();
	}
	
};
template <typename t>
void Stack<t>::push(t const& elem){
	elems.push_back(elem);

}
template <typename t>
void Stack<t>::pop(){
	if (elems.empty()) 
	{
		throw std::out_of_range("Stack<>::pop()): empty stack " );
	}else{
		elems.pop_back();
		
	}
}
template <typename t>
t Stack<t>::top() const {
	if (elems.empty())
	{
		/* code */
		throw std::out_of_range("Stack<>::pop()): empty stack " );
	}else{
		return elems.back();
		//return the copy of the last element
	}
}
int main(int argc, char const *argv[])
{
	Stack<std::string> lifo; //make an empty vector of strings
	std::string ip; //input variable
	int i=0;
	do{
		std::cout << "input into the stack"<<std::endl;

		std::cin >> ip;
		lifo.push(ip);
		 //the data is successfully inserted into the vector
	}while(i== 4);
	// reinitialize the value of the counter flag
	 i=0;
		std::cout << "output of all the elements from the stack "<<std::endl;
	do{

		
		std::cout << lifo.top() << " " ;
		lifo.pop(); //delete the last element
		 //the data is successfully inserted into the vector
	}while(i== 4);
		

	return 0;
}