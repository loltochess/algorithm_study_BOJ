#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
int land[201][201]={};
int visit[201][201]={}; //바이러스는 한 번 만 증식가능함!(어차피 막혔으니깐)

void bfs(int i, int j,int x, int t){
    if(i<0 || i>=n || j<0 || j>=n){
        return;
    }
    if(visit[i][j]==t){
        if(land[i][j]==0){
            land[i][j]=x;
        }
        return;
    }
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    for(int k=0;k<4;k++){
        int tempx=i+dx[k];
        int tempy=j+dy[k];
        if(tempx>=0 && tempx<n && tempy>=0 && tempy<n){
            if(land[tempx][tempy]==0){
                visit[tempx][tempy]=t;
                bfs(tempx,tempy,x,t);
            }
        }
    }
}

int main(){
    int k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>land[i][j];
        }
    }
    int S,X,Y;
    cin>>S>>X>>Y;
    int x=1;
    int t=1;
    while(t<=S){
        while(x<=k){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(land[i][j]==x){
                        if(visit[i][j]==t-1){
                            bfs(i,j,x,t);
                        }
                    }
                }
            }
            x++;
        }
        x=1;
        t++;
    }
    cout<<land[X-1][Y-1]<<endl;
}
