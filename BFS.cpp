#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

struct Edge{
    int to,cost;
    Edge(int t,int c=1):to(t),cost(c){}
};
struct Graph{
    int V;
    vector<vector<Edge>> adj;
    Graph(int n):V(n),adj(n){}
    void addEdge(int u,int v,int cost=1){adj[u].emplace_back(v,cost);}
};

void bfs(Graph &g,int start,function<void(int)> visit){
    vector<bool> visited(g.V,false);
    queue<int> q;
    q.push(start);
    visited[start]=true;
    while(!q.empty()){
        int node=q.front();q.pop();
        visit(node);
        for(auto &e:g.adj[node]){
            if(!visited[e.to]){
                visited[e.to]=true;
                q.push(e.to);
            }
        }
    }
}
