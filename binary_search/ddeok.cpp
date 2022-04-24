#include <iostream>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int data[n];
    int max=0;
    for(int i=0;i<n;i++){
        cin>>data[i];
        if(data[i]>max){
            max=data[i];
        }
    }
    int start=0;
    int end=max;
    int result=0;
    while(start<=end){
        int sum=0;
        int mid=(start+end)/2;
        for(int i=0;i<n;i++){
            if(data[i]>mid){
                sum+=data[i]-mid;
            }
        }
        if(sum<m){
            end=mid-1;
        } else {
            result=mid;
            start=mid+1;
        }
    }
    cout<<result<<endl;
}
