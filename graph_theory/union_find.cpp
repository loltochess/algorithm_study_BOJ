#include <iostream>

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

int main(){
    int parent[11];
    for(int i=1;i<=10;i++){
        parent[i]=i;
    }
    unionParent(parent,1,2);
    unionParent(parent,2,3);
    unionParent(parent,3,4);
    unionParent(parent,5,6);
    unionParent(parent,6,7);
    unionParent(parent,7,8);
    cout<<"1과 5의 연결여부: "<<findParent(parent,1,5)<<endl;
    unionParent(parent,1,5);
    cout<<"1과 5의 연결여부: "<<findParent(parent,1,5)<<endl;
    cout<<"5와 6의 연결여부: "<<findParent(parent,5,6)<<endl;
    for(int i=1;i<=8;i++){
        cout<<parent[i]<<" ";
    }
    cout<<"\n";
}
