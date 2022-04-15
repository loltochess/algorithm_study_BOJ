#include <iostream>

using namespace std;

int main(){
    int N,K;
    cin>>N>>K;
    int count=0;
    while(1){
        if(N==1){
            break;
        }
        else if(N%K==0){
            count++;
            N
        }
        else {
            N=N-1;
            count++;
        }
    }
    cout<<count<<endl;
}
