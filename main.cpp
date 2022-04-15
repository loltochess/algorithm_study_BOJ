#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    int data[n]={0};
    for(int i=0;i<n;i++){
        cin>>data[i];
    }
    sort(data,data+n);
    int sum=0;
    int count=0;
    int first=data[n-1];
    int second=data[n-2];
    
    count=m/(k+1)*k;
    count+=m%(k+1);

    sum+=count*first;
    sum+=(m-count)*second;
    
    cout<<sum<<endl;
}