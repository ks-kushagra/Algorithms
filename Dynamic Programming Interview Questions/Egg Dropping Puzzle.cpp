Suppose you have N eggs and you want to determine from which floor in a K-floor building you can drop an egg such that it doesn't break. You have to determine the minimum number of
attempts you need in order find the critical floor in the worst case while using the best strategy.There are few rules given below. 

An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If the egg doesn't break at a certain floor, it will not break at any floor below.
If the eggs breaks at a certain floor, it will break at any floor above.
For more description on this problem see wiki page

Input:
The first line of input is  T denoting the number of testcases.Then each of the T lines contains two positive integer N and K where 'N' is the number of eggs and 'K' is number of floor in building.

Output:
For each test case, print a single line containing one integer the minimum number of attempt you need in order find the critical floor.

Constraints:
1<=T<=30
1<=N<=10
1<=K<=50

Example:
Input:
2
2 10
3 5

Output:
4
3
_________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int solve(int e , int f , vector<vector <int> > &t)
{
    if(e == 1)
     return f;
     
    if(f<=1)
     return f;
     
     if(t[e][f] != -1)
     return t[e][f];
     
     int ans = INT_MAX;
    for(int k = 1;k<=f;k++)
    {
        int temp  = max(solve(e-1,k-1,t) , solve(e , f-k,t))+1;
        ans = min(ans, temp);
    }
    
    return t[e][f] = ans;
}

int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n , k;
	    cin>>n>>k;
	    vector<vector <int> > temp(n+1 , vector <int> (k+1 , -1));
	    cout<<solve(n , k , temp)<<endl;
	    
	}
	return 0;
}
