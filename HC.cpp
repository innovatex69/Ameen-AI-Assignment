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

int hillClimb(Graph &g,int start,function<int(int)> heuristic){
    int current=start;
    while(true){
        int nextNode=-1;
        int bestH=heuristic(current);
        for(auto &e:g.adj[current]){
            int hVal=heuristic(e.to);
            if(hVal<bestH){
                bestH=hVal;
                nextNode=e.to;
            }
        }
        if(nextNode==-1)break;
        current=nextNode;
    }
    return current;
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
    auto heuristic=[&](int node){return abs(goal-node);};
    int result=hillClimb(g,0,heuristic);
    cout<<result<<"\n";
    return 0;
}

