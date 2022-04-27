#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> food_times, long long k) {
    int i=0;
    int time=0;
    int answer = 0;
    vector<int> :: iterator it=food_times.begin();
    int sum=0;
    for(int i=0;i<food_times.size();i++){
        sum+=food_times[i];
    }
    while(1){
        while(*it==0){
            it++;
            if(it==food_times.end()){
                it=food_times.begin();
            }
        }
        (*it)--;
        sum--;
        if(sum==0){
            return -1;
        }
        time++;
        if(time==k){
            it++;
            if(it==food_times.end()){
                it=food_times.begin();
            }
            while(*it==0){
            it++;
            if(it==food_times.end()){
                it=food_times.begin();
            }
            }
            
            answer=distance(food_times.begin(),it)+1;        
            return answer;
        }
        if(it==food_times.end()-1){
            it=food_times.begin();
            continue;
        }
        it++;
    }
}
