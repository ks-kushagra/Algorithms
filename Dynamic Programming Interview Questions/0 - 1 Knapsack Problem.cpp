You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of four lines.
The first line consists of N the number of items.
The second line consists of W, the maximum capacity of the knapsack.
In the next line are N space separated positive integers denoting the values of the N items,
and in the fourth line are N space separated positive integers denoting the weights of the corresponding items.

Output:
For each testcase, in a new line, print the maximum possible value you can get with the given conditions that you can obtain for each test case in a new line.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 1000
1 ≤ W ≤ 1000
1 ≤ wt[i] ≤ 1000
1 ≤ v[i] ≤ 1000

Example:
Input:
2
3
4
1 2 3
4 5 1
3
3
1 2 3
4 5 6
Output:
3
0
Explanation:
Test Case 1: With W = 4, you can either choose the 0th item or the 2nd item. Thus, the maximum value you can generate is the max of val[0] and val[2], which is equal to 3.
Test Case 2: With W = 3, there is no item you can choose from the given list as all the items have weight greater than W. Thus, the maximum value you can generate is 0.

___________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int solve(int n , int w , vector <int> profit , vector <int> weight , vector < vector <int> > &t)
{
    if(n == 0 || w == 0)
     return 0;
    
    if(t[n][w] !=-1)
     return t[n][w];
     
    if(weight[n-1] <= w)
        return t[n][w]=max( profit[n-1] + solve(n-1,w-weight[n-1] , profit,weight, t) , solve(n-1 , w , profit , weight , t));
        
    return t[n][w]=solve(n-1 , w , profit , weight , t);
}

int solve1(int n , int w , vector <int> profit , vector <int> weight , vector < vector <int> > &t)
{

    for(int i=0;i<=n;i++)
      t[i][0]=0;
      
     for(int i=0;i<=w;i++)
      t[0][i]=0;
      
      for(int i=1;i<=n;i++)
        for(int j=1;j<=w;j++)
        {
            if(weight[i-1] <= j)
              t[i][j] = max(profit[i-1] + t[i-1][j - weight[i-1]] , t[i-1][j]);
              
            else
            t[i][j] = t[i-1][j];
        }
        
        return t[n][w];
 }


int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,w;
	    cin>>n>>w;
	    vector <int> profit(n);
	    vector <int> weight(n);
	    
	    for(int i=0;i<n;i++)
	    cin>>profit[i];
	    
	    for(int i=0;i<n;i++)
	    cin>>weight[i];
	    
	    vector <vector <int> > temp(n+1 , vector <int> (w+1 , -1));
	    
	   cout<<solve1(n , w , profit , weight , temp)<<endl;
	}
	return 0;
}
