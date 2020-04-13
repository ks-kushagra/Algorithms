Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights 
associated with n items respectively. Also given an integer W which represents knapsack capacity, find out the 
maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. 
You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).

________________________________________________________________________________________________________________________________________________________________________________



// without recursion  or using iterative version

#include <iostream>
#include<bits/stdc++.h>

using namespace std;


int t[100][100]; // declare a static array


int knapsack(vector <int> weight , vector<int> profit , int n , int W)
{
    //If there is no item
    for(int i=0;i<=W;i++)
        t[0][i]=0;
        
    //If the size of Sack is Zero
    for(int j =0;j<=n;j++)
     t[j][0]=0;
     
     for(int i=1;i<=n;i++)
     {
         for(int j=1;j<=W;j++)
         {
             if(weight[i-1] > W)
             {
                 t[i][j] = t[i-1][j];
             }
             
             else
             t[i][j] = max(t[i-1][j-weight[i-1]] + profit[i-1] , t[i-1][j]);
         }
     }
     
     return t[n][W];
}

int main() {
	int n;
	cin>>n;
	vector <int> weight(n);
	vector <int> profit(n);
	for(int i=0;i<n;i++)
	{
	    cin>>profit[i];
	}
	
	for(int i=0;i<n;i++)
	{
	    cin>>weight[i];
	}
	
	int W;
	cin>>W; // weight of Knapsack
	
	
	memset(t,-1,sizeof(t));
	cout<<knapsack(weight,profit , n , W);
	return 0;
}


