//  given a binary grid of n X m dimensions, a rat is standing at 0,0 cell and want to go to n-1,n-1
// where the movements allowed are right and down and  0 means free cell and 1 means block cell 
// q1:- tell whether rat can reach or not 
// q2:- print the path taken
// q3:- print all possible paths 

#include<bits/stdc++.h>
using namespace std;

vector<int> path;
void bfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis,int n,int m){
    if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==1 || vis[i][j]==1){
        return;
    }
    if(i==n-1 && j==m-1){
        path.push_back(i*m+j);
        for(auto it:path){
            cout<<it<<" ";
        }
        cout<<endl;
        path.pop_back();
        return;
    }
    vis[i][j]=1;
    path.push_back(i*m+j);
    bfs(i+1,j,grid,vis,n,m);
    bfs(i,j+1,grid,vis,n,m);
    path.pop_back();
    vis[i][j]=0;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<int>> vis(n,vector<int>(m,0));
    bfs(0,0,grid,vis,n,m);
    for(auto it:path){
        cout<<it<<" ";
    }
}