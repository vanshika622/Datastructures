#include<iostream>
#include<list>
using namespace std;
class Graph{
    public:
    int v;
    list<int> *l;
    Graph(int V){
        this->v=V;
        // array of list
        l=new list<int>[V];
    }
    void addEdge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);

    }
    void printAdj(){
        for(int i=0;i<v;i++){
            cout<<"Vertex "<<i<<"->";
            for(int nbr:l[i]){
                cout<<nbr<<",";
            }
            cout<<endl;
        }
    }
};
int main(){
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(2,3);
    g.addEdge(1,2);
    g.printAdj();

}