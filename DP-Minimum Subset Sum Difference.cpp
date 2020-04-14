Given a set of integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum.

If there is a set S with n elements, then if we assume Subset1 has m elements, Subset2 must have n-m elements and the value of
abs(sum(Subset1) – sum(Subset2)) should be minimum.

Example:


Input:  arr[] = {1, 6, 11, 5} 
Output: 1
Explanation:
Subset1 = {1, 5, 6}, sum of Subset1 = 12 
Subset2 = {11}, sum of Subset2 = 11        

______________________________________________________________________________________________________________________________________________________________________________________________________________



//Minimum Subset Sum Difference

#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int SubsetSum(vector<int> arr , int sum,int n)
{
    if(sum ==0)
    return 1;
    
    if(n==0 && sum >0)
    return 0;
    
    if(arr[n-1] <= sum)
    return SubsetSum(arr,sum - arr[n-1],n-1) || SubsetSum(arr, sum , n-1);
    
    else
    return SubsetSum(arr , sum , n-1);
}

void create(vector <int> &t,vector <int> arr)
{
    int range = t.size()-1;
    int n = arr.size();
    for(int i=1;i<=range;i++)
    {
        t[i]= SubsetSum(arr,i,n);
    }
}

int Min_Diff_Subset(vector <int> arr, int n)
{
    /*
    Let  sum of elements of two subsets be s1 and s2
    
    Now we have to minimize  -->>>>   abs(s1 - s2)
    
    let sum(Arr) = range
    
    minimize ------>  range - 2s1
    
    where s1 belongs to (0 to range/2)
    
    valid value of s1 is derived from sumSubset
    */
    
    int range=0;
    
    for(int i=0;i<n;i++)
     range +=arr[i];
     
     vector<int> t(range+1,0);
     t[0]=1;
     create(t,arr);
     
     int mn=INT_MAX;
     
     for(int i=0;i<=range/2;i++)
     {
         if(t[i])
         mn = min(mn , range - 2*i);
     }
     
     return mn;
}

int main() {
	int n;
	cin>>n;
	
	vector <int> arr(n);
	
	for(int i=0;i<n;i++)
	  cin>>arr[i];
	  
	  cout << Min_Diff_Subset(arr,n);
	return 0;
}
