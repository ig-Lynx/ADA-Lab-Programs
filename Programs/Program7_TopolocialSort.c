
#include<stdio.h>
#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int order[MAX];
int index_end;
int n;

void DFS(int v){
    visited[v]= 1;

    for(int i = 0 ; i < n ; i++){
        if(adj[v][i] && !visited[i]){
            DFS(i);
        }
    }
    order[--index_end] = v;
}

void topological_sort(){
    index_end = n;

    for(int i= 0 ; i < n ; i++){
        visited[i] = 0;
    }

    for(int i = 0 ; i < n ; i++){
        if(!visited[i]){
            DFS(i);
        }
    }
}

int main() {
    int i , j;

    printf("Enter the numbber of vertices : ");
    scanf("%d",&n);

    printf("Adj mAtrix \n");
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            scanf("%d",&adj[i][j]);
        }
    }

    topological_sort();

    printf("Topological Order : ");
    for(int i = 0 ; i < n ; i++){
        printf("%d \t",order[i]);
    }
    printf("\n");

    return 0;
}

