#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int node[8]={0,1,2,3,4,5,6,7};
int Degree[8]={-1,0,1,1,2,1,2,1};
vector<int>a[8]={
    {},
    {2,5},
    {3,6},
    {4},
    {7},
    {6},
    {4,7},
    {}
};
vector<int> result;
int main(){
    queue<int> q;
    for(int i=1;i<=7;i++){
        if(Degree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int x=q.front();
        q.pop();
        result.push_back(x);
        for(int j=0;j<a[x].size();j++){
            int y=a[x][j];
            Degree[y]--;
            if(Degree[y]==0){
                q.push(y);
            }
        }
    }
    for(int i=0;i<=6;i++){
        cout<<result[i]<<endl;
    }
}
