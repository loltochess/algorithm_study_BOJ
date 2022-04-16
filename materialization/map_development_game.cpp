#include <iostream>

using namespace std;

void move(int &A,int &B,int &d){

}
int main(){
    int N,M;
    cin>>N>>M;
    int A,B,d;
    cin>>A>>B>>d;
    int land[N][M]={0};
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>land[i][j];
        }
    }
    int dx[]={-1,0,1,0};
    int dy[]={0,-1,0,1};
    int nA=A;
    int nB=B;
    int count[N][M]={0};
    count[A][B]=1;
    int bulga=0;
    while(1){
        d++;
        if(d==4){
            d=0;
        }
        if(bulga==5){
            d--;
            if(d==0){
                d=3;
            }
            d=d+2;
            if(d==2){
                d=0;
            }
            else if(d==3){
                d=1;
            }
            nA+=dx[d];
            nB+=dy[d];
            if(land[nA][nB]==1){
                int sum=0;
                for(int i=0;i<N;i++){
                    for(int j=0;j<M;j++){
                        if(count[i][j]==1){
                            sum++;
                        }
                    }
                }
                cout<<sum<<endl;
                return 0;
            }
            A=nA;
            B=nB;
            continue;
        }
        nA+=dx[d];
        nB+=dy[d];
        if(count[nA][nB]==1){
            nA=A;
            nB=B;
            bulga++;
            continue;
        }
        else if(nA<0 || nA>N-1 || nB<0 || nB>M-1){
            nA=A;
            nB=B;
            bulga++;
            continue;
        }
        else if(land[nA][nB]==1){
            nA=A;
            nB=B;
            bulga++;
            continue;
        } else {
            A=nA;
            B=nB;
            count[A][B]=1;
            continue;
        }
    }
}
