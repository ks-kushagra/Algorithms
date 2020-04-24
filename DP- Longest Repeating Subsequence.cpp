/*

Longest Repeating Subsequence

Given a string, find length of the longest repeating subseequence such that the two subsequence don’t have same string 
character at same position, i.e., any i’th character in the two subsequences shouldn’t have the same index 
in the original string.



Input: str = "abc"
Output: 0
There is no repeating subsequence

Input: str = "aab"
Output: 1
The two subssequence are 'a'(first) and 'a'(second). 
Note that 'b' cannot be considered as part of subsequence 
as it would be at same index in both.

Input: str = "aabb"
Output: 2

Input: str = "axxxy"
Output: 2

*/

_____________________________________________________________________________________________________________________________________________________________________________________________



#include<bits/stdc++.h>
using namespace std;

int lcs(string a ,string b ,int n)
{
    vector <vector <int> > t(n+1 , vector <int> (n+1 , 0));
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
         {
             if(i!=j && a[i-1] == b[j-1])
             {
                 t[i][j] = 1+t[i-1][j-1];
             }
             
             else
             {
                 t[i][j] = max(t[i-1][j] , t[i][j-1]);
             }
         }
    }
    
    
    return t[n][n];
}

int main()
{
    string a;
    cin>>a;
    
    cout<<lcs(a,a,a.length());
    
    return 0;
}
