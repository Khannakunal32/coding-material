// -----graph adjency matrix using array
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{       
    int n, m; // n is nodes  m is edges
    cin>>n>>m;
    
  int adj[n][n]; // if nodes start from 0 else use adj[n+1][n+1] 
  
  memset(adj, 0, sizeof(adj));
  
  for(int i=0; i<m; i++){
      int u, v;
      cin>>u>>v; // value of nodes
      
      adj[u][v]=1;
      adj[v][u]=1; //if undirected graph, else remove it
      
  }
  
  // printing the nodes
  for(int node=0; node<n; node++){   // if nodes start from 0 else use node=1; node<=n
      cout<<node<<" -> ";
    for(int j=0; j<n; j++){
        cout<<adj[node][j]<<" ";
    }
    cout<<endl;
  }
  
    return 0;
}


// // -----------graph adjency list using maps

#include <bits/stdc++.h>
#include <unordered_map>
#include <list>

using namespace std;

// here we create a template so that we can make graph of any type int/ char/ bool etc..
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




// -----graph adjency list using vector array vector<int> v[]
#include<bits/stdc++.h>

using namespace std;

template<typename T, size_t x, int y>
class graph{
    
    public:
    // int n=0, m=0; // number of nodes and edge
      
    //   graph(int x, int y){
    //       n=x; m=y;
    //   }
      
  vector<int> adj[y];
   
};

int main(){
    int n, m;
    cin>>n>>m;
    graph<int, 5, m> g;
    // cout<<g.n;
    return 0;
}


// // -------graph using vector
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



// // ---------- graph adj list using class and vector and dynamic allocation concept
#include<bits/stdc++.h>

using namespace std;

template<typename t>
class graph{
    
    public:
    int n=0, m=0; // number of nodes and edge
     
    vector<int>* adj;
    
      graph(int x, int y){
          n=x; m=y;
          
          // this is a type of 2d vector creates a vector like vector<int> adj[n] dynamically
          adj= new vector<int>[n];  // using dynamic vector allocation to create vector of dynamic size
      }
      
      
      // creating graph adj list
    void addAdj(int u, int v){     
        
        adj[u].push_back(v); 
        adj[v].push_back(u); // if undirected graph else remove
    }
    
    void printAdj(){
        
        for(int node=0; node<n; node++){
            cout<<node<<" -> ";
            for(auto it: adj[node])   
                cout<<it<<" ";
                
                cout<<endl;
        }
    }
   
};

int main(){
    int n, m;
    cin>>n>>m;
    graph g(n, m);
    
    // taking nodes and making graph
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        g.addAdj(u, v);
    }
    
    g.printAdj();
    return 0;
}
