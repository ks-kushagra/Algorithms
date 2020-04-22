Given two strings s1 and s2, the task is to print the longest common subsequence present in both of them.

Examples:

    Input: s1 = “ABCDGH”, s2 = “AEDFHR”
    Output: "ADH".
    LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” .
    
    _________________________________________________________________________________________________________________________________________________________________________
    
    
    //print longest common subsequence

#include <iostream>
#include<bits/stdc++.h>

using namespace std;

void lcs(string x , string y ,int n ,int m,vector <vector <int> > &t)
{
    
    
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
    
    
}

int main() {
	string x,y;
	cin>>x>>y;
	int n = x.length();
	int m = y.length();
	vector <vector <int> > t(n+1 , vector <int> (m+1 , 0));
    lcs(x,y,n,m,t);
    
    int i =n;
    int j =m;
    string s ="";
    while( i>0 && j>0)
    {
        if(x[i-1] == y[j-1])
        {
            s = x[i-1]+s;
            i--;
            j--;
        }
        
        else{
            if(t[i-1][j] > t[i][j-1])
            {
                i--;
            }
            
            else
            j--;
        }
    }
    
    cout<<s;
	return 0;
}
