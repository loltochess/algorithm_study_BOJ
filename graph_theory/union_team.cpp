#include <iostream>
#include <vector>

using namespace std;

vector<int> student;
vector<int> parent;

int getParent(int a){
    if(parent[a]==a){
        return a;
    } else return getParent(parent[a]);
}

void unionParent(int a, int b){
    if(parent[a]!=parent[b]){
        if(parent[a]>parent[b]){
            parent[a]=parent[b];
        } else parent[b]=parent[a];
    }
}

void findParent(int a,int b){
    if(getParent(a)==getParent(b)){
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=n;i++){//N+1명이 있는셈
        student.push_back(i);
        parent.push_back(i);
    }
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        if(x==0){
            unionParent(y,z);
        } else if(x==1){
            findParent(y,z);
        }
    }
}
