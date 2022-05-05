    #include <vector>
    #include <queue>
    #include <iostream>

    using namespace std;

    int land[9][9]={};
    queue<pair<int,int>> q;
    vector<pair<int,int>> virus;
    vector<pair<int,int>> wall;
    vector<pair<int,int>> house;

    bool house_wall[80]={};

    int answer=0;

    int n,m;




    int bfs(vector<pair<int,int>> virus){
        int temp[9][9];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                temp[i][j]=land[i][j];
            }
        }
        int cnt=0;
        for(int i=0;i<virus.size();i++){
            int x=virus[i].first;
            int y=virus[i].second;
            q.push({x,y});
            int dx[4]={0,0,1,-1};
            int dy[4]={1,-1,0,0};
            while(!q.empty()){
                pair<int,int> a=q.front();
                q.pop();

                for(int i=0;i<4;i++){
                    x=a.first;
                    y=a.second;
                    x+=dx[i];
                    y+=dy[i];
                    if(temp[x][y]==0 && x>=0 && x<n && y>=0 && y<m){
                        temp[x][y]=2;
                        q.push({x,y});
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(temp[i][j]==0){
                    cnt++;
                }
            }
        }
        return cnt;
    }

    void select_wall(int idx, int cnt){
        if(cnt==3){
            for(int i=0;i<3;i++){
                land[wall[i].first][wall[i].second]=1;
            }
            answer=max(answer,bfs(virus));
            for(int i=0;i<3;i++){
                land[wall[i].first][wall[i].second]=0;
            }
            return;
        }
        for(int i=idx;i<house.size();i++){
            if(house_wall[i]==true){
                continue;
            }
            house_wall[i]=true;
            wall.push_back({house[i].first,house[i].second});
            select_wall(i,cnt+1);
            house_wall[i]=false;
            wall.pop_back();
        }
    }

    int main(){
        cin>>n>>m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>land[i][j];
                if(land[i][j]==2){
                    virus.push_back({i,j});
                }
                if(land[i][j]==0){
                    house.push_back({i,j});
                }
            }
        }
        select_wall(0,0);
        cout<<answer<<endl;
    }
