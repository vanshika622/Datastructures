#include<iostream>
#include<stack>
#include<vector>
#include<queue>
using namespace std;
void addedge( vector<vector<int>> adjmatrix ,int u, int v){
    adjmatrix[u][v]=1;
    
}
vector<int> topologicalsort(vector<vector<int>>vect,  queue<int>res){
    vector<int>indegree;
    vector<int>ans;
    for(int i=0;i<vect.size();i++){
        indegree[i]==0;
        for(int j=0;j<vect.size();j++){
            if(vect[i][j]==1)
                 indegree[i]++;
        }
    }
       for(int i=0;i<indegree.size();i++){
           if(indegree[i]==0)
               res.push(indegree[i]);
       }
  while(!res.empty()){
      int v=res.front();
      res.pop();
      ans.push_back(v);
      for(auto i=vect[v].begin();i<vect[v].end();i++){
          indegree[*i]--;
          if(indegree[*i]==0)
             res.push(*i);
      }




      
  }
  return ans;

}
int main(){
    vector<vector<int>> adjmatrix;
   addedge(adjmatrix,0,2);
   addedge(adjmatrix,0,4);
   addedge(adjmatrix,2,3);
   addedge(adjmatrix,2,4);
   addedge(adjmatrix,4,3);
   addedge(adjmatrix,4,5);

   for(int i=0;i<adjmatrix.size();i++){
       for(int j=0;j<adjmatrix.size();j++){
           cout<<adjmatrix[i][j]<<" ";
       }
   }
   queue<int>ans;
   vector<int> answer=topologicalsort(adjmatrix,ans);
   for(int i: answer){
       cout<<i<<" ";
   }
   cout<<endl;
    
}