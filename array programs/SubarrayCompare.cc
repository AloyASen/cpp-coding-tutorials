/*
in this program the source goal is to find the min of length of the subarray that is the cover for all the elements in the competing array
*/

#include <iostream>

int lenfinder(int lena , int lenb , int *a , int * b){


	int i, j ,start=0, end =0, minLength= lena;
	for (i = 0 ; i =lena;i++){
		// find the length of the sub array after finding the first element
		if (a[i] == b[0]){
			start = i;
			for (j =i ; ;j++){
				if (a[j]= b[lenb -1])
				{
					/*
					get the end index 
					*/
					end =j;

					break;

				}
			}
			if (minLength > ( end -start))
			{
				/* update min length of the sub array */
				minLength =( end -start);

			}
		}
	}

}

int main(int argc, char const *argv[])
{
	int a[]= { 5, 6, 5, 2, 7, 5,6, 7, 5,5,7};
	int b[] ={2,5,9};
	int lena= sizeof(a)/sizeof(a[0]); //the length of the array

	int lenb= sizeof(b)/sizeof(b[0]); //the length of the array

	
		int result = lenfinder(lena, lenb , a,b);
		std :: cout << result << " -> is the find-smallest-subarray-contains-elements-order";

	return 0;
}

/*

this programming approach is 
said to be greedy ::

the first element of the required subarray is searched for in the observation list 
when found the library of data sets is searched for the end element
and in this way the minlength sub array is calculated

this has been a problem from geeks for geeks

the link :  http://www.geeksforgeeks.org/find-smallest-subarray-contains-elements-order/
*/