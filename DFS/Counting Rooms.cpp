#include <bits/stdc++.h>
using namespace std;
void dfs(int i,int j,vector<vector<char>>&grid,vector<vector<bool>>&visited){
    if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||visited[i][j]||grid[i][j]=='#') return;
    visited[i][j]=true;
    dfs(i+1,j,grid,visited);
     dfs(i-1,j,grid,visited);
     dfs(i,j+1,grid,visited);
      dfs(i,j-1,grid,visited);

}

 int main(){
 int r,c;
 cout<<"row,col:";
 cin>>r>>c;
 vector<vector<char>>grid(r,vector<char>(c));
  vector<vector<bool>>visited(r,vector<bool>(c,false));
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
        cin>>grid[i][j];
    }
  }
    int roomcount=0;
 for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
        if(!visited[i][j]&&grid[i][j]=='.'){
            roomcount++;
            dfs(i,j,grid,visited);
        }
    }
  }
 cout<<"roomcount:"<<  roomcount;


 }
