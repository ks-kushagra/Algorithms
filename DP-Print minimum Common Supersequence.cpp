Given two strings str1 and str2, find the shortest string that has both str1 and str2 as subsequences.

Examples :

Input:   str1 = "geek",  str2 = "eke"
Output: "geeke"

Input:   str1 = "AGGTAB",  str2 = "GXTXAYB"
Output:  "AGXGTXAYB"

_______________________________________________________________________________________________________________________________________________________________________


//print minimum common Supersequence

#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int lcs(string x , string y ,int n ,int m,vector <vector <int> > &t)
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
    
    return t[n][m];
    
}

int main() {
	string x,y;
	cin>>x>>y;
	int n = x.length();
	int m = y.length();
	vector <vector <int> > t(n+1 , vector <int> (m+1 , 0));
   int Lcs =  lcs(x,y,n,m,t);
   // cout<< (n+m - Lcs);
    
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
                s = x[i-1]+s;
                i--;
            }
            
            else
            {
                s=y[j-1]+s;
                j--;
            }
        }
    }
    
    while(i >0)
    {
        s = x[i-1]+s;
        i--;
    }
    
    while(j>0)
    {
        s = y[j-1]+s;
        j--;
    }
    
    cout<<s<<endl;
    
    
	return 0;
}
