
#include<stdio.h>

int max(int a , int b){ return (a >b)? a : b ;}

int Knapsack(int W , int Wt[], int val[], int n){
    int i ,w ;

    // create DP table
    int K[n+1][W+1];

    for( i = 0 ; i <= n ; i++){
        for( w = 0 ; w <= W ; w++){
            if(i == 0 || w == 0)
                K[i][w] = 0;
            else if(Wt[i-1] <= w){
                K[i][w] = max(val[i-1]+K[i-1][w-Wt[i-1]],K[i-1][w]);
            }
            else
                K[i][w] = K[i-1][w];
        }
    }

    return K[n][W];
}

int main(){

    int i , n , W;
    int val[20], Wt[20];

    printf("Enter the number of Elements : ");
    scanf("%d",&n);

    printf("Enter the Value and Weights : ");
    for(i = 0 ; i < n ; i++){
        scanf("%d %d",&val[i],&Wt[i]);
    }

    printf("Enter the KnapSack Capacity : ");
    scanf("%d",&W);

    printf("Max Value : %d \n",Knapsack(W,Wt,val,n));

    return 0;
}