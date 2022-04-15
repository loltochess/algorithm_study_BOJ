#include <iostream>

using namespace std;

int main(){
    int N,M;
    cin>>N>>M;
    int max=0;
    for(int i=0;i<N;i++){
        int min=10000;
        for(int j=0;j<M;j++){
            int num;
            cin>>num;
            if(num<min){
                min=num;
            }
        }
        if(max<min){
            max=min;
        }
    }
    cout<<max<<endl;
}
