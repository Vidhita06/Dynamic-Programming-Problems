#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void multi(int n,int cost[][15],int stages){
    int bcost[n+1];
    int d[n+1];
    int p[stages+1];
    int j,l;
    
    bcost[0]=0;
    bcost[1]=0;
    d[0]=0;
    d[1]=1;
    for(int i=2;i<=n;i++){
        d[i]=-1;
    }
    int min;
    for(j=2;j<=n;j++){
        min=INT_MAX;
        for(l=j-1;l>=1;l--){
            if(cost[l][j]!=0 && (bcost[l]+cost[l][j] < min)){
                min=bcost[l]+cost[l][j];         
                d[j]=l;
            }
        }
        bcost[j]=min;
    }
    p[0]=0;
    p[1]=1;
    p[stages]=n;
    for(j=stages-1;j>=2;j--){
        p[j]=d[p[j+1]];
    }
    printf("                 Minimum path sum: %d\n",bcost[n]);
    printf("                 PATH: ");
    for(j=1;j<=stages;j++){
        printf(" %d ",p[j]);
    }
}
int main(){
int cost[15][15] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
    {0, 0, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 3, 2, 5, 0, 0, 0, 0, 0, 0, 0, 0}, 
    {0, 0, 0, 0, 0, 0, 0, 3, 2, 0, 0, 0, 0, 0, 0}, 
    {0, 0, 0, 0, 0, 0, 0, 0, 3, 2, 0, 0, 0, 0, 0}, 
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 3, 0, 0, 0, 0}, 
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0}, 
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 0, 0}, 
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 4, 0}, 
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 5, 0}, 
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3}, 
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2}, 
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4}, 
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}   
};
    int n=14; 
    int stages=6;
    printf("\n||-----------------MULTI STAGE GRAPH------------------||\n");
    multi(n,cost,stages);
    printf("\n||----------------------------------------------------||\n");
    return 0;
}