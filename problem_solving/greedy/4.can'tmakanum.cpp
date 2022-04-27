#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a, int b){
    return a>b;
}
int main(){
    int n;
    cin>>n;
    int coin[1001];
    for(int i=0;i<n;i++){
        cin>>coin[i];
    }
    sort(coin,coin+n,compare);
    int price=1;
    while(1){
        int cnt=0;
        for(int i=0;i<n;i++){
            int temp=price;
            for(int j=i;j<n;j++){
                if(temp>=coin[j]){
                    temp-=coin[j];
                }
                if(temp==0){
                    cnt++;
                    break;
                }
            }
            if(temp==0){
                cnt++;
                break;
            }
        }
        if(cnt>0){
            price++;
        } else {
            cout<<price<<endl;
            break;
        }
    }

}
