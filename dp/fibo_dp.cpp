#include <iostream>

using namespace std;

long long d[100]={0};

long long dp(int x){
    if(x==1 || x==2) return 1;
    if(d[x]!=0) return d[x];
    return d[x]=dp(x-1)+dp(x-2);
}

int main(){
    cout<<dp(100)<<endl;
}
