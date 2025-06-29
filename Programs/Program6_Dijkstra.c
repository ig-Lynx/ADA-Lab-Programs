
#include<stdio.h>
#include<stdbool.h>
#include<limits.h>

#define MAX_VERTICES 1000
#define INF INT_MAX

int graph[MAX_VERTICES][MAX_VERTICES];
bool visited[MAX_VERTICES];
int distance[MAX_VERTICES];

int num_vertices;

int get_min_distance_vertex(){
    int min_dist = INF;
    int min_vertex = -1;

    for(int i = 0 ; i < num_vertices ; i++){
        if(!visited[i]&& distance[i]<min_dist){
            min_dist = distance[i];
            min_vertex = i;
        }
    }
    return min_vertex;
}

void dijkstra(int start_vertex){

    for(int i = 0 ; i < num_vertices ; i++){
        distance[i] = INF;
        visited[i]= false;
    }

    distance[start_vertex] = 0;

    for(int i = 0 ; i < num_vertices-1 ; i++){
        int current_index = get_min_distance_vertex();
        if(current_index == -1) break;
        visited[current_index] = true;
        for(int j = 0 ; j < num_vertices ; j++){
            if(!visited[j] && graph[current_index][j]){
                int new_distance = distance[current_index]+graph[current_index][j];
                if(new_distance < distance[j]){
                    distance[j] = new_distance;
                }
            }
        }
    }
}

int main(){
    int num_edges;
    int start_vertex;

    printf("Enter the numebr of vertex : ");
    scanf("%d",&num_vertices);

    printf("Enter the number of edges:");
    scanf("%d",&num_edges);

    for(int i = 0 ; i < num_vertices ; i++){
        for(int j = 0 ; j < num_vertices ; j++){
            graph[i][j] = 0;
        }
    }

    printf("Enter the weight of edges : \n");
    for(int i = 0 ; i < num_edges ; i++){
        int u , v , w;
        printf("Edge %d(u,v,w) :",i+1);
        scanf("%d %d %d",&u,&v,&w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    printf("Enter the start veterx : ");
    scanf("%d",&start_vertex);

    dijkstra(start_vertex);

    printf("The shortest distance from start vertex : %d \n", start_vertex);
    for(int i = 0 ; i < num_vertices ; i++){
        printf("Vertex %d : ",i);
        if(distance[i] == INF){
            printf("inf\n");
        }else{
            printf("%d \n",distance[i]);
        }
    }

    return 0;
}