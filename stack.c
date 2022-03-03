#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
  
struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node Node;

int isEmpty(Node *s)
{
  return s == NULL; 
}

/*
    push works even when the stack is empty
*/
void push(Node **s, int new_data)
{
    Node *p = (Node*)malloc(sizeof(Node)) ;
    p->data = new_data;
    p->next = *s;
    *s = p;
}

/*
    pop raises an error if it is empty
*/
int pop(Node **s)
{
    if(!isEmpty(*(s))) {
        Node *p = *s;
        int x = p->data;
        *s = p->next;
        free(p);
        return x;
    }
    else {
        printf("Stack Underflow!\n");
    }
}

int top(Node **s) {

    if(!isEmpty(*(s))) {
        Node *p = *s;
        int x = p->data;
        return x;
    }
    else {
        printf("Stack Underflow!\n");
    }
}

int count(Node *s)
{
  int cnt = 0;
  while(s != NULL)
  { 
      cnt++;
      s = s->next;
  }
  return cnt; 
}

void print_stack(Node *s)
{
  while(s != NULL)
  {
    printf("%d ", s->data);
    s = s->next;
  }
    printf("\n");
}

int main() 
{

  Node *myStack = NULL;
  push(&myStack, 3);
  push(&myStack, 8);
  push(&myStack, 9);
  push(&myStack, 11);
  print_stack(myStack);
  printf("The size is %d \n", count(myStack));
  pop(&myStack);
  pop(&myStack);
  pop(&myStack);
  pop(&myStack);
  print_stack(myStack);
  printf("The size is %d \n", count(myStack));

  return 0;
}

// gcc stack.c
// .\a.exe