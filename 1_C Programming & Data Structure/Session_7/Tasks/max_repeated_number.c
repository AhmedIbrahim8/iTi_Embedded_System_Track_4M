#include<stdio.h>
int main(){
    int array[10]={1,2,3,2,3,3,7,9,4,4};
    int sum[10]={0};
    int index;
    int max=sum[0];
    int index_max;
    for(index=0;index<10;index++){
        sum[array[index]]++;
        if(sum[array[index]]>max){
            max=sum[array[index]];
            index_max=index;
            }
    }
    printf("Max repeated number = %d",array[index_max]);
    return 0; 
}