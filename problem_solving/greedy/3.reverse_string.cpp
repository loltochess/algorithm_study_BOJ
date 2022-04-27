#include <iostream>

using namespace std;

int main(){
    string s;
    cin>>s;
    int change_count=0;
    for(int i=0;i<s.length()-1;i++){
        if((int)s[i]!=(int)s[i+1]){
            change_count++;
        }
    }
    cout<<change_count/2<<endl;
}
