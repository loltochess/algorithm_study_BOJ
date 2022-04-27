#include <iostream>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int ball[1001]={};
    for(int i=0;i<n;i++){
        cin>>ball[i];
    }
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(ball[i]!=ball[j]){
                count++;
            }
        }
    }
    cout<<count<<endl;
}
