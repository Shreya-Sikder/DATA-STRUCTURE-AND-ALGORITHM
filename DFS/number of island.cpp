#include<bits/stdc++.h>
using namespace std;

void dfs(int i,int j,vector<vector<char>>&grid){
    if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]=='0')
        return ;
    grid[i][j]='0';
    dfs(i+1,j,grid);
     dfs(i-1,j,grid);
      dfs(i,j+1,grid);
       dfs(i,j-1,grid);

}

int numberisland( vector<vector<char>>&grid){
int c=0;
for(int i=0;i<grid.size();i++){
    for(int j=0;j<grid[0].size();j++){
        if(grid[i][j]=='1'){
            c++;
            dfs(i,j,grid);
        }
    }
}


return c;
}
int main(){
    int r,c;
    cout<<"number of row and column:" ;
    cin>>r>>c;
    vector<vector<char>>grid(r,vector<char>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>grid[i][j];
        }
    }
    int res=numberisland(grid);
    cout<<"number of island is :"<<res;
    return 0;
}
