#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(pair<string,int> a, pair<string,int> b){
    return a.second<b.second;
}

int main(){
    string name;
    int score;
    int n;
    cin>>n;
    vector<pair<string,int>> student;
    for(int i=0;i<n;i++){
        cin>>name>>score;
        student.push_back(make_pair(name,score));
    }
    sort(student.begin(),student.end(),compare);
    for(int i=0;i<n;i++){
        cout<<student[i].first<<" ";
    }
    cout<<endl;
}
