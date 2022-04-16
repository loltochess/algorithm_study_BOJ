#include <iostream>

using namespace std;

int array[]={7,5,9,0,3,1,6,2,4,8};
int main(){
    for(int i=0;i<sizeof(array)/sizeof(int);i++){
        int min=100001;
        int index;
        for(int j=i+1;j<sizeof(array)/sizeof(int);j++){
            if(min>array[j]){
                min=array[j];
                index=j;
            }
        }
        int temp=array[i];
        array[i]=array[index];
        array[index]=temp;
    }
    for(int i=0;i<sizeof(array)/sizeof(int);i++){
        cout<<array[i]<<endl;
    }
}
