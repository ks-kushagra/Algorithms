 You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. 
 For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:

Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.

________________________________________________________________________________________________________________________________________________________________________________________________________

#include<bits/stdc++.h>
#include <iostream>
using namespace std;


int countSubsetwithSum(vector <int> arr, int n ,int target)
{
    if(target ==0)
    return 1;
    
    if(n == 0 && target > 0)
    return 0;
    
    if(arr[n-1] <= target)
     return countSubsetwithSum(arr,n-1,target - arr[n-1]) + countSubsetwithSum(arr,n-1,target);
     
     else
     return countSubsetwithSum(arr,n-1,target);
}


int subsetDiff(vector <int> arr, int n ,int diff)
{
    int sum =0;
    
    for(int i=0;i<n;i++)
     sum += arr[i];
     
     int k = (sum + diff)/2;
     
     return countSubsetwithSum(arr,n,k);
}

int main() {
	int n;
	cin>>n;
	
	vector <int> arr(n);
	for(int i=0;i<n;i++)
	cin>>arr[i];
	
	int diff;
	cin>>diff;
	
	/*
	Now , let 2 subsets be s1 and s2
	sum(s1) + sum(s2) = sum(arr)
	sum(s1) - sum(s2) = diff
	
	sum(s1) = (sum(arr) + diff) /s2  = k(say)
	
	That means we just have to count the number of subsets with sum of its element equal k 
	countSubsetSum Problem
	*/
	
	cout<<subsetDiff(arr,n,diff);
	return 0;
}
