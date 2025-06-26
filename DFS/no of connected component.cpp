#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<vector<int>>&adj,vector<bool>&visited)
{
    visited[node]=true;
    cout<<node<<" ";
    for(int neighbor:adj[node])
    {
        if(!visited[neighbor])
        {
            dfs(neighbor,adj,visited);
        }
    }
}

int connectedComponent(int node,vector<vector<int>>&adj)
{
    vector<bool>visited(node,false);
    int c=0;
    for(int i=0; i<node; i++)
    {
        if(!visited[i])
        {
            dfs(i,adj,visited);
            c++;
        }
    }


    return c;
}


int main()
{

    int node, edge;
    cout<<"enter node, edge: ";
    cin>>node>>edge;
    vector<vector<int>>adj(node);

    cout<<"input: ";
        for(int i=0; i<edge; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    int res= connectedComponent(node,adj);
    cout<<"res: "<<res;


}
