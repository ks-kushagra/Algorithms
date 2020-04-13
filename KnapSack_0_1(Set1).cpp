Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. 
In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively.
Also given an integer W which represents knapsack capacity, 
find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W.
You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).



____________________________________________________________________________________________________________________________________________________________________


//0-1 Knapsack Problem
//using recursion


#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int> weight , vector <int> profit ,int n ,int W)
{
    if(n==0 || W==0)
    return 0;
    
    if(weight[n-1] <= W)
     return max(profit[n-1] + knapsack(weight,profit,n-1,W-weight[n-1]) , knapsack(weight,profit , n-1,W));

    else
     return knapsack(weight , profit, n-1 , W);
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
	cout<<knapsack(weight,profit,n,W);
	return 0;
}
