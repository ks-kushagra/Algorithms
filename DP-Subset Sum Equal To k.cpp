Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.
Example:

Input:  set[] = {3, 34, 4, 12, 5, 2}, sum = 9
Output:  True  //There is a subset (4, 5) with sum 9.

____________________________________________________________________________________________________________________________________________________________



//Subset Sum Eqaul to target Sum


#include<bits/stdc++.h>
#include <iostream>

using namespace std;


int t[100][100];

int subsetSum(vector <int> arr,int n ,int sum)
{
    for(int i=0;i<=n;i++)
     {
         t[i][0]=1;           //If sum =0 then there's always a subset whose sum is 0--->Empty Set
     }
     
     for(int i=1;i<=sum;i++)
     t[0][i] =0;              //If no element in set then there will be no subset whose sum > 0 
     
     for(int i=1;i<=n;i++)
      for(int j=1;j<=sum;j++)
      {
          if(arr[i-1] > j)
          {
              t[i][j]= t[i-1][j];
          }
          
          else
           t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
      }
      
      return t[n][sum];
}

int main() {
	int n;
	cin>>n;
	vector <int> arr(n);
	for(int i=0;i<n;i++)
	 cin>>arr[i];
	 
	int k;
	cin>>k; //target Sum
	
	
	 memset(t,-1,sizeof(t));
	 cout<<subsetSum(arr,n,k);
	return 0;
}
