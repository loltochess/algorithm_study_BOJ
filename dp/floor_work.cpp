#include <iostream>

using namespace std;

int main(){
    int d[1001];
    d[0]=1;
    d[1]=1;

    int n;
    cin>>n;

    for(int i=2;i<=n;i++){
        d[i]=(d[i-1]+2*d[i-2])%796,796;
    }
    cout<<d[n]<<endl;
}
