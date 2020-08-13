#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int find(int i , vector <int> parent)
{
    if(i == parent[i])
     return i;
     
     return find(parent[i], parent);
}

void merge(int u , int v , vector <int> &parent)
{
    int u_rep = find(u , parent);
    int v_rep = find(v , parent);
    
    parent[v_rep] = u_rep;
}

int solve(vector<vector<int> > graph , vector<pair <int, pair<int,int> > > e , vector<int> &parent)
{
    int n = graph.size();
    sort(e.begin(),e.end());
    int ans =0;
    int nodes=0;
    for(int i=0;i<e.size();i++)
    {
        int weight = e[i].first;
        int u = e[i].second.first;
        int v = e[i].second.second;
        int u_rep = find(u,parent);
        int v_rep = find(v , parent);
        
        if(u_rep != v_rep)
        {
            merge(u,v,parent);
            nodes++;
            ans += weight;
        }
        
        if(nodes+1 == n)
        break;
    }
    
    return ans;
}

int main() {
	int n;
	cin>>n;
	vector<vector <int> >graph(n , vector <int> (n , 0));
	vector <pair<int , pair<int,int> > > e;
	for(int i=0;i<n;i++)
	 for(int j=0;j<n;j++)
	    {
	        cin>>graph[i][j];
	        if(graph[i][j] !=0)
	        {
	            e.push_back({graph[i][j] , {i,j}});
	        }
	    }
	    
	    vector <int> parent(n);
	    for(int i=0;i<n;i++)
	    parent[i]=i;
	    
	    cout<<solve(graph , e , parent);
      	     
    
	return 0;
}



_______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

//kruskal's algorithm

#include<bits/stdc++.h>
#include <iostream>
using namespace std;

void addEdge(vector < vector <int > > &v , pair<int, pair <int,int> > p)
{
    int u = p.second.first;
    int v1 = p.second.second;
    int weight = p.first;
    
    v[u][v1] = weight;
    v[v1][u] = weight;
}


void merge(int u , int v , vector <int> &parent)
{
    int up =find(u,parent);
    int vp=find(v,parent);
    parent[vp] = parent[up];
}



int find(vector <int> parent , int a)
{
    while( a != parent[a])
      a = parent[a];
      
    return a;
}



void kruskal(vector <vector <int> > graph , int vertices)
{
    int min_sum=0;
    
    vector <vector <int > > MinST(vertices , vector <int> (vertices , 0)); // Initially MST is fi
    
    vector <pair<int , pair<int, int>> > weight; // this will store edges and weigths they are containing
    vector <int> parent; // it will check whether two vertices belongs to same set or not
    
    for(int i=0;i<vertices;i++)
      parent.push_back(i);
      
      
    
    for(int i=0;i<vertices;i++)
     {
         for(int j=i+1;j<vertices;j++)
          {
              if(graph[i][j])
                 weight.push_back(make_pair(graph[i][j] , make_pair( i, j)));
          }
     }
     
     sort(weight.begin(),weight.end()); //sort according to their weight
     
     for(int i=0;i<weight.size();i++)
       cout<<weight[i].second.first<<" "<<weight[i].second.second<<" "<< weight[i].first <<endl;
       
    int t=0;
    for(int e=0;e<weight.size();e++)
    {
        auto e1 = weight[e];
       int a = find(parent , e1.second.first);
       int b = find(parent , e1.second.second);
       
       if(a != b)
       {
           merge(parent , e1.second.first , e1.second.second);
           addEdge(MinST , e1);
           min_sum +=e1.first;
           t++;
           
           if(t==vertices -1) // if total vertices in MinST is n-1 break the loop
             break;
       }
    }
    
    
    
    for(int i=0;i<vertices;i++)
    {
        for(int j=0;j<vertices;j++)
         {
             cout<<MinST[i][j]<<" ";
         }
         
         cout<<endl;
    }
    
    cout<<"Min cost"<<min_sum;
} 



int main() {
    int vertices;
    cin>>vertices;
    
	vector <vector <int> > graph(vertices , vector <int> (vertices , 0));
	
	for(int i=0;i<vertices;i++)
	 {
	     for(int j=0;j<vertices;j++)
	       {
	           cin>>graph[i][j];
	       }
	 }
	 
	kruskal(graph,vertices);
	
	return 0;
}
