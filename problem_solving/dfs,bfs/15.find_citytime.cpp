#include <vector>
#include <iostream>
#include <queue>


using namespace std;

vector<int> a[300001]={
    {0}
};
bool c[300001]={};
int d[300001]={};//0으로초기화

queue<int> q;
void bfs(int start){
    if(c[start]==false){
        q.push(start);
        c[start]=true;
        d[start]=0;
    }
    while(!q.empty()){
        int x=q.front();
        q.pop();
        int temp=d[x];
        temp++;
        for(int i=0;i<a[x].size();i++){
            int y=a[x][i];
            if(c[y]==false){
                q.push(y);
                c[y]=true;
                d[y]=temp;
            }
        }
    }
    
}
int main(){
    int n,m,k,x;
    cin>>n>>m>>k>>x;
    for(int i=0;i<m;i++){
        int from,to;
        cin>>from>>to;
        a[from].push_back(to);
    }
    int cnt=0;
    bfs(x);
    for(int i=1;i<=n;i++){
        if(d[i]==k){
            cnt++;
            cout<<i<<endl;
        }
    }
    if(cnt==0){
        cout<<-1<<endl;
    }
}
