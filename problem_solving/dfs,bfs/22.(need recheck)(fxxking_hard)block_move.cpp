#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<vector<int>> board;
pair<pair<int,int>,pair<int,int>> drone={{0,0},{0,1}};
queue <bool> q;
bool visit_move[101][101]={};
bool visit_turn[101][101]={};
int fx=drone.first.first;
int fy=drone.first.second;
int sx=drone.second.first;
int sy=drone.second.second;
int time=0;
int N=board.size();

// 어느 좌표를 축으로 하냐에 따라 회전의 결과는 다르다.
bool clockwise_turn(int x, int y){//x,y는 축이 되는 좌표다.
    pair<pair<int,int>,pair<int,int>> temp=drone;
    if(fx==x && fy==y){//fx,fy가 축일 경우
        int tempx=sx-fx;
        int tempy=sy-fy;
        if(board[fx+tempy][sy]==0 && board[fx+tempy][fy-tempx]==0){
            sx=fx+tempy;
            sy=fy-tempx;
            time++;
            return true;
        }
    } else {//sx,sy가 축일 경우
        int tempx=fx-sx;
        int tempy=fy-sy;
        if(board[-tempy+sx][fy]==0 && board[-tempy+sx][tempx+sy]==0){
            fx=-tempy+sx;
            fy=tempx+sy;
            time++;
            return true;
        }
    }
    return false;
}

void counter_clockwise_turn(int x, int y){
    if(fx==x && fy==y){
        int tempx=sx-fx;
        int tempy=sy-fy;
        if(board[-tempy+fx][sy]==0 && board[-tempy+fx][tempx+sx]==0){
            sx=-tempy+fx;
            sy=tempx+sx;
            time++;
        }
    } else {
        int tempx=fx-sx;
        int tempy=fy-sy;
        if(board[tempy+sx][fy]==0 && board[tempy+sx][-tempx+sy]==0){
            fx=tempy+sx;
            fy=-tempx+sy;
            time++;
        }
    }
}

bool move(){
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    for(int i=0;i<3;i++){
        pair<pair<int,int>,pair<int,int>> t_drone;
        t_drone={{fx+dx[i],fy+dy[i]},{sx+dx[i],sy+dy[i]}};
        int t1x=t_drone.first.first;
        int t1y=t_drone.first.second;
        int t2x=t_drone.second.first;
        int t2y=t_drone.second.second;
        if(t1x>=0 && t1x<N && t1y>=0 && t1y<N && t2x>=0 && t2x<N && t2y>=0 && t2y<N){
            if(board[t1x][t1y]==0 && board[t2x][t2y]==0 && (visit_move[t1x][t2y]==false || visit_move[t1x][t2y]==false)){
                drone=t_drone;
                time++;
                while(1){
                    if(!move()){
                        counter_clockwise_turn(sx,sy);
                    }
                }
            }
        }
    }
    return false;
}

void bfs(int k){

}

int solution(vector<vector<int>> board) {
    int answer = 10000001;
    return answer;
}

int main(){
    vector<vector<int>> board={
        {0, 0, 0, 1, 1},{0, 0, 0, 1, 0},{0, 1, 0, 1, 1},{1, 1, 0, 0, 1},{0, 0, 0, 0, 0}
    };
    cout<<solution(board)<<endl;
}
