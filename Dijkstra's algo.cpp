#include "bits/stdc++.h"
using namespace std;

int main(){

  int n,m;
  cin>>n>>m;

  vector<int> dist(n+1,INT_MAX);
  vector<vector<pair<int,int>>> graph(n+1);
  
  for(int i=0; i<m; i++){
    int u,v,w;
    cin>>u>>v>>w;

    graph[u].push_back({v,w});
    graph[v].push_back({u,w});
  }

  int source=0;

  dist[source]=0;
  set<pair<int,int>> s;

  s.insert({0,source});

  while(!s.empty()){
    auto x=*(s.begin());
    s.erase(x);
    for(auto it: graph[x.second]){
      if(dist[it.first] > dist[x.second] + it.second){
       // s.erase({dist[it.first],it.first});
        dist[it.first]=dist[x.second] + it.second;
        s.insert({dist[it.first],it.first});
      }
    }
  }

  for(int i=1; i<=n; i++){
    if(dist[i] <INT_MAX){
      cout<<dist[i]<<" ";
    }
    else 
       cout<<-1<<" ";
  }

  return 0;
}
