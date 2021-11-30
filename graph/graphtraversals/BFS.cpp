#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;

template <typename T>
class Graph{
   map<T,list<T>>l;

   public:
    void addEdge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void bfs(T src){
        // vector<bool>visited(graph->size(),false)
        map<T,bool> visited;
        queue<T>q;

        q.push(src);
        visited[src]=true;
        while(!q.empty()){
            T node=q.front();
            cout<<node<<" ";
            q.pop();

        //    for(auto i=graph[v].begin();i!=graph[v].end();i++)
            for(int nbr:l[node]){
                if(!visited[nbr])
                 q.push(nbr);
                 visited[nbr]=true;
            }
        }
    }
};
int main(){
    Graph<int> g,g1;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);

    g1.addEdge(0,1);
    g1.addEdge(0,2);
    g1.addEdge(1,2);
    g1.addEdge(2,0);
    g1.addEdge(2,3);
    g1.addEdge(3,3);

    




    // g.bfs(0);
    g1.bfs(2);
    return 0;
}
