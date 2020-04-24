

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



void merge(vector <int> &parent , int u ,int v)
{
    for(int i=0;i<parent.size();i++)
     {
         if(parent[i] == parent[v])
           parent[i] = parent[u];
     }
     
     
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
