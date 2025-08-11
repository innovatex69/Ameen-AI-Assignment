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

vector<int> branchAndBoundWithHeuristics(Graph &g,int start,function<bool(int)> oracle,function<int(int)> heuristic){
    priority_queue<AStarState,vector<AStarState>,greater<>> pq;
    pq.push({start,0,heuristic(start),{start}});
    vector<int> bestCost(g.V,numeric_limits<int>::max());
    bestCost[start]=0;
    while(!pq.empty()){
        AStarState cur=pq.top();pq.pop();
        if(oracle(cur.node)) return cur.path;
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

int main(){
    Graph g(6);
    g.addEdge(0,1,2);
    g.addEdge(0,2,4);
    g.addEdge(1,3,7);
    g.addEdge(2,4,3);
    g.addEdge(4,5,1);
    g.addEdge(3,5,1);
    int goal=5;
    auto oracle=[&](int node){return node==goal;};
    auto heuristic=[&](int node){return abs(goal-node);};
    auto path=branchAndBoundWithHeuristics(g,0,oracle,heuristic);
    for(int n:path)cout<<n<<" ";
    cout<<"\n";
    return 0;
}

