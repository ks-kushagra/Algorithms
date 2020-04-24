Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively. 
Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this 
subset is smaller than or equal to W. You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).

__________________________________________________________________________________________________________________________________________________________________________________

//using Memoizaton


#include <iostream>
#include<bits/stdc++.h>
using namespace std;


int t[100][100];

int knapsack(vector<int> weight , vector <int> profit , int n ,int W)
{
    if(t[n][W] !=-1)
    return t[n][W];
    
    if(n==0 || W==0)
    return t[n][W]=0;
    
    if(weight[n-1] <= W)
    {
        return t[n][W]= max(profit[n-1] + knapsack(weight , profit , n-1 , W-weight[n-1]) , knapsack(weight,profit , n-1 , W));
    }
    
    else
     return t[n][W] = knapsack(weight,profit , n-1 , W);
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
	
	//Maximize the profit
	memset(t,-1,sizeof(t));
	cout<<knapsack(weight,profit,n,W);
	return 0;
}

