#include <stdio.h>
#include <stdlib.h>

// A utility function to create a new queue node.
typedef struct QNode {
   int vertex;
   struct QNode* next;
} QNode;

// A utility function to create an empty queue.
typedef struct Queue {
   QNode* front;
   QNode* rear;
} Queue;

// A utility function to create a new queue node.
QNode* newQNode(int vertex) {
   QNode* qnode = (QNode*)malloc(sizeof(QNode));
   qnode->vertex = vertex;
   qnode->next = NULL;
   return qnode;
}

// A utility function to create an empty queue.
Queue* createQueue() {
   Queue* queue = (Queue*)malloc(sizeof(Queue));
   queue->front = queue->rear = NULL;
   return queue;
}

// A utility function to check if the queue is empty.
int isEmpty(Queue* queue) {
   return queue->front == NULL;
}

// A utility function to add a new vertex to the queue.
void enqueue(Queue* queue, int vertex) {
   QNode* qnode = newQNode(vertex);

   if (isEmpty(queue)) {
       queue->front = queue->rear = qnode;
       return;
   }

   queue->rear->next = qnode;
   queue->rear = qnode;
}

// A utility function to remove the front vertex from the queue.
int dequeue(Queue* queue) {
   if (isEmpty(queue)) {
       return -1;
   }

   QNode* qnode = queue->front;
   int vertex = qnode->vertex;
   queue->front = qnode->next;

   if (isEmpty(queue)) {
       queue->rear = NULL;
   }

   free(qnode);
   return vertex;
}

// A utility function to perform the BFS traversal.
void BFS(int** graph, int numVertices, int startVertex) {
   Queue* queue = createQueue();
   int* visited = (int*)malloc(numVertices * sizeof(int));

   for (int i = 0; i < numVertices; i++) {
       visited[i] = 0;
   }

   enqueue(queue, startVertex);
   visited[startVertex] = 1;

   while (!isEmpty(queue)) {
       int vertex = dequeue(queue);
       printf("%d ", vertex);

       for (int i = 0; i < numVertices; i++) {
           if (graph[vertex][i] && !visited[i]) {
               enqueue(queue, i);
               visited[i] = 1;
           }
       }
   }

   free(visited);
   free(queue);
}

int main() {
   int numVertices, numEdges;

   printf("Enter the number of vertices: ");
   scanf("%d", &numVertices);

   printf("Enter the number of edges: ");
   scanf("%d", &numEdges);

   int** graph = (int**)malloc(numVertices * sizeof(int*));

   for (int i = 0; i < numVertices; i++) {
       graph[i] = (int*)malloc(numVertices * sizeof(int));
   }

   // initialize the adjacency matrix with 0
   for (int i = 0; i < numVertices; i++) {
       for (int j = 0; j < numVertices; j++) {
           graph[i][j] = 0;
       }
   }

   printf("Enter the edges (vertex pair) one by one:\n");
   for (int i = 0; i < numEdges; i++) {
       int u, v;
       scanf("%d %d", &u, &v);
       graph[u][v] = 1;
       graph[v][u] = 1;
   }

   int startVertex;
   printf("Enter the start vertex: ");
   scanf("%d", &startVertex);

   printf("Breadth First Search traversal of the graph is:\n");
   BFS(graph, numVertices, startVertex);

   for (int i = 0; i < numVertices; i++) {
       free(graph[i]);
   }

   free(graph);

   return 0;
}
