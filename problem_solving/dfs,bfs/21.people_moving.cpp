#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
int A[51][51]={};
int L,R;
int di[4]={1,-1,0,0};
int dj[4]={0,0,1,-1};
int sum=0;
bool visit[51][51]={};
vector<pair<int,int>> opened;

bool dfs(int i, int j){
    if(visit[i][j]==true){
        return false;
    }
    visit[i][j]=true;
    opened.push_back({i,j});
    sum+=A[i][j];
    for(int k=0;k<4;k++){
        int tempi=i+di[k];
        int tempj=j+dj[k];
        if(tempi<0 || tempi>=N || tempj<0 || tempj>=N){
            continue;
        }
        if(abs(A[tempi][tempj]-A[i][j])>=L && abs(A[tempi][tempj]-A[i][j])<=R){
            dfs(tempi,tempj);
        }
    }
    if(opened.size()==1){
        visit[i][j]=false;
        opened.pop_back();
        sum-=A[i][j];
        return false;
    }
    return true;
}

int main(){
    int count=0;
    cin>>N>>L>>R;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>A[i][j];
        }
    }
    int cnt=1;

    while(cnt!=0){
        cnt=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(dfs(i,j)){
                    int average=sum/opened.size();
                    for(int i=0;i<opened.size();i++){
                        int x=opened[i].first;
                        int y=opened[i].second;
                        A[x][y]=average;
                    }
                    sum=0;
                    cnt++;
                }
                while(!opened.empty()){
                    opened.pop_back();
                }
            }
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                visit[i][j]=false;
            }
        }
        count++;
    }
    cout<<count-1<<endl;
}
