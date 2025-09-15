#include<stdio.h>
#include<stdlib.h>
void sort(int arr[20],int size){
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-1-i;j++){
            if(arr[j]>arr[j+1]){
                int temp= arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void lds(int arr[20],int size){
    sort(arr,size);
    int i,j;
    int dp[size];
    int prev[size];
    for(i=0;i<size;i++){
        dp[i]=1;
        prev[i]=-1;
    }
    for(i=1;i<size;i++){
        for(j=0;j<i;j++){
            if((arr[i] % arr[j]==0) && dp[i]<dp[j]+1){
                dp[i]=dp[j]+1;
                prev[i]=j;
            }
        }
    }
    int maxL=dp[0];
    int max_idx=0;
    for(i=0;i<size;i++){
        if(maxL<dp[i]){
            maxL=dp[i];
            max_idx=i;

        }
    }
    printf("Longest Divisible Subset Length: %d\n",maxL);
    printf("Longest Divisible Subset: ");
    int k=max_idx;
    i=maxL-1;
    int seq[size];
    while(k!=-1){ 
        seq[i]=arr[k];
        i--;
        k=prev[k];     
    }
    for(j=0;j<maxL;j++){
        printf("%d ",seq[j]);
    }
}

int main(){
    int arr[20];
    int size,i,j;
    printf("Enter the size of array:\n");
    scanf("%d",&size);
    printf("Enter the array:\n");
    for(i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    lds(arr,size);
    return 0;
}
