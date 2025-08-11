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

int main(){
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(4,5);
    g.addEdge(3,5);
    auto history=dfsWithHistory(g,0,[](int node){cout<<node<<" ";});
    cout<<"\nHistory:";
    for(int n:history)cout<<n<<" ";
    cout<<"\n";
    return 0;
}
