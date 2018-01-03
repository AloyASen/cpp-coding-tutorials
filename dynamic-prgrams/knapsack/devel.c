/*
Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).

this is the problem of not breaking the items in the knapsack into parts


in fractional knapsack this type of breaking will be allowed


*/



// ========-------------------------===============

/*
 A Naive recursive implementation of 0-1 Knapsack problem 




#include <stdio.h>
//this utility returns the maximum of two numbers 

int max (int a, int b ){ return (a >b) ?a :b ;}


int knapsack(int w, int wt[], int val[], int n){
	// base case

	if (n ==0 || w ==0)
	{
		return 0;
	}
	if (wt[n-1 ] > w)
	{
		return knapsack(w, wt, val, n-1);

	}else{
		return max(val[n - 1 ] + knapsack(w-wt[n-1], wt,val,n-1 ), 
			knapsack(w, wt, val, n-1)
			);
	}
}

int main(int argc, char const *argv[])
{
	int val[] = {60, 100, 120};
	int wt[] = { 10,20,30};
	int w= 50;
	int n= sizeof(val)/ sizeof(val[0]);
	printf("%d\n", knapsack(w, wt, val, n ) );
	return 0;
}




It should be noted that the above function computes the same subproblems again and again. See the following recursion tree, K(1, 1) is being evaluated twice


recursion tree

In the following recursion tree, K() refers to knapSack().  The two 
parameters indicated in the following recursion tree are n and W.  
The recursion tree is for following sample inputs.
wt[] = {1, 1, 1}, W = 2, val[] = {10, 20, 30}

                       K(3, 2)         ---------> K(n, W)
                   /            \ 
                 /                \               
            K(2,2)                  K(2,1)
          /       \                  /    \ 
        /           \              /        \
       K(1,2)      K(1,1)        K(1,1)     K(1,0)
       /  \         /   \          /   \
     /      \     /       \      /       \
K(0,2)  K(0,1)  K(0,1)  K(0,0)  K(0,1)   K(0,0)
Recursion tree for Knapsack capacity 2 units and 3 items of 1 unit weight.



Time complexity of this naive recursive solution is exponential (2^n)


*/


//=============-----------------------================

/*the dynamic programming approach to floydi algo */

#include <stdio.h>
//this utility returns the maximum of two numbers 

int max (int a, int b ){ return (a >b) ?a :b ;}
int knapsack(int w, int wt[], int val[], int n){
	int i,W ;
	int k[n+1][w+1];
	for(i =0; i <= n; i++ ){
		for(W = 0;W <w;W++){
			if (i == 0 || w==0)
			{
				k[i][W] =0;
			}else if (wt[i-1] <= W)
			{
				k[i][W] = max(val[i-1] + k[i-1][W-wt[i-1]],k[i-1][W]);

			}else{
				k[i][W]= k[i-1][W];
			}
		}
	}
	return k[n][w];
}
int main(int argc, char const *argv[])
{
	int val[] = {60, 100, 120};
	int wt[] = { 10,20,30};
	int w= 50;
	int n= sizeof(val)/ sizeof(val[0]);
	printf("%d\n", knapsack(w, wt, val, n ) );
	return 0;
}
