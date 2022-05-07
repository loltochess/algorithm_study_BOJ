#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,k;
int x=1;
int t=1;
int land[201][201]={};
int visit[201][201]={}; //바이러스는 한 번 만 증식가능함!(어차피 막혔으니깐)


void search(int i,int j, int t){
    visit[i][j]=t;
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    int virus=1001;
    for(int k=0;k<4;k++){
        int tempx=i+dx[k];
        int tempy=j+dy[k];
        if(tempx>=0 && tempx<n && tempy>=0 && tempy<n && land[tempx][tempy]>0 && visit[tempx][tempy]==t-1){
            virus=min(virus,land[tempx][tempy]);
        }
    }
    if(virus==1001){
        virus=0;
    }
    land[i][j]=virus;
}

int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>land[i][j];
        }
    }
    int S,X,Y;
    cin>>S>>X>>Y;
    while(t<=S){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(land[i][j]==0){
                    search(i,j,t);
                }
            }
        }
        t++;
    }
    cout<<land[X-1][Y-1]<<endl;
}
