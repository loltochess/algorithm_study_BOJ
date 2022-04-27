#include <iostream>
#include <vector>

using namespace std;

int main(){
    string s;
    cin>>s;
    vector<int> v;
    for(int i=0;i<s.length();i++){
        v.push_back(s[i]-'0');
    }
    vector<int>::iterator it=v.begin();
    while(it!=v.end()){
        *(it+1)=max(*it+*(it+1),*it**(it+1));
        it++;
    }
    cout<<*(--it)<<endl;
}
