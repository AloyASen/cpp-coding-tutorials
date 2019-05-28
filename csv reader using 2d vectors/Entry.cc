/*
this is the entry code line of reading a comma
seperated spredsheet
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

int main(){

  ifstream ip("mnist_train.csv");
  vector< vector<string> > data;

  if(!ip.is_open()) std::cout << "ERROR: File Open" << '\n';

    string line;
	string cell;

  while (std::getline(ip, line)) {
			//Add dimnesion to data
			data.push_back(std::vector<std::string>());

			//Read all the cells in the line
			std::stringstream lineStream(line);
			while (std::getline(lineStream, cell, ',')) {

				//Store the content of every cells
				data.back().push_back(cell);
				cout<< cell << " ";
			}
			cout <<endl;
			cout<<"reading new line"<<endl ;
	}

  ip.close();

	// //read the 2d vector
	//     for (auto i = data.begin(); i != data.end(); ++i){
	// 			// for (auto in = i.begin(); i != i.end(); ++i){
	// 			// 	cout << *i << " ";
	// 			// }
				
	// 		} 
        
}
