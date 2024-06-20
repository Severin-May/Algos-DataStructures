def insertionSort(A):
  n = len(A)
  for i in range (1, n):
    if(A[i-1] > A[i]) :
        x = A[i]
        print("A[i]: ")
        print(A[i])
        A[i] = A[i-1] #A[i] = 6
        j = i - 2 #i=1, j = -1
        while j >= 0 and A[j] > x :
          A[j+1] = A[j]
          j = j - 1
        #A[-1+1]=2
        A[j+1] = x
  for i in range(n):
    print(A[i])


myarr = [4, 6, 2, 8, 5, 2]
insertionSort(myarr)
