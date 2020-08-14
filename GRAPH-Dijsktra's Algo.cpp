//Dijsktra algorithm
/*Given a graph and a source vertex in the graph, find shortest paths from 
source to all vertices in the given graph.*/

#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int findMin(vector <int> A , int source , vector <int> B)
{
    int min_index=-1,min_element = INT_MAX;
    
    for(int i=0;i<A.size();i++)
    {
        if(i != source && B[i] == 0)
           {
               if(min_element > A[i])
                  {
                      min_element = A[i];
                      min_index = i;
                  }
           }
    }
    
    return min_index;
}

void solve(vector<vector <int>> graph , int n)
{
    //source vertex = 0
    
    vector <int> status(n , 0);
    vector <int> dist(n , INT_MAX);
    
    //Initialization
    status[0]=1;
    int nodes=1;
    dist[0]=0;
    for(int i=1;i<n;i++)
       {
           if(graph[0][i] != 0)
              dist[i]=graph[0][i];
       }
       
     for(int i=0;i<n;i++)
      cout<<dist[i]<<" ";
      
      cout<<endl;
      
    while(nodes < n)
    {
        int selected = findMin(dist , 0 , status);
        status[selected]=1;
        
        if(selected == -1)
        break;
        
        nodes++;
        
        for(int i = 0;i<n;i++)
        {
            if(i != 0 && graph[selected][i] != 0)
                dist[i] = min(dist[i] , graph[selected][i] + dist[selected]);
        }
     
      for(int i=0;i<n;i++)
      cout<<dist[i]<<" ";
      cout<<endl;
    }
    
   
}

int main() {
	int n;
	cin>>n;
	vector<vector <int> > graph(n , vector <int> (n , 0));
	
	for(int i=0;i<n;i++)
	 for(int j=0;j<n;j++)
	   cin>>graph[i][j];
	   
    solve(graph,n);	  
   
	return 0;
}
