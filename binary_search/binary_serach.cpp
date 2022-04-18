#include <iostream>

using namespace std;

int binSearch(int *array, int target, int start, int end){
    if(start>end){
        return -1;
    }
    int mid=(start+end)/2;
    if(array[mid]==target){
        return mid;
    } else if(array[mid]>target){
        return binSearch(array,target,start,mid-1);
    } else {
        return binSearch(array,target,mid+1,end);
    }
}   

int main(){
    int n,target;
    cin>>n>>target;
    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    int result=binSearch(array,target,0,n-1);
    if(result==-1){
        cout<<"there is no target element."<<"\n";
        return 0;
    }
    cout<<binSearch(array,target,0,n-1)<<endl;
}
