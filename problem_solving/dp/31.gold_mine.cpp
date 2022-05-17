#include <bits/stdc++.h>

using namespace std;

int t,n,m;
int land[20][20];
int dp[20][20];

int main(){
    cin>>t;
    while(t-->0){
        cin>>n>>m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>land[i][j];
                dp[i][j]=land[i][j];
            }
        }

        for(int j=1;j<m;j++){
            for(int i=0;i<n;i++){
                int leftup,left,leftdown;
                if(i==0){
                    leftup=0;
                } else {
                    leftup=dp[i-1][j-1];
                }
                if(i==n-1){
                    leftdown=0;
                } else {
                    leftdown=dp[i+1][j-1];
                }
                left=dp[i][j-1];
                dp[i][j]+=max(leftup,max(left,leftdown));
            }
        }
        int result=0;
        for(int i=0;i<n;i++){
            result=max(result,dp[i][m-1]);
        }
        cout<<result<<"\n";
    }
}
