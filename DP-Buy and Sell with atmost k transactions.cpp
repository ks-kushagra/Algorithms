

_________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

class Solution {
public:
    
    int solve(vector <int> A , int n, int k , vector<vector <int>> &t)
    {
        if(n == 0 || k == 0)
            return 0;
        
        if(t[n][k] !=-1)
            return t[n][k];
        
        int max_profit =0;
        
        for(int i=0;i<n-1;i++)
        {
            int temp = t[i][k-1];
            if(temp == -1)
                temp = solve(A,i,k-1,t);
            
            max_profit = max(max_profit , A[n-1]-A[i] + temp);
        }
        
        int temp = t[n-1][k];
        if(temp == -1)
            temp = solve(A,n-1,k,t);
        return max(temp , max_profit);
    }
    
    int iterativesolve(vector <int> A , int n ,int k , vector<vector <int> > &t)
    {
       for(int i=1;i<=n;i++)
       {
           for(int j=1;j<=k;j++)
           {
               int max_profit=0;
               
               for(int m =0;m<i-1;m++)
               {
                   max_profit = max(max_profit , A[i-1] - A[m] + t[m][j-1]);
               }
               
               t[i][j] = max(max_profit , t[i-1][j]);
           }
       }
        
        return t[n][k];
    }
    
    int maxProfit(vector<int>& A) {
        int n = A.size();
        vector <vector <int> > t(n+1 , vector <int> (3,0));
        return iterativesolve(A , n,2,t);
    }
};
