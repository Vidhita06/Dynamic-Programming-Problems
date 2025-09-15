//Q4 MINIMUM PATH SUM IN A GRID (USING NON-GREEDY APPROCH)
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void min_path_sum_non_greedy(int m,int n,int arr[m][n]){
    int dp[m][n];
    int up,left,i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(i==0 && j==0){
                dp[0][0]=arr[0][0];

            }
            else{
                up=arr[i][j];
                if(i>0){
                        up+=dp[i-1][j];
                }
                else{
                    up=INT_MAX;
                }
                left=arr[i][j];
                if(j>0){
                    left+=dp[i][j-1];
                }
                else{
                    left=INT_MAX;
                }
                if(up<left ){
                    dp[i][j]=up;
                }
                if(left<=up ){
                    dp[i][j]=left;
                }
            }
        }
    }
    printf("------------------------------------------------\n");
    printf("Minimum path sum(Using Non-Greedy Approach): %d\n",dp[m-1][n-1]);
    printf("------------------------------------------------\n");
}
int main(){
    int m,n;
    int arr[3][3]={
        {10,8,2},
        {10,5,100},
        {1,1,2}
    };
    m=3;
    n=3;
    min_path_sum_non_greedy(m,n,arr);
    return 0;
}