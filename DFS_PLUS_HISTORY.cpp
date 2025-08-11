#include <iostream>
#include <vector>
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

void dfsWithHistoryUtil(Graph &g,int node,vector<bool> &visited,vector<int> &history,function<void(int)> visit){
    visited[node]=true;
    history.push_back(node);
    visit(node);
    for(auto &e:g.adj[node]){
        if(!visited[e.to])dfsWithHistoryUtil(g,e.to,visited,history,visit);
    }
}

vector<int> dfsWithHistory(Graph &g,int start,function<void(int)> visit){
    vector<bool> visited(g.V,false);
    vector<int> history;
    dfsWithHistoryUtil(g,start,visited,history,visit);
    return history;
}
