#include <bits/stdc++.h>
using namespace std;
void dfs(int start, vector<vector<int>>&adj, vector<bool>&visited){
    visited[start]=true;
    cout<<<start <<" ";
    for(int neighbor:adj[start]){
        if(!visited[neighbor]){
            dfs(neighbor,adj,visited);
        }
    }
}
int main(){
int node,edge;
cout<<"enter nodes and edges:";
cin>>node>>edge;
vector<vector<int>>adj(node);
vector<bool>visited(node,false);
cout<<"input:";
for(int i=0;i<edge;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int start;
cout<<"start";
cin>>start;
cout<<"dfs trav: ";
dfs(start,adj,visited);



}
