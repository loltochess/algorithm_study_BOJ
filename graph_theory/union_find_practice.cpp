#include <iostream>
#include <vector>
using namespace std;

int data[7]={0,1,2,3,4,5,6};
int parent[7]={0,1,2,3,4,5,6};

int getParent(int x){
    if(parent[x]==x){
        return x;
    } else {
        return getParent(parent[x]);
    }
}

void unionParent(int a,int b){
    a=getParent(a);
    b=getParent(b);
    if(a<=b){
        parent[b]=a;
    } else {
        parent[a]=b;
    }
}

bool findParent(int a, int b){
    a=getParent(a);
    b=getParent(b);
    if(a==b){
        return true;
    } else {
        return false;
    }
}

void ifcycle(){
    cout<<"사이클입력함수입니다. 세 가지 노드를 입력하시오."<<endl;
    int a,b,c;
    cin>>a>>b>>c;
    vector<pair<int,int>> cycle;
    cycle.push_back({a,b});
    cycle.push_back({b,c});
    cycle.push_back({c,a});
    int cnt=0;
    for(int i=0;i<cycle.size();i++){
        if(findParent(cycle[i].first,cycle[i].second)){
            cnt++;
            cout<<cycle[i].first<<"와"<<cycle[i].second<<"는 연결 상태입니다."<<endl;
        } else {
            cout<<cycle[i].first<<"와"<<cycle[i].second<<"는 연결되지 않았습니다."<<endl;
        }
    }
    if(cnt==3){
        cout<<cycle[0].first<<","<<cycle[1].first<<","<<cycle[2].first<<"는 CYCLE상태입니다."<<endl;
    } else {
        cout<<"cycle연결 상태가 아닙니다."<<endl;
    }
}
int main(){
    unionParent(1,4);
    unionParent(2,3);
    unionParent(2,4);
    unionParent(5,6);
    if(findParent(1,5)){
        cout<<"1과 5는 연결 상태입니다."<<endl;
    } else {
        cout<<"1과 5는 연결 상태가 아닙니다."<<endl;
    }
    ifcycle();
}
