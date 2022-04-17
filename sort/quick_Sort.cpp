#include <iostream>

using namespace std;


int array[10]={5,8,9,1,3,2,4,6,0,7};
int number=10;
int temp;

void qSort(int *data,int start,int end){
    if(start>=end){
        return;
    }

    int i=start+1;
    int j=end;
    int temp=0;
    while(i<=j){
        while(i<=end && data[i]<=data[start]){
            i++;
        }
        while(j>start && data[j]>=data[start]){
            j--;
        }
        if(i>j){
            temp=data[start];
            data[start]=data[j];
            data[j]=temp;    
        } else {
            temp=data[j];
            data[j]=data[i];
            data[i]=temp;
        }
    }
    qSort(data,start,j-1);
    qSort(data,j+1,end);
}


int main(){
    qSort(array,0,number-1);
    for(int i=0;i<number;i++){
        cout<<array[i]<<endl;
    }
}
