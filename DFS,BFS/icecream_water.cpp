#include <bits/stdc++.h>

using namespace std;

int icecream[1001][1001];

int N,M;

bool dfs(int i, int j){
    if(icecream[i][j]==1){
        return false;
    }
    else if(i<0 || i>=N ||j<0 || j>=M){
        return false;
    }
    else if(icecream[i][j]==0){
        icecream[i][j]=1;
        dfs(i-1,j);
        dfs(i+1,j);
        dfs(i,j+1);
        dfs(i,j-1);
        return true;
    }
    return false;
}

int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%1d",icecream[i][j]);
        }
    }

    int result=0;
    int a=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(dfs(i,j)){
                result++;
            }
        }
    }
    cout<<result<<endl;
}
