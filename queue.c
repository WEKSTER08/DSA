    #include <stdio.h>
#include<stdlib.h>		
#include<limits.h>
//creating a structure for stack;
struct Queue { 
    int front, rear, size; 
    unsigned capacity; 
    int* array; 
}; 

struct Queue* makeq(unsigned a)
{
    //alloting space in memory;
	struct Queue* q1 = (struct Queue*)malloc(sizeof(struct Queue*));
    //intializing the parameters;
	q1->capacity=a;
	q1->front=q1->size=0;
	q1->rear=a-1;
	q1->array=(int*)malloc(q1->capacity*sizeof(int*));
	return q1;

}
int isFull(struct Queue* queue) 
{ 
    return (queue->size == queue->capacity); 
} 
int isEmpty(struct Queue* queue) 
{ 
    return (queue->size == 0); 
} 
void enqueue(struct Queue* queue, int item) 
{ 
    if (isFull(queue)) 
        return; 
    //so as to have the correct array location
    queue->rear = (queue->rear + 1) 
                  % queue->capacity; 
    // enqueuing happens
    queue->array[queue->rear] = item; 
    queue->size = queue->size + 1;     
}
int dequeue(struct Queue* queue) 
{ 
    if (isEmpty(queue)) 
        return INT_MIN; 
    int item = queue->array[queue->front]; 
    //updating the front adress;
    queue->front = (queue->front + 1) 
                   % queue->capacity; 
    queue->size = queue->size - 1; 
    printf("%d ",item); 
} 

int main(int argc, char const *argv[])
{
	struct Queue* queue = makeq(100); 
  	for(int i=0;i<argc-1;i++)
    	enqueue(queue, atoi(argv[i+1]));
    for(int i=0;i<argc-1;i++)
    	dequeue(queue); 
    
    return 0; 
}