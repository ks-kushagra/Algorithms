A frog jumps either 1, 2 or 3 steps to go to top. In how many ways can it reach the top.

Input:
The first line of input contains an integer T denoting the number of test cases. T testcases follow. Each testcase contains one line of input N denoting the total number of steps.

Output:
For each testcase, in a new line, print the number of ways to reach the top.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 50

Example:
Input:
2
1
5
Output:
1
13
______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int steps(int n , vector <int> &t)
{
    if(n<0)
    return 0;
    
    if(t[n] !=-1)
     return t[n];
     
    if(n==0)
    return 1;
    
    return t[n]= steps(n-1,t)+steps(n-2,t)+steps(n-3,t);
}

int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<int> temp(n+1,-1);
	    cout<<steps(n,temp)<<endl;
	}
	return 0;
}
