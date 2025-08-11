#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <limits>
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

struct AStarState{
    int node,gCost,fCost;
    vector<int> path;
    bool operator>(const AStarState &other)const{return fCost>other.fCost;}
};

vector<int> aStar(Graph &g,int start,int goal,function<int(int)> heuristic){
    priority_queue<AStarState,vector<AStarState>,greater<>> pq;
    pq.push({start,0,heuristic(start),{start}});
    vector<int> bestCost(g.V,numeric_limits<int>::max());
    bestCost[start]=0;
    while(!pq.empty()){
        AStarState cur=pq.top();pq.pop();
        if(cur.node==goal) return cur.path;
        if(cur.gCost>bestCost[cur.node]) continue;
        for(auto &e:g.adj[cur.node]){
            int newG=cur.gCost+e.cost;
            if(newG<bestCost[e.to]){
                bestCost[e.to]=newG;
                auto newPath=cur.path;
                newPath.push_back(e.to);
                pq.push({e.to,newG,newG+heuristic(e.to),newPath});
            }
        }
    }
    return {};
}
