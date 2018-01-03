#include <gsl/gsl_complex.h>
#include <gsl/gsl_complex_math.h>
#include<iostream>
gsl_complex gsl_calculate(gsl_complex * a){
 //store the temporary addendum 
gsl_complex b = gsl_complex_rect(4.0, 3.2);
std::cout<< "After adding 2 numbers that are complex" <<std::endl; 
return gsl_complex_add(*a, b);
}
int main(){
gsl_complex complex= gsl_complex_rect(2.0,3.9);
std::cout<< "this program has successfully generated complex numbers";
gsl_complex c = gsl_calculate(&complex);
//printing the output
std::cout << "real  : " << c.dat[0] << " , "<< "complex : " << c.dat[1] << std::endl;
return 0;
}
