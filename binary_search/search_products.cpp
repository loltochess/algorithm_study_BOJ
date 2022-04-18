#include <iostream>
#include <algorithm>

using namespace std;

void binSearch(int *array,int target,int start, int end){
    if(start>end){
        cout<<"no"<<endl;
        return;
    }
    int mid=(start+end)/2;
    if(array[mid]==target){
        cout<<"yes"<<endl;
        return;
    } else if(array[mid]>target){
        return binSearch(array,target,start,mid-1);
    } else {
        return binSearch(array,target,mid+1,end);
    }
}

int main(){
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    int m;
    cin>>m;
    int check[m];
    for(int j=0;j<m;j++){
        cin>>check[j];
    }
    sort(array,array+n);
    for(int j=0;j<m;j++){
        binSearch(array,check[j],0,n-1);
    }
}
