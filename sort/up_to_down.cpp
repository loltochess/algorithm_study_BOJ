#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a,int b){
    if(a>=b){
        return 1;
    } else return 0;
}

int main(){
    int array[501];
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>array[i];
    }
    sort(array,array+N,compare);
    for(int i=0;i<N;i++){
        cout<<array[i]<<" ";
    }
    cout<<"\n";
}
