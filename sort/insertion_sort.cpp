#include <iostream>

using namespace std;

int array[10]={7,5,9,0,3,1,6,2,4,8};

int main(){
    for(int i=1;i<10;i++){
        for(int j=0;j<i;j++){
            if(array[i]<array[j]){
                int temp=array[i];
                array[i]=array[j];
                array[j]=temp;
            }
        }
    }
    for(int i=0;i<10;i++){
        cout<<array[i]<<endl;
    }
}
