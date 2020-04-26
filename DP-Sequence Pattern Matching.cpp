//Sequence Pattern Matching

/*
You are given a String a and a string b and you need to find out whether that string a 
is present in string b or not.

like 
       string a:abd
       string b:ajhbjd
       
       output:true or 1
*/

___________________________________________________________________________________________________________________________________________
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int lcs(string a , string b , int m ,int n , vector <vector <int > > &t)
{
    if(t[m][n] !=-1)
    return t[m][n];
    
    if(m == 0 || n==0)
     return t[m][n] =0;
     
     if(a[m-1] == b[n-1])
       return t[m][n] = 1+lcs(a,b,m-1,n-1,t);
       
      else
       return t[m][n] = max(lcs(a , b ,m-1 ,n,t) , lcs(a ,b , m ,n-1,t));
}


int seqPattern(string a , string b ,int m ,int n)
{
    vector < vector <int> > t(m+1 , vector <int> (n+1 , -1));
   int t1 = lcs(a ,b,m,n ,t);
   
   if(t1 == m)
   return 1;
   
   return 0;
}

int main() {
	string a;
	string b;
	cin>>a>>b;
	
	cout<< seqPattern(a,b,a.length() , b.length());
	return 0;
}
