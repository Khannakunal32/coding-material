/******************************************************************************

                              Online C++ Compiler.
              Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
#include <unordered_map>
#include <list>

using namespace std;

template <typename T>
class graph{
    
    public:
    unordered_map<T, list<T>> adj;
    
    void addEdge(T u, T v, bool directed){
        adj[u].push_back(v);
        
        if(!directed) adj[v].push_back(u);
    }
    
    void printAdj(){
        
        for(auto i: adj){
            cout<<i.first<<" -> ";
            for(auto j: i.second)
                cout<<j<<" ";
                
                cout<<endl;
        }
    }
    
};

int main()
{
    graph<int> g;
    int n, m;
    cout<<"enter number of nodes";
    cin>>n;
    cout<<"\nenter number of edges";
    cin>>m;
    
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        
        g.addEdge(u, v, 0);
    }
    
    g.printAdj();  

    return 0;
}



#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;
  
    // graph represenetation with vector
    vector<int> adjv[n+1];
    
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        
        adjv[u].push_back(v); // in all cases
        adjv[v].push_back(u); // in case of undirected graph
    }

    // to iterate over a 'u' in vector ie adjecent kon kon se hai us element ke
       for(int node=1; node<=n; node++){// to print adjecey list // node starting 1 se n tak
       cout<<node<<" -> ";
    for(auto it: adjv[node]){
        cout<<it<<" ";
    }
cout<<endl;
}  

    return 0;
}










// //  ------------shortest distace in DAG using topoSortDFS TC=O(V+E) Sc= O(V)
#include <bits/stdc++.h>

using namespace std;

class Graph{
    public:
    
    int n;
    
    Graph(int x){
        n = x;
    }
    unordered_map<int, list<pair<int,int>>> adj;
    
    void addEdge(int u, int v, int wt){
        adj[u].push_back({v, wt});
    }
};

void topoSortDFS(int node, unordered_map<int, list<pair<int,int>>> adj, 
            unordered_map<int, bool> &vis, stack<int> &s){
                
                 vis[node] = 1;
                 
                for(auto nbr: adj[node]){
                    if(!vis[nbr.first]){
                        vis[nbr.first] = 1;
                        topoSortDFS(nbr.first, adj, vis, s);
                    }
                }
                
                s.push(node);
}

int main()
{
    Graph g(5);
    g.addEdge(0,1,5);    // u, v, wt
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);
    
    // g.addEdge(0,4,5);    // u, v, wt
    // g.addEdge(0,2,3);
    // g.addEdge(4,2,2);
    // g.addEdge(4,3,6);
    // g.addEdge(2,3,7);
    // g.addEdge(2,1,4);
    // g.addEdge(2,5,2);
    // g.addEdge(3,1,-1);
    // g.addEdge(1,5,-2);
    
//     g.addEdge(0, 1, 2); //-------
// 	g.addEdge(0, 4, 1); 
// 	g.addEdge(1, 2, 3); 
// 	g.addEdge(4, 2, 2); 
// 	g.addEdge(4, 5, 4); 
// 	g.addEdge(2, 3, 6); 
// 	g.addEdge(5, 3, 1);
    
    int src = 1;
    int n = g.n;
    unordered_map<int, bool> vis;
    stack<int> s;
    
    for(int i=0; i<=n; i++){
        if(!vis[i])
    topoSortDFS(i, g.adj, vis, s);
    }
    
     vector<int> dis(n+1, INT_MAX);  // fill dist with inifity
    dis[src] = 0;
    
    cout<<"Topological Sort -> ";
    while(!s.empty()){
        int node= s.top();
        s.pop();
        cout<<node<<" ";
        if(dis[node]!= INT_MAX)
        {
        for(auto nbr: g.adj[node]){
        int wt = dis[node]+ nbr.second;
        dis[nbr.first] = min(dis[nbr.first], wt); 
            }
        }
    } 
    cout<<endl;
    
    cout<<"distance from source to ith node \n";
    int i=0;
    for(auto it: dis) cout<<i++<<"->"<<it<<" ";

    return 0;
}
