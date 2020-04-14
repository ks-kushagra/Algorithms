Given an array arr[] of length N and an integer X, the task is to find the number of subsets with sum equal to X.

Examples:

    Input: arr[] = {1, 2, 3, 3}, X = 6
    Output: 3
    
    Explanation:
    All the possible subsets are {1, 2, 3},
    {1, 2, 3} and {3, 3}
    
    __________________________________________________________________________________________________________________________________________________________________________
    
    
    
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int count_subset(vector <int> arr, int n , int target)
{
    if(target == 0)
    return 1;
    
    if(n==0 && target>0)
    return 0;
    
    if(arr[n-1] <= target)
    {
        return count_subset(arr,n-1,target-arr[n-1]) + count_subset(arr,n-1,target);
    }
    
    else
    {
        return count_subset(arr,n-1,target);
    }
}

int main() {
	int n;
	cin>>n;
	
	vector <int> arr(n);
	
	for(int i=0;i<n;i++)
	cin>>arr[i];
	
	int target;
	cin>>target;
	
	cout<<"Count is "<<count_subset(arr,n,target);
	return 0;
}
