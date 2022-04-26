#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int INF=100000000;

int main(){
    int n,m,c;
    cin>>n>>m>>c;
    vector<pair<int,int>> a[n+1];
    int d[n+1];
    for(int i=1;i<=n;i++){
        d[i]=INF;
    }
    d[c]=0;
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        a[x].push_back({z,y});
    }
    priority_queue<pair<int,int>> pq;
    pq.push({0,c});
    while(!pq.empty()){
        int current=pq.top().second;
        int distance=-pq.top().first;
        pq.pop();
        if(distance>d[current]){
            continue;
        }
        for(int i=0;i<a[current].size();i++){
            int next=a[current][i].second;
            int nextDistance=a[current][i].first+distance;
            if(nextDistance<d[next]){
                d[next]=nextDistance;
                pq.push({-nextDistance,next});
            }
        }
    }
    int cities=0;
    int time=0;
    for(int i=1;i<=n;i++){
        if(d[i]>0 && d[i]<INF){
            cities++;
            if(d[i]>time){
            time=d[i];
            }
        }
    }
    cout<<cities<<" "<<time<<endl;
}
