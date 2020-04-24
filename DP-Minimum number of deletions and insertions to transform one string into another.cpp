Given two strings ‘str1’ and ‘str2’ of size m and n respectively. The task is to remove/delete and insert minimum number of characters 
from/in str1 so as to transform it into str2. It could be possible that the same character needs to be removed/deleted from one point 
of str1 and inserted to some another point.

Examples:

Input : str1 = "heap", str2 = "pea" 
Output : Minimum Deletion = 2 and
         Minimum Insertion = 1
p and h deleted from heap
Then, p is inserted at the beginning
One thing to note, though p was required yet
it was removed/deleted first from its position and
then it is inserted to some other position.
Thus, p contributes one to the deletion_count
and one to the insertion_count.

Input : str1 = "geeksforgeeks", str2 = "geeks"
Output : Minimum Deletion = 8
         Minimum Insertion = 0       

__________________________________________________________________________________________________________________________________________________________________________

//Minimum Number of Insertion and Deletion to convert String a to String b
/*
String a = heap
String b = pea

Output = 2:Deletion ( ea )
         1:Insertion ( p )
         
         
Here, first we find LCS of both
substract it from a.length() will gives num. of Deletion

No of insertion = b.length() - lcs()
*/

#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int lcs(string a , string b ,int n ,int m)
{
    vector <vector <int> > t(n+1 , vector <int> (m+1 ,0));
    
    for(int i=1;i<=n;i++)
     {
         for(int j=1;j<=m;j++)
         {
             if(a[i-1] == b[j-1])
             {
                 t[i][j] = 1 + t[i-1][j-1];
             }
             
             else
             {
                 t[i][j] = max(t[i-1][j],t[i][j-1]);
             }
         }
     }
     
     return t[n][m];
}
int main() {
	string a, b;
	cin>>a>>b;
	int n = a.length();
	int m = b.length();
	
	int t = lcs(a,b,n,m);
	
	cout<<"Deletion : "<<(n-t)<<endl;
	cout<<"Insertion :"<<(m-t);
	
	return 0;
}
