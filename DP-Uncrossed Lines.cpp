We write the integers of A and B (in the order they are given) on two separate horizontal lines.

Now, we may draw connecting lines: a straight line connecting two numbers A[i] and B[j] such that:

    A[i] == B[j];
    The line we draw does not intersect any other connecting (non-horizontal) line.

Note that a connecting lines cannot intersect even at the endpoints: each number can only belong to one connecting line.

Return the maximum number of connecting lines we can draw in this way.

 

Example 1:

Input: A = [1,4,2], B = [1,2,4]
Output: 2
Explanation: We can draw 2 uncrossed lines as in the diagram.
We cannot draw 3 uncrossed lines, because the line from A[1]=4 to B[2]=4 will intersect the line from A[2]=2 to B[1]=2.

Example 2:

Input: A = [2,5,1,2,5], B = [10,5,2,1,5,2]
Output: 3

Example 3:

Input: A = [1,3,7,1,7,5], B = [1,9,2,5,1]
Output: 2

 

Note:

    1 <= A.length <= 500
    1 <= B.length <= 500
    1 <= A[i], B[i] <= 2000

________________________________________________________________________________________________________________________________________________________


int solve(vector <int> A , vector<int> B , int n , int m,vector <vector <int> > &t)
    {
        
        if( t[n][m] != -1)
            return t[n][m];
        
        
        if(n ==0 || m == 0)
            return t[n][m]=0;
        
        if(A[n-1] == B[m-1])
            return t[n][m]= 1 + solve(A , B , n-1 , m-1,t);
        
        else
        {
            return t[n][m]= max( solve(A , B , n-1 , m,t) , solve( A , B , n , m-1,t));
        }
    }
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        vector <vector <int> > t(A.size()+1 , vector <int> ( B.size()+1 , -1));
        
        return solve( A , B , A.size(), B.size(),t);
    }
