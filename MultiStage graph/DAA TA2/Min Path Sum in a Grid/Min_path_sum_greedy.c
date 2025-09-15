//Q4 MINIMUM PATH SUM IN A GRID (USING GREEDY APPROCH)
//Q4 MINIMUM PATH SUM IN A GRID (USING GREEDY APPROCH)

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void min_path_sum_greedy(int m,int n,int arr[m][n]){
    int i,j;
    int sum=0;
    sum=arr[0][0];
    i=0,j=0;
    while(i < m-1 || j < n-1){
        if(i==m-1){
            j++;
        }
        else if(j==n-1){
            i++;
        }
        else{
            if(arr[i][j+1] < arr[i+1][j] ){
                j++;
            }
            else{
                i++;
            }
        }
        sum+=arr[i][j];    
    }
    printf("-----------------------------------------------\n");
    printf("Minimum Path Sum(Using Greedy Approach): %d\n",sum);
    printf("-----------------------------------------------");
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
    min_path_sum_greedy(m,n,arr);
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void min_path_sum_greedy(int m,int n,int arr[m][n]){
    int i,j;
    int sum=0;
    sum=arr[0][0];
    i=0,j=0;
    while(i < m-1 || j < n-1){
        if(i==m-1){
            j++;
        }
        else if(j==n-1){
            i++;
        }
        else{
            if(arr[i][j+1] < arr[i+1][j] ){
                j++;
            }
            else{
                i++;
            }
        }
        sum+=arr[i][j];    
    }
    printf("-----------------------------------------------\n");
    printf("Minimum Path Sum(Using Greedy Approach): %d\n",sum);
    printf("-----------------------------------------------");
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
    min_path_sum_greedy(m,n,arr);
    return 0;
}