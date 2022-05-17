#include <iostream>

using namespace std;

int n;
int tri[501][501];
int dp[501][501];
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cin>>tri[i][j];
            dp[i][j]=tri[i][j];
        }
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<=i;j++){
            int left,right;
            if(j-1<0){
                left=0;
            } else {
                left=dp[i-1][j-1];
            }
            if(j==i){
                right=0;
            } else {
                right=dp[i-1][j];
            }
            dp[i][j]+=max(left,right);
        }
    }
    int last_max=0;
    for(int j=0;j<n;j++){
        last_max=max(last_max,dp[n-1][j]);
    }
    cout<<last_max<<endl;
}
