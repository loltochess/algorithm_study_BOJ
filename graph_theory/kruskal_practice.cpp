#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int getParent(int parent[],int x){
    if(parent[x]==x) return x;
    return getParent(parent,parent[x]);
}

void unionParent(int parent[],int a, int b){
    a=getParent(parent,a);
    b=getParent(parent,b);
    if(a<b) parent[b]=a;
    else parent[a]=b;
}

int findParent(int parent[],int a, int b){
    a=getParent(parent,a);
    b=getParent(parent,b);
    if(a==b){
        return 1;
    }
    return 0;
}

bool compare(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
    return a.second<b.second;
}
int main(){
    vector<pair<pair<int,int>,int>> kru;
    int v,e;
    cin>>v>>e;
    int node[v+1]={};
    int parent[v+1]={};
    for(int i=1;i<=v;i++){
        node[i]=i;
        parent[i]=i;
    }
    for(int i=0;i<e;i++){
        int start,end,cost;
        cin>>start>>end>>cost;
        kru.push_back(pair<pair<int,int>,int>(pair<int,int>(start,end),cost));
    }
    sort(kru.begin(),kru.end(),compare);
    int result=0;
    for(int i=0;i<e;i++){
        if(findParent(parent,kru[i].first.first,kru[i].first.second)==0){
            unionParent(parent,kru[i].first.first,kru[i].first.second);
            result+=kru[i].second;
        }
    }
    cout<<result<<endl;
}
