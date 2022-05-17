#include <iostream>

using namespace std;

int n; 
int t[16];
int p[16];
int dp[16];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t[i]>>p[i];
        dp[i]=p[i];
    }
    for(int i=2;i<=n;i++){
        if(i+t[i]>n+1){
            dp[i]=0;
            continue;
        }
        int maxp=0;
        for(int j=1;j<=i-1;j++){
            if(j+t[j]<=i){
                maxp=max(maxp,dp[j]);
            }
        }
        dp[i]+=maxp;
    }
    int answer=0;
    for(int i=1;i<=n;i++){
        answer=max(answer,dp[i]);
    }
    if(1+t[1]>n+1 && answer==dp[1]){
        cout<<0<<endl;
        return 0;
    }
    cout<<answer<<endl;
}
