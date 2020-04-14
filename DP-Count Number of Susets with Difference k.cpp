Given an array of integers and a difference value k.
Count the number of subsets pairs whose difference of Sum of their elements equal to k

Like
arr: {1,1,2,3}
k: 1

Output: 3

Explanation:
a) pair1 = s1 = {1,3} and s2 = {1,2} ==> 1+3 - 1+2 =1
b) pair2 = s1 ={1,3} and s2 = {1,2}
c) pair3 = s1 = {1,1,2} and s2 ={3}

_____________________________________________________________________________________________________________________________________________________________________________________________



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
