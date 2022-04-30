#include <string>
#include <vector>


using namespace std;

int solution(string s) {
    if(s.length()==1){
        return 1;
    }
    int i=0;
    int cut=1;
    int min=1001;
    string now;
    string next;
    int count=1;
    string new_str;
    while(cut<=s.length()/2){
        new_str="";
        int i=0;
        while(i<=s.length()-cut){
            now=s.substr(i,cut);
            next=s.substr(i+cut,cut);
            if(now==next){
                count++;
            } else if(count>1){
                new_str.append(to_string(count));
                new_str+=now;
                count=1;
            } else {
                new_str+=now;
            }
            i+=cut;
        }
        if(count>1){
            new_str.append(to_string(count));
            new_str+=now;
        } else {
            new_str+=next;
        }
        if(new_str.length()<min){
            min=new_str.length();
        }
        cut++;
    }
    return min;
}
