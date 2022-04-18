#include <iostream>

using namespace std;

int seqSearch(int n, int target, int *data){
    for(int i=0;i<n;i++){
        if(data[i]==target){
            return i+1;
        }
    }
    return 0;
}

int main(){
    int n;
    int target;
    cin>>n>>target;
    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    cout<<seqSearch(n,target,array);
}
