#include<iostream>
#include<list>
#include<cstring>
#include<unordered_map>
using namespace std;
class Graph{
    unordered_map<string,list<pair<string,int>>>l;
    public:
    void addEdge(string x,string y,bool bidir,int wt){
        l[x].push_back(make_pair(y,wt));
        if(bidir){
            l[y].push_back(make_pair(x,wt));
        }
    }
    void printAdjlist(){
        for(auto p:l){
            string city=p.first;
            list<pair<string,int>> nbrs=p.second;

            for(auto nbr:nbrs){
                string dest=nbr.first;
                int dist=nbr.second;

                      cout<<dest<<" "<<dist<<",";
                
            }
            cout<<endl;
        }
    }
};
int main(){
    Graph g;
    g.addEdge("A","B",true,20);
    g.addEdge("B","D",true,40);

    g.addEdge("A","C",true,10);
    g.addEdge("A","D",true,40);
    g.addEdge("A","D",true,50);

    return 0;
}