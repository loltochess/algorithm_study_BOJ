#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int board[102][102]={}; //apple위치

void move(deque<pair<int,pair<int,int>>> &snake, char direction, int &apple){
    char dir[4]={'R','L','U','D'};
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,-1,1};
    for(int i=0;i<4;i++){
        if(direction==dir[i]){
            snake.push_back({apple+1,{snake.back().second.first+dy[i],snake.back().second.second+dx[i]}});
        }  
    }
    if(board[snake.back().second.first][snake.back().second.second]==1){
        apple++;
        board[snake.back().second.first][snake.back().second.second]=0;
        return;
    }
    else{
        for(int i=0;i<snake.size();i++){
            snake[i].first--;
        }
    }
}

char changed(char direction, char change){
    char dir[4]={'R','U','L','D'};
    if(change=='L'){
        for(int i=0;i<4;i++){
            if(direction=='D'){
                direction='R';
                break;
            }
            else if(direction==dir[i]){
                direction=dir[i+1];
                break;
            }
        }
    } else {
        for(int i=0;i<4;i++){
            if(direction=='R'){
                direction='D';
                break;
            }
            else if(direction==dir[i]){
                direction=dir[i-1];
                break;
            }
        }
    }
    return direction;
}
int main(){
    int n,k,l;
    cin>>n;
    cin>>k;
    for(int i=0;i<k;i++){
        int x,y;
        cin>>x>>y;
        board[x][y]=1;
    }
    cin>>l;
    deque<pair<int,char>> cmd; //{time,방향}
    for(int i=0;i<l;i++){
        int time;
        char change;
        cin>>time>>change;
        cmd.push_back({time,change});
    }
    char direction='R';
    int t=1;
    deque<pair<int,pair<int,int>>> snake; //남은 수명, 위치
    snake.push_back({0,{1,1}});
    int apple=0;
    int x=0;
    while(1){
        int cnt=0;
        move(snake,direction,apple);
        if(snake.back().second.first<1 || snake.back().second.first>n || snake.back().second.second<1 || snake.back().second.second>n){
            break;
        }
        if(snake.size()>1){
            for(int i=0;i<snake.size()-1;i++){
                if(snake[i].first>=-1){
                    if(snake.back().second.first==snake[i].second.first && snake.back().second.second==snake[i].second.second){
                        cnt++;
                    }
                }
            }
        }
        if(cnt>0){
            break;
        }
        if(cmd[x].first==t){
            direction=changed(direction,cmd[x].second);
            x++;
        }
        t++;
    }
    cout<<t<<endl;
}
