Rahul and Ankit are the only two waiters in Royal Restaurant. Today, the restaurant received N orders. The amount of tips may differ when handled by different waiters, if Rahul takes the ith order, he would be tipped Ai rupees and if Ankit takes this order, the tip would be Bi rupees.
In order to maximize the total tip value they decided to distribute the order among themselves. One order will be handled by one person only. Also, due to time constraints Rahul cannot take more than X orders and Ankit cannot take more than Y orders. It is guaranteed that X + Y is greater than or equal to N, which means that all the orders can be handled by either Rahul or Ankit. Find out the maximum possible amount of total tip money after processing all the orders.


Input:

•    The first line contains one integer, number of test cases.
•    The second line contains three integers N, X, Y.
•    The third line contains N integers. The ith integer represents Ai.
•    The fourth line contains N integers. The ith integer represents Bi.

 

Output:
Print a single integer representing the maximum tip money they would receive.
 

Constraints:
1 ≤ N ≤ 105
1 ≤ X, Y ≤ N; X + Y ≥ N
1 ≤ Ai, Bi ≤ 104

 

Example:

Input:

2
5 3 3
1 2 3 4 5
5 4 3 2 1
8 4 4
1 4 3 2 7 5 9 6 
1 2 3 6 5 4 9 8

 

Output:

21
43

____________________________________________________________________________________________________________________________________________________________________________________________-


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxtip(vector<int> r,vector <int> a,int n,int x,int y,vector <vector <int> > &t)
{
    if(t[x][y] !=-1)
    return t[x][y];
    
    if(x==0 && y ==0)
      return t[x][y]=0;
      
    if(x ==0 && y!=0)
     {
         int sum =0;
         for(int i=n-1;i>=0;i--)
           sum +=a[i];
           
           return t[x][y]=sum;
     }
     
    if(x !=0 && y==0)
     {
         int sum =0;
         for(int i=n-1;i>=0;i--)
           sum +=r[i];
           
           return t[x][y]=sum;
     }
     
     
     return t[x][y]=max(r[n-1]+maxtip(r,a,n-1,x-1,y,t) , a[n-1]+maxtip(r,a,n-1,x,y-1,t));
}

int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,x,y;
	    cin>>n>>x>>y;
	    vector <int> a(n);
	    vector <int> r(n);
	    
	    for(int i=0;i<n;i++)
	      cin>>r[i];
	      
	    for(int i=0;i<n;i++)
	     cin>>a[i];
	     
	     vector <vector <int> > t(x+1 , vector<int> (y+1 , -1));
	     int ans = maxtip(r,a,n,x,y,t);
	     
	     cout<<ans<<endl;
	     
	}
	return 0;
}
