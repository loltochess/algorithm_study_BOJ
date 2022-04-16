#include <bits/stdc++.h>

using namespace std;

int n,m;
int maze[201][201]={0};

int dx[]={1,0,0,-1};
int dy[]={0,1,-1,0};


int BFS(int i, int j){
    queue <pair<int,int>> q;
    q.push({i,j});
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        int min=1000001;
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=m){
                continue;
            }
            if(maze[nx][ny]==0){
                continue;
            }
            if(maze[nx][ny]==1){
                maze[nx][ny]=maze[x][y]+1;
                if(maze[nx][ny]==maze[x][y]){
                    break;//돌아가면 루프끝냄
                }
                q.push({nx,ny});
            }
        }
    }
    return maze[n-1][m-1];
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%1d",&maze[i][j]);
        }
    }
    cout<<BFS(0,0)<<endl; //목적지를 (n-1, m-1)이라고 생각하면..
    
}
