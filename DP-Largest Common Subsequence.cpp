Given two strings s1 and s2, the task is to find the length of longest common subsequence present in both of them.

Examples:

    Input: s1 = “ABCDGH”, s2 = “AEDFHR”
    Output: 3
    LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.


    Input: s1 = “striver”, s2 = “raj”
    Output: 1 
________________________________________________________________________________________________________________________________________________________________________________________


//Longest Common Subsequence

#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int lcs(string x , string y ,int n ,int m)
{
    
    vector <vector <int> > t(n+1 , vector <int> (m+1 , 0));
    
    for(int i=1;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            if(x[i-1] == y[j-1])
              t[i][j]=1+t[i-1][j-1];
              
             else
               t[i][j]=max(t[i-1][j],t[i][j-1]);
        }
    }
    
    return t[n][m];
    
}

int main() {
	string x,y;
	cin>>x>>y;
	cout<< lcs(x,y , x.length(),y.length());
	return 0;
}
