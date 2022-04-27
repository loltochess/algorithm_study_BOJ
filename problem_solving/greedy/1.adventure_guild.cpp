#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    int man[100001];
    for(int i=0;i<n;i++){
        cin>>man[i];
    }
    sort(man,man+n);
    int group=0;
    for(int i=0;i<n;i++){
        int aaa=0;
        if(n-i>=man[i]){
            for(int j=i;j<=i+man[i]-1;j++){
                if(man[j]>man[i]){
                    aaa++;
                    break;
                }
            }
        } else {
            aaa++;
        }
        if(aaa>0){
            break;
        }
        group++;
        i=i+man[i]-1;
    }
    cout<<group<<endl;
}
