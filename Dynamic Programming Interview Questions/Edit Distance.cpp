Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of edits (operations) required to convert ‘str1′ into ‘str2′.

Insert
Remove
Replace
All of the above operations are of cost=1.
Both the strings are of lowercase.

Input:
The First line of the input contains an integer T denoting the number of test cases. Then T test cases follow. Each tese case consists of two lines. 
The first line of each test case consists of two space separated integers P and Q denoting the length of the strings str1 and str2 respectively.
The second line of each test case coantains two space separated strings str1 and str2 in order.

Output:
Corresponding to each test case, pirnt in a new line, the minimum number of operations required.

Constraints:
1 <= T <= 50
1 <= P <= 100
1 <= Q <= 100

Example:
Input:
1
4 5
geek gesek

Output:
1

Explanation:
Testcase 1: One operation is required to make 2 strings same i.e. removing 's' from str2.
__________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

-#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int editDistance(string a, string b , int n , int m, vector<vector <int> > &t )
{
    if(t[n][m] !=-1)
    return t[n][m];
    
    if(a == b)
     return 0;
     
     if(n==0)
     return m;
     
     if(m==0)
     return n;
     
     if(a[n-1]==b[m-1])
     return t[n][m] = editDistance(a,b,n-1,m-1,t);
     
     return t[n][m] = 1+min(editDistance(a,b,n,m-1,t) , min(editDistance(a,b,n-1,m,t) , editDistance(a,b,n-1,m-1,t)));
}
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>>n>>m;
	    string a,b;
	    cin>>a>>b;
	    vector<vector <int> > temp(n+1 , vector <int> (m+1 , -1));
	    cout<<editDistance(a,b,n,m,temp)<<endl;
	}
	return 0;
}
