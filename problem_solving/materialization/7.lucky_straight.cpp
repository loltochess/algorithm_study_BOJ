#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int sum(string str){
    int total=0; 
    for(int i=0;i<str.length();i++){
        total+=str[i]-'0';
    }
    return total;
}

int main(){
    string s;
    cin>>s;
    string left=s.substr(0,s.length()/2);
    string right=s.substr(s.length()/2,s.length()/2);
    if(sum(left)==sum(right)){
        cout<<"LUCKY"<<endl;
    } else {
        cout<<"READY"<<endl;
    }
    return 0;
}
