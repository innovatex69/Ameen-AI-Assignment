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

struct State{
    int node,cost;
    vector<int> path;
    bool operator>(const State &other)const{return cost>other.cost;}
};

vector<int> branchAndBoundWithHistory(Graph &g,int start,function<bool(int)> oracle){
    priority_queue<State,vector<State>,greater<>> pq;
    pq.push({start,0,{start}});
    vector<bool> visited(g.V,false);
    vector<int> history;
    while(!pq.empty()){
        State cur=pq.top();pq.pop();
        history.push_back(cur.node);
        if(oracle(cur.node)) return history;
        if(visited[cur.node]) continue;
        visited[cur.node]=true;
        for(auto &e:g.adj[cur.node]){
            if(!visited[e.to]){
                auto newPath=cur.path;
                newPath.push_back(e.to);
                pq.push({e.to,cur.cost+e.cost,newPath});
            }
        }
    }
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
    auto oracle=[](int node){return node==5;};
    auto history=branchAndBoundWithHistory(g,0,oracle);
    for(int n:history)cout<<n<<" ";
    cout<<"\n";
    return 0;
}
