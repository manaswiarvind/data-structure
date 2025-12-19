#include<stdio.h>
#include<stdlib.h>

#define MAX 20

void bfs(int am[20][20], int src, int n, int visited[], int order[],int *ordercount){
    int front=0;
    int rear=0;
    int q[n];

    for(int i=0; i<n; i++){
        visited[i]=0;
    }

    q[rear++]=src;
    visited[src]=1;
    *ordercount=0;

    while(front<rear){
        int u=q[front++];
        order[(*ordercount)++]=u;

        for (int v=0; v<n; v++){
            if (am[u][v]==1 && !visited[v]==1){
                visited[v]=1;
                q[rear++]=v;
            }
        }

    }
}

int main(){
    int am[20][20];
    int src;
    int n;
    int ordercount;
    printf("Enter number of vertices:");
    scanf("%d", &n);
    int visited[n];
    int order[n];
    printf("Enter adjacency matrix:\n");
    for (int i=0; i<n;i++){
        for (int j=0; j<n;j++){
            scanf("%d", &am[i][j]);
        }
    }
    printf("Enter src vertex:");
    scanf("%d", &src);

    bfs(am, src, n, visited, order, &ordercount);

    printf("\nBFS traversal order:\n");
    for (int i = 0; i < ordercount; i++)
        printf("%d ", order[i]);

    printf("\n\nReachability from vertex %d:\n", src);
    for (int i = 0; i < n; i++)
    {
        if (visited[i])
            printf("Vertex %d:Reachable\n", i);
        else
            printf("Vertex %d:Not reachable\n", i);
    }

    return 0;
}