
Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

 

Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.

Example 2:

Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.

 
 -_________________________________________________________________________________________________________________________________________________________________________
 
 
int countSquares(vector<vector<int>>& matrix) {
        
      int ans = 0;
      int n = matrix.size();
      int m = matrix[0].size();   
        
     vector <vector <int> > t(n+1 , vector <int> (m+1 , 0));

        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                if(matrix[i-1][j-1])
                t[i][j] = 1 + min(t[i-1][j] , min(t[i][j-1],t[i-1][j-1])); //minimum of diagnol , previous row and previous column   +  1
                
                ans += t[i][j];
            }
        }
    
    
      return ans;
        
    }
