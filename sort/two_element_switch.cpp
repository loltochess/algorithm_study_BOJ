#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(int a, int b){
    return a>b;
}
int main(){
    int n,k;
    cin>>n>>k;
    int arrA[100001];
    int arrB[100001];
    for(int i=0;i<n;i++){
        cin>>arrA[i];
    }
    for(int i=0;i<n;i++){
        cin>>arrB[i];
    }
    sort(arrA,arrA+n);
    sort(arrB,arrB+n,compare);
    int sum=0;
    int temp;
    for(int i=0;i<k;i++){
        if(arrA[i]<arrB[i]){
            temp=arrA[i];
            arrA[i]=arrB[i];
            arrB[i]=temp;
        } else break;
    }
    for(int i=0;i<n;i++){
        sum+=arrA[i];
    }
    cout<<sum<<"\n";
}
