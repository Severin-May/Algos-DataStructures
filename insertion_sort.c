#include <stdio.h>

void insertionSort(int A[], int n);

int main(void) {
  int A[10] = {1,6,5,3,8,9,0,2,7,4};
  int n = sizeof(A)/sizeof(A[0]); 
  insertionSort(A, n);
  for(int i = 0; i < n; i++) {
    printf("%d ", A[i]);
  }
  return 0;
}

void insertionSort(int A[], int n) {
  
  for(int i = 1; i < n; i++) {
    int x;
      if(A[i-1] > A[i]) {
        x = A[i];
        A[i] = A[i-1];
        int j = i - 2;
        while(j >= 0 && A[j] > x) {
          A[j+1] = A[j];
          j--;
        }
        A[j+1] = x;
      }
  }
}