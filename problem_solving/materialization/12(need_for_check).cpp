#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int space[101][101]; //기둥=0, 보=1로 설정할 공간

bool build(int n, vector<vector<int>> temp,int x, int y, int a);

vector<vector<int>> solution(int n, vector<vector<int>> build_frame){
    
    vector<vector<int>> result;
    for (int i = 0; i < 101; i++)
    {
        for (int j = 0; j < 101; j++)
        {
            space[i][j] = -1; //-1로 초기화
        }
    }
    for (int i = 0; i < build_frame.size(); i++)
    {
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int a = build_frame[i][2];
        int b = build_frame[i][3];
        if (b == 1)
        { //설치
            if (a == 0)
            { //기둥 설치
                if (y == 0 && space[x][y] == -1)
                {                    //바닥에서 설치할 경우
                    space[x][y] = 0; //기둥 설치됨.
                    result.push_back({x,y,0});
                    continue;
                }
                else if (y >= 1 && (space[x][y - 1] == 0 || space[x][y-1]==2))
                { //기둥 위에 기둥을 설치할경우
                    if (space[x][y] == 1)
                    {                    //보가 있을 경우
                        space[x][y] = 2; //보+기둥
                    }
                    else
                    {
                        space[x][y] = 0;
                    }
                    result.push_back({x, y, 0});

                    continue;
                }
                else if (y >= 1 && (space[x - 1][y] == 1 || space[x + 1][y] == 1))
                { //보의 끝부분 위에 있는경우
                    if (space[x][y] == 1)
                    {                    //보가 있을 경우
                        space[x][y] = 2; //보+기둥
                    }
                    else
                    {
                        space[x][y] = 0;
                    }
                    result.push_back({x, y, 0});
                }
            }
            else
            { //보 설치
                if (y >= 1 && (space[x][y - 1] == 0 || space[x + 1][y - 1] == 0 || space[x][y-1]==2 || space[x+1][y-1]==2))
                { //한쪽 끝부분이 기둥 위에 있을 경우
                    if (space[x][y] == 0)
                    {
                        space[x][y] = 2;
                    }
                    else
                    {
                        space[x][y] = 1;
                    }
                    result.push_back({x, y, 1});
                }
                else if (space[x - 1][y] == 1 && space[x + 1][y] == 1)
                { //끝부분 보들과 동시에 연결
                    if (space[x][y]==0)
                    {
                        space[x][y] = 2;
                    }
                    else
                    {
                        space[x][y] = 1;
                    }
                    result.push_back({x, y, 1});
                }
            }
        }
        else
        { //삭제일 경우
            vector<vector<int>> temp;
            temp=result;
            vector<vector<int>>::iterator it = temp.begin();
            vector<vector<int>>::iterator it_result=result.begin();
            for (int i = 0; i < result.size(); i++)
            {
                if (result[i][0] == x && result[i][1] == y && result[i][2] == a)
                {
                    temp.erase(it);
                    if (build(temp.size(), temp,x,y,a))
                    {
                        result.erase(it_result);
                        if(space[x][y]==2){
                            if(a==0){
                                space[x][y]=1;
                            } else {
                                space[x][y]=0;
                            }
                        } else {
                            space[x][y]=-1;
                        }
                        i=1001;
                    } else {
                        it_result++;
                    }
                    temp=result;
                }
                it++;
                it_result++;
            }
        }
    }

    sort(result.begin(), result.end());
    return result;
}

bool build(int n, vector<vector<int>> temp, int x, int y,int a){
    int temp_space[101][101];
    for(int i=0;i<101;i++){
        for(int j=0;j<101;j++){
            temp_space[i][j]=space[i][j];
        }
    }
    if(space[x][y]==2){
        if(a==0){
            space[x][y]=1;
        } else {
            space[x][y]=0;
        }
    } else {
        space[x][y]=-1;
    }
    int cnt=n;
    for(int i=0;i<temp.size();i++){
        int xx=temp[i][0];
        int yy=temp[i][1];
        int aa=temp[i][2];
        if(aa==0){//기둥인경우
            if(yy==0 || space[xx][yy]>=1 || space[xx-1][yy]>=1 || space[xx][yy-1]>=1){
                cnt--;
            }
        } else { // 보인 경우
            if(space[xx][yy-1]==0 || space[xx][yy-1]==2 || space[xx+1][yy-1]==0 || space[xx][yy-1]==2 || (space[xx-1][yy]>=1 && space[xx+1][yy]>=1)){
                cnt--;
            }
        }
    }
    if(cnt==0){
        return true;
    } else {
        return false;
    }
}


int main()
{
    vector<vector<int>> build_frame = {
        {0, 0, 0, 1},
        {2, 0, 0, 1},
        {4, 0, 0, 1},
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {2, 1, 1, 1},
        {3, 1, 1, 1},
        {2, 0, 0, 0},
        {1, 1, 1, 0},
        {2, 2, 0, 1}
    };
    vector<vector<int>> solutions = solution(5, build_frame);
    for (int i = 0; i < solutions.size(); i++)
    {
        for (int j = 0; j < solutions[0].size(); j++)
        {
            cout << solutions[i][j];
        }
        cout << "\n";
    }
    return 0;
}
