Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins. The order of coins doesn’t matter. 
For example, for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4. For N = 10 and S = {2, 5, 3, 6}, 
there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. So the output should be 5.

Input:
The first line contains an integer 'T' denoting the total number of test cases. In each test cases, the first line contains an integer
'M' denoting the size of array. The second line contains M space-separated integers A1, A2, ..., AN denoting the elements of the array. The third line contains an integer 'N' 
denoting the cents.

Output:
Print number of possible ways to make change for N cents.

Constraints:
1 ≤ T ≤ 50
1 ≤ N ≤ 300
1 ≤ A[i] ≤ 300

Example:
Input:
2
3
1 2 3
4
4
2 5 3 6
10

Output:
4
5
___________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int solve(vector <int> A , int target , int n , vector<vector <int> > &t)
{
    if(target == 0)
     return 1;
     
    if(n == 0 || target < 0)
      return 0;
      
      if(t[n][target] != -1 )
      return t[n][target];
      
     if(A[n-1] > target)
      return t[n][target] = solve(A , target , n-1,t);
      
      else
       return t[n][target] =solve(A , target - A[n-1] , n,t) + solve(A , target , n-1,t);
}
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,target;
	    cin>>n;
	    vector <int> v(n);
	    for(int i=0;i<n;i++)
	    cin>>v[i];
	    cin>>target;
	    vector<vector <int> > temp(n+1 , vector <int> (target +1 , -1));
	    cout<<solve(v , target , n , temp)<<endl;
	}
	return 0;
}
