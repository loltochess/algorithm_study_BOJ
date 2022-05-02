#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> flip(vector<vector<int>> lock){

    vector<vector<int>> temp(lock.size(),vector<int>(lock[0].size(),0));
    for(int i=0;i<lock.size();i++){
        for(int j=lock.size()-1;j>=0;j--){
            temp[i][j]=lock[lock.size()-1-j][i];
        }
    }
    return temp;
}

bool check(vector<vector<int>> key, vector<vector<int>> lock){
    vector<vector<int>> board(lock.size()-2+2*key.size(),vector<int>(lock.size()-2+2*key.size(),0));
    for(int i=key.size()-1;i<=lock.size()+key.size()-2;i++){
        for(int j=key.size()-1;j<=lock.size()+key.size()-2;j++){
            board[i][j]=lock[i-key.size()+1][j-key.size()+1];
        }
    }
    int cnt=0;
    for(int i=0;i<key.size()+lock.size()-1;i++){
        for(int j=0;j<key.size()+lock.size()-1;j++){
            vector<vector<int>> newboard(lock.size()-2+2*key.size(),vector<int>(lock.size()-2+2*key.size(),0));
            newboard=board;
            cnt=0;
            int a=0;
            for(int x=i;x<i+key.size();x++){
                int b=0;
                for(int y=j;y<j+key.size();y++){
                    newboard[x][y]+=key[a][b];
                    b++;
                }
                a++;
            }
            for(int m=key.size()-1;m<key.size()+lock.size()-1;m++){
                for(int n=key.size()-1;n<key.size()+lock.size()-1;n++){
                    if(newboard[m][n]==0 || newboard[m][n]==2){
                        cnt++;
                    }
                }
            }
            if(cnt==0){
                return true;
            }
        }
    }
    return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    for(int i=0;i<4;i++){
        lock=flip(lock);
        if(check(key,lock)){
            return true;
        }
    }
    return false;
}
