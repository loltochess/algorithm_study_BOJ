#include <iostream>
#include <string>

using namespace std;

int dx[]={-2,-1,1,2,2,1,-1,-2};
int dy[]={-1,-2,-2,-1,1,2,2,1};
int main(){
    string data;
    cin>>data;
    int garo=data[0]-'a'+1;
    int sero=data[1]-'0';
    int result=0;
    int tempx,tempy;
    for(int i=0;i<8;i++){
        tempx=garo+dx[i];
        tempy=sero+dy[i];

        if(tempx>=1 && tempx<=8 && tempy>=1 && tempy>=8){
            result++;
        }
    }
    cout<<result<<endl;
}
