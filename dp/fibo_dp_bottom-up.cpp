#include <iostream>

using namespace std;

long long d[101]={0};

long long dp(int x){
    
    d[1]=d[2]=1;

    for(int i=3;i<=x;i++){
        d[i]=d[i-1]+d[i-2];
    }
    return d[x];
}

int main(){
    cout<<dp(100)<<endl;
}
