#include <stdio.h>


void mergeSort(int A[], int n);
void ms(int A[], int B[], int u, int v);
void merge(int A[], int B[], int u, int m,  int v);

int main(void) {

  int A[10] = {1,6,5,3,8,9,0,2,7,4};
  int n = sizeof(A)/sizeof(A[0]); 
  mergeSort(A, n);
  for(int i = 0; i < n; i++) {
    printf("%d ", A[i]);
  }
  
  return 0;
}

void mergeSort(int A[], int n) {
  int B[10];
  
  for(int i = 0; i < n; i++) {
    B[i] = A[i];
  }  

  ms(B, A, 0, n);
}

void ms(int B[], int A[], int u, int v) {
  int m;
  if(v - u > 1) {
    m = (u+v)/2;
    ms(A, B, u, m);
    ms(A, B, m, v);
    merge(B, A, u, m, v);
  }
}


void merge(int B[], int A[], int u, int m,  int v) {
  int k = u; 
  int i = u;
  int j = m;

  while(i < m && j < v) {
    if(B[i] <= B[j]) {
      A[k] = B[i];
      i++;
    }
    else {
      A[k] = B[j];
      j++;
    }
    k++;
  }

  if(i < m) {
    int p = i;
    for(int l = k; l < v && p < m; l++) {
      A[l] = B[p];
      p++;
    }
  }
  else {
    int p = j;
    for(int l = k; l < v && p < v; l++) {
      A[l] = B[p];
      p++;
    }
  }
}

