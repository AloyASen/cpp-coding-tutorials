// basic file operations
#include <iostream>
#include <fstream>
using namespace std;
struct Person{
char name[50];
int age;
double weight;

};
int main () {
  Person someone = {"frodo" , 20, 8.0};
  string filename= "test.bin";
  ofstream myfile;
  myfile.open (filename.c_str(),  ios::binary); 
  if(myfile.is_open()){
  myfile.write(reinterpret_cast<char *> (&someone), sizeof(Person));
  myfile.close();
  }else{
  cout << "could not create the new file";
}
  return 0;
}
