#include <iostream>
#include <algorithm>

using namespace std;

int ways[30001]={0};

int func(int x){
    ways[2]=ways[3]=ways[5]=1;
    ways[4]=2;
    for(int i=6;i<=x;i++){
        int problems[4]={30000,30000,30000,30000};
        int temp=30000;
        if(i%5==0){
            problems[0]=ways[i/5]+1;
        }
        if(i%3==0){
            problems[1]=ways[i/3]+1;
        }
        if(i%2==0){
            problems[2]=ways[i/2]+1;
        }
        problems[3]=ways[i-1]+1;
        sort(problems,problems+4);
        ways[i]=problems[0];
    }
    return ways[x];
}

int main(){
    int n;
    cin>>n;
    cout<<func(n)<<endl;
}
