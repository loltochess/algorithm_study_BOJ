#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int number=6;
int INF=10000000;
vector<pair<int,int>>a[7]={
    {{0,0}},
    {{2,2},{5,3},{1,4}},
    {{2,1},{3,3},{2,4}},
    {{5,1},{3,2},{3,4},{1,5},{5,6}},
    {{1,1},{2,2},{3,3},{1,5}},
    {{1,3},{1,4},{2,6}},
    {{5,3},{2,5}}
};
int d[7];//최단경로

void dijkstra(int start){
    for(int i=1;i<=number;i++){
        d[i]=INF;
    }
    d[start]=0;
    priority_queue<pair<int,int>> pq;
    pq.push({0,start});//first로결정
    while(!pq.empty()){
        int current=pq.top().second;
        int distance=-pq.top().first; //0은 모든음수보다크므로 가장먼저나온다.
        pq.pop();
        if(d[current]<-distance){
            continue;
        }
        for(int i=0;i<a[current].size();i++){
            int next=a[current][i].second;
            int nextDistance=distance+a[current][i].first;
            if(nextDistance<d[next]){
                d[next]=nextDistance;
                pq.push({-nextDistance,next});
            }
        }
    }

}

int main(){
    dijkstra(6);
    for(int i=1;i<=number;i++){
        cout<<d[i]<<" ";
    }
    cout<<"\n";
}
