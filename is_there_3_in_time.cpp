#include <iostream>

using namespace std;

int main(){
    int N;
    cin>>N;
    int count=0;
    for(int i=0;i<=N;i++){
        for(int j=0;j<=59;j++){
            for(int k=0;k<=59;k++){
                if(i%10!=3 && i/10%10!=3 && j%10!=3 && j/10%10!=3 && k%10!=3 && k/10%10!=3){
                    continue;
                }
                count++;
            }
        }
    }
    cout<<count<<endl;
}
