#include <stdio.h>
#include <string.h>

int max(int a, int b);

int lcs(char *x, char *y, int m, int n){
	if( m== 0 ||n==0)
		return 0;
	if(x[m-1] == y[n-1])
		return 1 + lcs(x,y ,m-1, n-1);
	else
		return max(lcs(x,y,m,n-1), lcs(x,y,m-1,n));
}

int max(int a, int b){
	return (a >b)?a:b;
}
int main(){
	char x[]= "aggtab";
	char y[]= "gxtxayb";
	int m= strlen(x);
	int n= strlen(y);
	printf("length of Lcs is %dn\n", lcs(x,y,m,n) );
	return 0;
}

//this is the top down recursive solution 
 //to the old lcs prolem solved by a sen
 // another program in the same directory 
// is the dynamic program