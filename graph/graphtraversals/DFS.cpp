#include<iostream>
#include<map>
#include<list>
using namespace std;
template <typename T>
class Graph{
    map<T,list<T>>l;
    public:
      void addEdge(int x, int y){
          l[x].push_back(y);
          l[y].push_back(x);
      }
      void dfs_helper(T src, map<T,bool>& visited){
              cout<<src<<" ";
             visited[src]=true;
              for(T nbr:l[src]){
             if(!visited[nbr]){
                 dfs_helper(nbr,visited);
             }
              }
      }
      void dfs(T src){
          map<T,bool>visited;
        //   mark all the nodes as not visited
        for(auto p:l){
            T node=p.first;
            visited[node]=false;

        }
        dfs_helper(src,visited);
      }
      void dfs_iterativr(vector<T> graph[],int start){
          vector<bool> visited(graph->size(),false);
          stack<int>st;
          st.push(start);
          visited[start]=true;
          while(!st.empty()){
              int v=st.top();
              cout<<v<<" ";
              st.pop();
              for(auto i=graph[v].begin();i!=graph[v].end();i++){
                  if(!visited[*i]){
                      st.push(*i);
                      visited[*i]=true;
                  }
              }
          }
      }

};
int main(){
    Graph<int>g;
    g.addEdge(0,1);
     g.addEdge(1,2);
      g.addEdge(2,3);
       g.addEdge(3,4); 
       g.addEdge(4,5);
      g.addEdge(3,0);

      g.dfs(0);

      return 0;

}