#include <iostream>
#include <vector>
#include <algorithm>
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

vector<int> beamSearchWithHistory(Graph &g,int start,function<bool(int)> isGoal,function<int(int)> heuristic,int beamWidth){
    vector<int> currentLevel={start},history;
    while(!currentLevel.empty()){
        for(int node:currentLevel){
            history.push_back(node);
            if(isGoal(node)) return history;
        }
        vector<int> nextLevel;
        for(int node:currentLevel){
            for(auto &e:g.adj[node]) nextLevel.push_back(e.to);
        }
        sort(nextLevel.begin(),nextLevel.end(),[&](int a,int b){
            return heuristic(a)<heuristic(b);
        });
        if((int)nextLevel.size()>beamWidth) nextLevel.resize(beamWidth);
        currentLevel=nextLevel;
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
    int goal=5;
    auto isGoal=[&](int node){return node==goal;};
    auto heuristic=[&](int node){return abs(goal-node);};
    int beamWidth=2;
    auto history=beamSearchWithHistory(g,0,isGoal,heuristic,beamWidth);
    for(int n:history)cout<<n<<" ";
    cout<<"\n";
    return 0;
}
