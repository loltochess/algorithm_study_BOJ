#include <iostream>

using namespace std;



int main(){
    int dp[10001];
    for(int i=0;i<10001;i++){
        dp[i]=10001;
    }
    int n,m;
    cin>>n>>m;
    int coin[n+1];
    int coin_max=0;
    for(int i=1;i<=n;i++){
        cin>>coin[i];
        if(coin[i]>coin_max){
            coin_max=coin[i];
        }
    }
    dp[0]=0;
    for(int i=1;i<=coin_max;i++){
        for(int j=n;j>=1;j--){
            if(i%coin[j]==0){
                dp[i]=i/coin[j];
            }
        }
    }
    for(int i=coin_max+1;i<=m;i++){
        int coin_min=10001;
        for(int j=1;j<=n;j++){
            dp[i]=min(coin_min,dp[coin[j]]+dp[i-coin[j]]);
            if(dp[i]<coin_min){
                coin_min=dp[i];
            }
        }
        dp[i]=coin_min;
    }
    if(dp[m]==10001){
        cout<<-1<<endl;
    } else {
        cout<<dp[m]<<endl;
    }
}
