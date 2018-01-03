#include <iostream>
#include <cmath>
double find_log(int tetrad){
  return log(tetrad);
}
void finally(){
	std::cout << " Genuine xit sequence initiated";
}
int main(int argc, char const *argv[])
{
	bool loop;
	double tetrad_result=40.0;
	do{
		std::cin.clear();
		tetrad_result = find_log(tetrad_result);
		std::cout << tetrad_result;
		std::cout << " do you want to continue? ";
		std::cin>> loop;
	}while(loop == true);
	finally();
	//return control to os 
	return 0;
}