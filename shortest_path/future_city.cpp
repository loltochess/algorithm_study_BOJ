#include <iostream>

using namespace std;

int INF=10000000;

int main(){
    int n,m;
    cin>>n>>m;
    int d[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            d[i][j]=INF;
        }
        d[i][i]=0;
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        d[a-1][b-1]=1;
        d[b-1][a-1]=1;
    }
    int X,K;
    cin>>X>>K;
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(d[i][k]+d[k][j]<d[i][j]){
                    d[i][j]=d[i][k]+d[k][j];
                }
            }
        }
    }
    if(d[0][K-1]+d[K-1][X-1]<=INF)
        cout<<d[0][K-1]+d[K-1][X-1]<<endl;
    else
        cout<<-1<<endl;
}
