#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

int cutString(string p){
    int left=0;
    int right=0;
    for(int i=0;i<p.length();i++){
        if(p[i]=='('){
            left++;
        } else {
            right++;
        }
        if(left==right){
            return i;
        }
    }
    return 0;
}

bool isright(string u){
    int right=0;
    int left=0;
    for(int i=u.length()-1;i>=0;i--){
        if(u[i]==')'){
            right++;
        }
        if(u[i]=='('){
            left++;
        }
        if(right<left){
            return false;
        }
    }
    return true;
}

string solution(string p) {
    if(p.length()==0){
        return "";
    }
    if(isright(p)){
        return p;
    }
    string answer = "";
    int cut=cutString(p);
    string u=p.substr(0,cut+1);
    string v;
    if(cut==p.length()-1){//v를 표현할 때 out_of_range에러방지
        v="";
    } else {
        v=p.substr(cut+1,1000);
    }
    if(isright(u)){//s가 올바른 괄호 문자열일 경우
        return u+solution(v);
    } else {
        string temp="(";
        temp+=solution(v);
        temp+=")";
        string new_u=u;
        string reversed_u;
        if(new_u.length()>=2){
            new_u.erase(0,1);
            new_u.erase(new_u.length()-1,1);
            for(int i=0;i<new_u.length();i++){
                if(new_u[i]=='('){
                    reversed_u+=')';
                } else {
                    reversed_u+='(';
                }
            }
        }
        temp+=reversed_u;
        return temp;
    }
}

int main(){
    string p;
    cin>>p;
    p=solution(p);
    for(int i=0;i<p.length();i++){
        cout<<p[i];
    }
    cout<<endl;
}
