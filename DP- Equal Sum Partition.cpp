Partition problem is to determine whether a given set can be partitioned into two subsets such that the sum of elements in both subsets is same.

Examples:

arr[] = {1, 5, 11, 5}
Output: true 
The array can be partitioned as {1, 5, 5} and {11}

arr[] = {1, 5, 3}
Output: false 
The array cannot be partitioned into equal sum sets.


__________________________________________________________________________________________________________________________________________________________________________________________

//Equal Partioion sum


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

int EqualPartionSum(vector <int> arr,int n)
{
    int sum=0;
    sum = accumulate(arr.begin(),arr.end(),0);
    
    if(sum %2 !=0)
    return 0;
    
    return subsetSum(arr,n,sum/2);
}

int main() {
	int n;
	cin>>n;
	vector <int> arr(n);
	for(int i=0;i<n;i++)
	 cin>>arr[i];
   
	 memset(t,-1,sizeof(t));
   
	 cout<<EqualPartionSum(arr,n);
	return 0;
}
