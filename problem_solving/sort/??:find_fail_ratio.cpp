#include <string>
    #include <vector>
    #include <algorithm>
    #include <iostream>

    using namespace std;

    bool compare(pair<double,int> a, pair<double,int> b){
        if(a.first==b.first){
            return a.second<b.second;
        }
        return a.first>b.first;
    }

    vector<int> solution(int N, vector<int> stages) {
        vector<pair<double,int>> answer;
        sort(stages.begin(),stages.end());
        int cleared=(int)stages.size();//클리어한 사람
        int last_cleared=0;//i번째 스테이지를 못 깬 사람
        int start_man=0;
        for(int i=1;i<=N;i++){
            for(int j=start_man;j<stages.size();j++){
                double sp=0;//실패율
                if(stages[j]==i) {
                    last_cleared++;
                } else {//stages[j]>i
                    sp=(double)last_cleared/(cleared-start_man);
                    start_man=j;//다음번엔 j부터 시작
                    answer.push_back({sp,i});
                    last_cleared=0;
                    break;
                }
            }
            if(last_cleared>0){
                double sp=(double)last_cleared/(cleared-start_man);
                answer.push_back({sp,i});
                last_cleared=0;
                for(int k=i+1;k<=N;k++){
                    answer.push_back({0,k});
                }
                break;
            }
        }
        sort(answer.begin(),answer.end(),compare);
        vector<int>real_answer;
        for(int i=0;i<answer.size();i++){
            real_answer.push_back(answer[i].second);
            cout<<answer[i].second<<endl;
        }
        return real_answer;
    }

    int main(){
        int N=5;
        vector<int>stages={4,4,4,4,4};
        solution(N,stages);
    }
