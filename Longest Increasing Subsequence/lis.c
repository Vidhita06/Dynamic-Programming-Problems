#include<stdio.h>
#include<stdlib.h>
void lis(int arr[20],int size){
    int prev[size];
    int dp[size];
    int len,i,j;
    for(i=0;i<size;i++){
        dp[i]=1;
        prev[i]=-1;
    }
    for(i=1 ;i<size;i++){
        for(j=0;j<i;j++){
            if(arr[i] >arr[j]  && dp[i]<dp[j]+1){
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
    printf("Longest increasing subsequence: %d\n",maxL);
    printf("Subsequence: ");
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
    int size,i;
    printf("Enter the size of the array:\n");
    scanf("%d",&size);
    printf("Enter the array:\n");
    for(i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    lis(arr,size);
    return 0;
}