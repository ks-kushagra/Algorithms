You are given an array A of size N. The array contains integers and is of even length. The elements of the array represent N coin of values V1, V2, ....Vn. You play against an opponent in an alternating way.

In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the value of the coin.

You need to determine the maximum possible amouint of money you can win if you go first.

Input:
The first line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains two lines of input. The first line contains N denoting the size of the array. The second line contains N elements of the array.

Output:
For each testcase, in a new line, print the maximum amout.

Constraints:
1 <= T <= 100
2 <= N <= 100
1 <= Ai <= 106

Examples:
Input:
2
4
5 3 7 10
4
8 15 3 7
Output:
15
22

Explanation:
Testcase1: The user collects maximum value as 15(10 + 5)
Testcase2: The user collects maximum value as 22(7 + 15)

__________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int solve(vector <int> A , int i ,int j , vector <vector <int> > &t)
{
    if(i > j)
     return 0;
     
    if(t[i][j] !=-1)
     return t[i][j];
     
    if(j-i+1 == 2)
      return max(A[i],A[j]);
      
     
    // if A[i] is Selected
    int a = A[i] + min( solve(A , i+2 ,j,t) , solve(A , i+1 , j-1,t) );
    
    // if A[j] is Selected
    int b = A[j]  + min( solve(A , i , j-2,t) , solve(A , i+1 , j-1,t));
    
    return t[i][j] = max(a , b);
}
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector <int> A(n);
	    for(int i=0;i<n;i++)
	    cin>>A[i];
	    vector<vector <int> > temp(n , vector <int> ( n ,-1));
	    cout<<solve(A , 0 , n-1,temp)<<endl;
	}
	return 0;
}
