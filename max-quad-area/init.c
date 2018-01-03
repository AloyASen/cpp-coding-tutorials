#include <stdio.h>
#include <math.h>
double maxarea(int a, int b, int c, int d){
	//calculate the semi-perimeter	
	double s= (a+b+c+d)/2;
	return (sqrt(s-a)*(s-b)*(s-c)*(s-d));
}
int main(){
double area= maxarea(2,5,7,5);
printf("%f", area);
return 0;
}

