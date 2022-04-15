#include <iostream>
#include <vector>

using namespace std;

void R(int N,int &a, int &b){
    if(b<N){
        b++;
    }
}

void L(int N,int &a, int &b){
    if(b>1){
        b--;
    }
}

void U(int N,int &a,int &b){
    if(a>1){
        a--;
    }
}

void D(int N,int &a, int &b){
    if(a<N){
        a++;
    }
}
int main(){
    int N;
    cin>>N;
    int a=1,b=1;
    for(int i=0;i<N;i++){
        char select;
        cin>>select;
        if(select=='R'){
            R(N,a,b);
        } else if(select=='L'){
            L(N,a,b);
        } else if(select=='U'){
            U(N,a,b);
        } else if(select=='D'){
            D(N,a,b);
        }
    }
    cout<<a<<" "<<b<<endl;
}
