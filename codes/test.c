#include <stdio.h>
#define INFINITY 9999
#define MAX 10

void dijkstra(int G[MAX][MAX], int n, int startnode){
    int cost[MAX][MAX], distance[MAX], visited[MAX], pred[MAX];
    int mindistance, nextNode;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cost[i][j] = (G[i][j] == 0) ? INFINITY : G[i][j];

    for(int i = 0; i < n; i++){
        distance[i] = cost[startnode][i];
        pred[i] = startnode;
        visited[i] = 0;
    }

    distance[startnode] = 0;
    visited[startnode] = 1;

    int count = 1;
    while(count < n-1){
        mindistance = INFINITY;

        for(int i = 0; i < n; i++)
            if(!visited[i] && distance[i] < mindistance){
                mindistance = distance[i];
                nextNode = i;
            }

        visited[nextNode] = 1;

        for(int i = 0; i < n; i++)
            if(!visited[i] && mindistance + cost[nextNode] < distance[i]){
                distance[i] = mindistance + cost[nextNode];
                pred[i] = nextNode;
            }

        count++;
    }

    

}

int main(){

    return 0;
}