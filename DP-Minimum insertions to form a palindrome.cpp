
/*

Minimum insertions to form a palindrome 

Given a string str, the task is to find the minimum number of characters to be inserted to convert it to palindrome.

Before we go further, let us understand with few examples:

    ab: Number of insertions required is 1 i.e. bab
    aa: Number of insertions required is 0 i.e. aa
    abcd: Number of insertions required is 3 i.e. dcbabcd
    abcda: Number of insertions required is 2 i.e. adcbcda which is same as number of insertions in the substring bcd(Why?).
    abcde: Number of insertions required is 4 i.e. edcbabcde

 
 string  abcde , edcba (longest palindromic length =1) 
 (insertion = length(a) - PalindomicLength)
 

*/
_____________________________________________________________________________________________________________________________________________________________________________________
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


int minInsertion(string a ,int n)
{
    vector < vector <int> > t(n+1 , vector <int> (n+1 , -1));
    string a1 = a;
    reverse(a.begin(),a.end());
   int t1 = lcs(a1 ,a,n,n ,t);
   
   
   return ( n - t1);
}

int main() {
	string a;
	cin>>a;
	
	cout<< minInsertion(a,a.length());
	return 0;
}
