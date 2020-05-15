Write an efficient program to find the sum of contiguous subarray within a one-dimensional array of numbers which has the largest sum. 

____________________________________________________________________________________________________________________________________________


int kadane(vector <int> A)
    {
         int n = A.size();
         int max_sum=INT_MIN;
         int cur_sum=0;
         for(int i=0;i<n;i++)
         {
             cur_sum += A[i];
             max_sum = max(max_sum , cur_sum);
             
             if(cur_sum < 0)
                 cur_sum =0;
         }
        
        return max_sum;  
    }
