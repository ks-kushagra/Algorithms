Given an array, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum.

Input:
The first line contains an integer 'T' denoting the total number of test cases. In each test cases, the first line contains an integer 'N' denoting the size of array. 
The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.


Output:
In each seperate line print minimum absolute difference.


Constraints:
1<=T<=200
1<=N<=50
1<=A[i]<=200


Example:
Input:
2
4
1 6 5 11
4
36 7 46 40

Output : 
1
23

Explaination :
Testcase 1:
Subset1 = {1, 5, 6} ; sum of Subset1 = 12
Subset2 = {11} ;       sum of Subset2 = 11

Testcase 2:
Subset1 = {7, 46} ;   sum = 53
Subset2 = {36, 40} ; sum = 76
______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void isValid(vector <int> A , int n , int target,vector<vector <int> > &t)
{
    for(int i=0;i<=n;i++)
     t[i][0]=1;
     
    for(int i=1;i<=target;i++)
      t[0][i]=0;
      
     for(int i=1;i<=n;i++)
       for(int j=1;j<=target;j++)
       {
           if(A[i-1] > j)
             t[i][j] = t[i-1][j];
             
            else
             t[i][j] = t[i-1][j-A[i-1]]||t[i-1][j];
       }
}

int minSubsetDiff(vector <int> A , int n)
{
    int sum =0;
    for(int i=0;i<n;i++)
      sum += A[i];
      
    vector <vector <int> > temp(n+1 , vector <int> (sum+1 , -1));
    isValid(A,n,sum,temp);
    
    int ans = INT_MAX;
    for(int i=0;i<=sum/2;i++)
       if(temp[n][i]==1)
            ans = min(ans , abs(sum - 2*i));
            
    return ans;
	
	
}

int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector <int> A(n , 0);
	    for(int i=0;i<n;i++)
	    cin>>A[i];
        
        cout<<minSubsetDiff(A , n)<<endl;
	}
	return 0;
}
