#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

void print_alpha(vector<char> v){
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        cout<<v[i];
    }
}

void print_num(vector<char> v){
    int sum=0;
    for(int i=0;i<v.size();i++){
        sum+=v[i]-'0';
    }
    cout<<sum;
}

int main(){
    string s;
    cin>>s;
    vector<char>alphabet;
    vector<char>number;
    for(int i=0;i<s.length();i++){
        if(s[i]>='A' && s[i]<='Z'){
            alphabet.push_back(s[i]);
        } else {
            number.push_back(s[i]);
        }
    }
    print_alpha(alphabet);
    print_num(number);
    cout<<"\n";
    return 0;
}
