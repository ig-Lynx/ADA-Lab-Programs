#include<stdio.h>

int main(){

    int cost[10][10] , visited[10],n;

    int i , j , ne = 1;
    int min , a, b , u ,v;
    int mincost = 0;

    printf("Enter the nummber of Vertices : ");
    scanf("%d",&n);

    printf("Enter the cost adajancey matrix (0 for no edge) : \n");
    for(i = 1 ; i<= n ; i++){
        for(j = 1 ; j<= n ; j++){
            scanf("%d",&cost[i][j]);
            if(cost[i][j] == 0)
                cost[i][j] = 999;
        }
        visited[i] = 0;
    }

    visited[1] = 1;

    printf("The minimum Spaning tree  \n");

    while(ne < n){
        min = 999;

        for(i = 1 ; i<= n ; i++){
            if(visited[i]){
                for(j = 1 ; j <= n ; j++){
                    if(!visited[j]&& cost[i][j] < min){
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        visited[b] = 1;

        printf("%d Edge (%d,%d) = %d \n",ne++,a,b,min);
        mincost += min;
    }

    printf("Mincost : %d \n",mincost);
    return 0;
}