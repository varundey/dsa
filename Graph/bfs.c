#include <stdio.h>
#include <stdlib.h>

int MAX=6;

struct Vertex {
        char label;
        int visited;
};

struct Vertex* vertices[6];
int adjMatrix[6][6];
int noOfVertices = 0;
int queue[6];
int REAR = -1;
int FRONT = 0;

void enqueue(int data) {
        queue[++REAR] = data;
}

int dequeue() {
        return queue[FRONT++];
}

int isQueueEmpty() {
        if (FRONT < 0 || FRONT > REAR) {
                return 0;
        }
        return 1;
}

void addVertex(char label) {
        struct Vertex* vertex = (struct Vertex*) malloc(sizeof(struct Vertex));
        vertex->label = label;
        vertex->visited = 0;
        vertices[noOfVertices++] = vertex;
}

void addEdge(int start,int end) {
        adjMatrix[start][end] = 1;
        adjMatrix[end][start] = 1;
}

void displayVertex(int i) {
        printf("%c ",vertices[i]->label);
}

int getAdjUnvisitedVertex(int i) {
        int j;
        for(j = 0; j < noOfVertices; j++) {
                if(adjMatrix[i][j] == 1 && vertices[j]->visited == 0) {
                        return j;
                }
        }
        return -1;
}

void breadthFirstSearch() {
        int i;
        vertices[0]->visited = 1;
        displayVertex(0);
        enqueue(0);
        int unvisitedVertex;
        while(isQueueEmpty() > 0) {
                int tempVertex = dequeue();
                while((unvisitedVertex = getAdjUnvisitedVertex(tempVertex)) != -1) {
                        vertices[unvisitedVertex]->visited = 1;
                        displayVertex(unvisitedVertex);
                        enqueue(unvisitedVertex);
                }
        }
        for(i = 0; i < noOfVertices; i++) {
                vertices[i]->visited = 0;
        }
}


int main() {
        int i, j;
        for(i = 0; i<MAX; i++) {
                for(j = 0; j<MAX; j++) {
                        adjMatrix[i][j] = 0;
                }
        }
        addVertex('A'); //0
        addVertex('B'); //1
        addVertex('C'); //2
        addVertex('D'); //3
        addVertex('E'); //4
        addVertex('F'); //5
        /*
              THE GRAPH
                   A
                /  |  \
              /   D    \
            B           E
         |           |
            C           F
         */
        addEdge(0, 1); //A - B
        addEdge(1, 2); //B - C
        addEdge(0, 3); //A - D
        addEdge(0, 4); //A - E
        addEdge(4, 5); //E - F
        printf("Depth First Search: ");
        breadthFirstSearch();
        return 0;
}
