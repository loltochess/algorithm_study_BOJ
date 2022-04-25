#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int data[101]={0};
    for(int i=1;i<=n;i++){
        cin>>data[i];
    }
    int d[101]={0};
    d[1]=data[1];
    d[2]=max(data[1],data[2]);
    for(int i=3;i<=n;i++){
        d[i]=max(d[i-1],d[i-2]+data[i]);
    }
    
    cout<<d[n]<<endl;
    
}
