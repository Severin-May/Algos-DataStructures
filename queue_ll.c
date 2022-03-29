#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
  
struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node Node;

struct Queue {
    int n;
    struct Node *first;
    struct Node *tail;
};

typedef struct Queue queue;

struct Queue *construct_queue() {
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->n = 0;
    Node *p = (Node*)malloc(sizeof(Node)) ;
    q->tail = p ;
    q->first =  p;
    return q;
}

void set_empty(struct Queue *q) {

  Node *temp;
  while( q->first != q->tail )
    {
      temp = q->first;
      q->first = q->first->next;
      free (temp);
    }
  q->n = 0;
}

void desctruct_queue(struct Queue **q) {

  set_empty(*q);
  free ((*q)->first);
  free ((*q));
  *q = NULL;
}

int length(struct Queue *q)
{
  return q->n; 
}

void add(struct Queue *q, int new_data)
{
    Node *p = (Node*)malloc(sizeof(Node)) ;
    q->tail->data = new_data;
    q->n = q->n + 1;
    q->tail->next = p;
    q->tail = p;
    // q->tail->next = NULL;
}

int rem(struct Queue *q)
{
    if((q)->first == (q)->tail) {
        printf("Queue Underflow!\n");
    }
    else {
        int x = (q)->first->data;
        Node *p = (q)->first ;
        (q)->n = (q)->n - 1;
        (q)->first = (q)->first->next;
        free(p);
        return x;
    }
}

void print_queue(struct Queue *q)
{
  Node *temp = q->first;
  for(int i = 0; i < q->n; i++)
  {
    printf ("%d ", temp->data);
    temp = temp -> next;
  }
    printf("\n");
}

int main() 
{

  struct Queue *myQueue = construct_queue(myQueue);
  add(myQueue, 3);
  add(myQueue, 8);
  add(myQueue, 9);
  add(myQueue, 11);
  print_queue(myQueue);
  printf("The size is %d \n", length(myQueue));
  
  rem(myQueue);
  rem(myQueue);
  rem(myQueue);
  rem(myQueue);
  printf("The size is %d \n", length(myQueue));
  print_queue(myQueue);
  

  desctruct_queue(&myQueue);
  print_queue(myQueue);
  
  return 0;
}

// gcc queue_ll.c
// .\a.exe