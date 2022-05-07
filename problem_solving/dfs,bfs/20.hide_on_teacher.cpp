#include <iostream>
#include <vector>

using namespace std;

int n;
char land[6][6];
char temp[6][6];
vector<pair<int,int>> teacher;
vector<pair<int,int>> student;
vector<pair<int,int>> obstacle;
int student_num=student.size();
bool ifright=0;
int visit[6][6]={};// 방문x=0 방문한곳=1 학생과선생님=2

bool calculate(char temp[][6]){
    for(int i=0;i<teacher.size();i++){
        int x=teacher[i].first;
        int y=teacher[i].second;
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        for(int i=0;i<4;i++){
            int tempx=x;
            int tempy=y;
            while(1){
                tempx+=dx[i];
                tempy+=dy[i];
                if(!(tempx>=0 && tempx<n && tempy>=0 && tempy<n)){
                    break;
                }
                if(temp[tempx][tempy]=='O' || temp[tempx][tempy]=='T'){
                    break;
                }
                if(temp[tempx][tempy]=='S'){
                    return false;
                }
            }
        }
    }
    return true;
}

void obstacle_select(pair<int,int> here, int cnt){
    if(cnt==3){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp[i][j]=land[i][j];
            }
        }
        for(int i=0;i<3;i++){
            int x=obstacle[i].first;
            int y=obstacle[i].second;
            temp[x][y]='O';
        }
        if(calculate(temp)){
            ifright=1;
            return;
        }
        return;  
    }
    for(int j=here.second;j<n;j++){
        if(visit[here.first][j]==0){
            visit[here.first][j]=1;
            obstacle.push_back({here.first,j});
            obstacle_select(here,cnt+1);
            obstacle.pop_back();
            visit[here.first][j]=0;
        }
    }
    for(int i=here.first+1;i<n;i++){
        for(int j=0;j<n;j++){
            if(visit[i][j]==0){
                visit[i][j]=1;
                obstacle.push_back({i,j});
                obstacle_select(here,cnt+1);
                obstacle.pop_back();
                visit[i][j]=0;
            }
        }
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>land[i][j];
            if(land[i][j]=='S'){
                student.push_back({i,j});
                visit[i][j]=2;
            }
            if(land[i][j]=='T'){
                teacher.push_back({i,j});
                visit[i][j]=2;
            }
        }
    }
    obstacle_select({0,0},0);
    if(ifright==true){
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    }
}
