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
    if allocation of the memory is not possible, i.e. there is no space in the memory,
    push function sends an error message "Stack Overflow" and returns 1
    push works even when the stack is empty
*/
int push(Node **s, int new_data)
{
    Node *p = (Node*)malloc(sizeof(Node)) ;
    if(p==NULL) {
        printf("Stack Overflow");
        return 1;
    }
    p->data = new_data;
    p->next = *s;
    *s = p;
    return 0;
}

/*
    pop function gives an error message if stack is empty
    otherwise, it returns the key of the topmost element of a stack
    AND deletes it
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

/*
    top function gives an error message if stack is empty
    otherwise, it returns the key of the topmost element of a stack
    BUT does not delete it like pop function
*/
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

/* 
    returns the size of the stack
*/
int size(Node *s)
{
  int cnt = 0;
  while(s != NULL)
  { 
      cnt++;
      s = s->next;
  }
  return cnt; 
}

/* 
    displays the stack elements
*/
void print_stack(Node *s)
{
  while(!isEmpty(s))
  {
    printf("%d->", s->data);
    s = s->next;
  }
    printf("NULL\n");
}

int main() 
{

  Node *myStack = NULL;
  push(&myStack, 3);
  push(&myStack, 8);
  push(&myStack, 9);
  push(&myStack, 11);
  printf("The size is %d \n", size(myStack));
  print_stack(myStack);
  pop(&myStack);
  pop(&myStack);
  pop(&myStack);
  pop(&myStack);
  printf("The size is %d \n", size(myStack));
  print_stack(myStack);

  return 0;
}

// for cmd execution:
// gcc stack.c
// .\a.exe