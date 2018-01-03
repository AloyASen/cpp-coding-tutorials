/*
	problem :: print all permutations of a given string
	video :: https://www.youtube.com/watch?v=AfxHGNRtFac
	instructor:: geekforgeeks
	author :: Aloy Sen
	dated :: 2/10/2017
*/
// this is a backitracking approach to the proble

// time Complexity O(n*n!)
// C program to print all permutations with duplicates allowed
#include <stdio.h>
#include <string.h>
 
/* Function to swap values at two pointers */
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
// ======---------core logic goes here------=======


/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */

void permute(char *a,int l, int r){
	int i;
	if (l==r)
	{
		printf("%s\n", a);
	}else{
		for (int i = l; i <=r; i++)
		{
			swap((a+l), (a+i));
			permute(a,l+1, r);
			swap((a+l),(a+i)); // backtrack
		}
	}
}
// ======---------core logic goes here------=======

/* Driver program to test above functions */
int main()
{
    char str[] = "ABC";
    int n = strlen(str);
    permute(str, 0, n-1);
    return 0;
}