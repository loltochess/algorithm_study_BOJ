#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> time;
    time.push_back(0);//time[1]부터시작하기위해
    vector<int> lesson[n+1];
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        time.push_back(t);
        while(1){
            int l;
            cin>>l;
            if(l==-1){
                break;
            }
            lesson[l].push_back(i);
        }
    }//초기작업 끝
    int Degree[n+1]={};
    for(int i=1;i<=n;i++){
        for(int j=0;j<lesson[i].size();j++){
            int y=lesson[i][j];
            Degree[y]++;
        }
    }
    int defaults[n+1]={0};
    for(int i=1;i<=n;i++){
        defaults[i]=time[i];
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(Degree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int x=q.front();
        cout<<time[x]<<endl;
        q.pop();
        for(int i=0;i<lesson[x].size();i++){
            int y=lesson[x][i];
            time[y]=max(time[y],time[x]+defaults[y]);
            Degree[y]--;
            if(Degree[y]==0){
                q.push(y);
            }
        }
    }
}
