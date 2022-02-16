#include <stdio.h>
#include <stdlib.h>
/* "typedef" is used in order not to type "struct" keyword every time we create a Node 
   ex: without "typedef" we need to create new Node like this: struct Node *head = ...... 
   with the next line of code written, we can create Node as simply as Node *head = .....
*/

typedef struct Node Node; 
/*
    struct is our custom data structure, we need to construct Node which is not built-in in C
    similarly, we can construct other data types such as Stack, Queues and many more by using structs
*/
struct Node {
   int key;
   Node *next;
};  

/* 
    initializes the node by settig its key to given key and its next to NULL
*/
Node* init_node(Node* node, int key) {
    node->key = key;
    node->next = NULL;
    return node;
}


/*
    inserts a new element at the beginning of the list
    int a = 3;
    int* ptr = &a; ptr == &a;
    int** pptr = &ptr; pptr == &ptr;
*/
void insert_at_front(Node **L, int x) {
    Node *p = (Node*)malloc(sizeof(Node));
    p->key = x;
    p->next = *L;
    *L = p;
}

/*
    gets element at a given "index": there is no explicit indexing in the list,
    i - sequence number of an element, starting from zero
*/
Node* get_element(Node *L, int i) {
    Node *p = L;
    int j = 0;
    while(j < i) {
        j++;
        p = p->next;
    }
    return p;
}

/*
    deletes the very first node of the list, if the list is empty sends a warning
*/
void delete_first(Node **L) {
    if((*L) == NULL || L == NULL) { printf("The linked-list is empty or does not exist!"); }
    Node *p = *L;
    *L = (*L)->next;
    free(p);
}

/*
    deletes the next node of the given node
*/
void delete_next(Node *p) {
    if(p == NULL) printf("The linked-list is empty!");
    Node *q = (Node*)malloc(sizeof(Node));
    q = p->next;
    p->next = q->next;
    free(q);
}

/*
    insert a new node with key x next to the given node
*/
void append_next(Node *p, int x) {
    Node *q = (Node*)malloc(sizeof(Node));
    q->key = x;
    q->next = p->next;
    p->next = q;
}

void print_list (Node* L)
{
  //if(L->next == NULL) { printf("The linked-list is empty!"); }
  Node *temp = L;
  while(temp != NULL) 
  {
    printf("%d->", temp->key);
    temp = temp-> next;
  }
  printf ("NULL\n");
} 

int main() {
   Node *ll = (Node*)malloc(sizeof(Node));
   init_node(ll, 1);
   insert_at_front(&ll, 2);
   insert_at_front(&ll, 3);
   //printf("%d ", get_element(ll, 1)->key);
   print_list(ll);
//    delete_first(&ll);
//    delete_first(&ll);
//    delete_first(&ll);
//    delete_first(&ll);
   delete_next(ll);
//    delete_next(ll);
//    delete_next(ll); //segmentation fault
   append_next(ll, 4);
   print_list(ll);
   return 0;
}
