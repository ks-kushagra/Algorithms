Given a graph, the task is to check if it contains a negative weight cycle or not.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains 2 lines the first line 
contains two space separated integers v and e denoting the no of vertices and no of edges respectively. Then in the next line are 3*e space separated values x,y,z 
denoting an edge from x to y with a weight of z.

Output:
For each test case in a new line print 0 if there is no negative weight cycle else print 1.

Constraints:
1 <= T <= 50
1 <= v <= 100
1 <= e <= 50

Example:
Input:
2
5 8
0 1 -1 0 2 4 1 2 3 1 3 2 1 4 2 3 2 5 3 1 1 4 3 -3
3 3
0 1 -5 1 2 -6 2 0 -9
Output:
0
1

_________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________-

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int solve(vector<vector <int> > edge , int n)
{
    vector <int> dist(n , INT_MAX);
    dist[0]=0;
    int flag=0;
    
    for(int iteration =1;iteration <=n-1 ;iteration++)
    {
        flag=0;
        for(int i=0;i<edge.size();i++)
        {
            int u = edge[i][0],v=edge[i][1],cost=edge[i][2];
            if(dist[v] > dist[u] + cost)
                dist[v] = dist[u] + cost , flag =1;
        }
        
        if(flag == 0)
         break;
    }
    
    for(int i=0;i<edge.size();i++)
        {
            int u = edge[i][0],v=edge[i][1],cost=edge[i][2];
            if(dist[v] > dist[u] + cost)
              return 1;
        }
        
        
return 0;
}

int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,e;
	    cin>>n>>e;
	    vector < vector <int> > edge(e , vector <int> (3,0));
	    for(int i=0;i<e;i++)
	        cin>>edge[i][0]>>edge[i][1]>>edge[i][2];
	        
	    
	   cout<<solve(edge , n)<<endl;
	}
	return 0;
}
