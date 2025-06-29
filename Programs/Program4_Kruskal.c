#include<stdio.h>

int parent[10];
int cost[10][10];
int mincost = 0;
int n; 

int find(int i){
    while(parent[i])
        i = parent[i];
    return i;
}

int main() {

    int i , j , u , v, a , b, min , ne = 1;

    printf("Enter the number of vertices : ");
    scanf("%d",&n);

    printf("Enter the cost Matrix of the graph : \n");
    for(i = 1 ; i <= n ; i++){
        for(j = 1 ; j <= n ; j++){
            scanf("%d",&cost[i][j]);
            if(cost[i][j]== 0)
                cost[i][j] = 999;
        }
    }

    printf("The edges of the Minimum spanning tree are :\n");

    while(ne < n){
        min = 999;

        for(i = 1 ; i <= n ; i++){
            for(j = 1 ; j <= n ; j++){
                if(cost[i][j] < min){
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        // check if both u & v are the same 
        if(u != v){
            parent[v] = u;
            printf("%d \t Edge(%d,%d) = %d \n",ne++,a,b,min);
            mincost += min;
        }

        cost[a][b] = cost[b][a] = 999;
    }
    
    printf("The minimum Cost Spanning Tree : %d \n" , mincost);

    return 0;
}