#include <iostream>
#include <vector>
#include <stack>
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

bool britishMuseumSearch(Graph &g,int start,function<bool(int)> isGoal,vector<int> &path){
    vector<bool> visited(g.V,false);
    stack<vector<int>> stk;
    stk.push({start});
    while(!stk.empty()){
        auto curr_path=stk.top();stk.pop();
        int node=curr_path.back();
        if(isGoal(node)){path=curr_path;return true;}
        if(visited[node])continue;
        visited[node]=true;
        for(auto &e:g.adj[node]){
            if(!visited[e.to]){
                auto new_path=curr_path;
                new_path.push_back(e.to);
                stk.push(new_path);
            }
        }
    }
    return false;
}
