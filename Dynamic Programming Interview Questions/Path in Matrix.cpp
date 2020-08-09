Given a N X N  matrix Matrix[N][N] of positive integers.  There are only three possible moves from a cell Matrix[r][c].

1. Matrix[r+1][c]

2. Matrix[r+1][c-1]

3. Matrix[r+1][c+1]

Starting from any column in row 0, return the largest sum of any of the paths up to row N-1.

Input:
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N denoting the order of matrix. Next line contains N*N integers denoting the elements of the matrix in row-major form.

Output:
Output the largest sum of any of the paths starting from any cell of row 0 to any cell of row N-1. Print the output of each test case in a new line.

Constraints:
1<=T<=20
2<=N<=20
1<=Matrix[i][j]<=1000 (for all 1<=i<=N && 1<=j<=N)

Example:

Input:
1
2
348 391 618 193

Output:
1009

Explanation: In the sample test case, the path leading to maximum possible sum is 391->618.  (391 + 618 = 1009)
_________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int solve(vector<vector <int>> A , int i ,int j,int n,vector <vector <int> > &t)
{
    
    if(t[i][j] !=-1)
     return t[i][j];
     
    if(i == n-1 && j == n-1)
     return A[i][j];
     
     int a=0 , b=0 , c=0;
     
     if(i+1<n)
     {
         a = solve(A , i+1 ,j,n,t);
         
         if(j-1>=0)
          b = solve(A ,i+1 ,j-1,n,t);
          
         if(j+1 < n)
          c = solve(A , i+1 , j+1 , n,t);
     }
     
     return t[i][j] = max(a , max(b ,c ))+A[i][j];
}
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<vector <int> > A ( n ,vector <int> (n,0));
	    for(int i=0;i<n;i++)
	      for(int j=0;j<n;j++)
	        cin>>A[i][j];
	   vector <vector <int> > temp( n , vector <int> (n , -1));
	   int ans =0;
       for(int i=0;i<n;i++)
         {
             ans = max(ans , solve(A , 0,i,n,temp));
         }
         
        cout<<ans<<endl;
	}
	return 0;
}
