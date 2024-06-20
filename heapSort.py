def heapify(array, n, i):
  largest = i
  left = 2*i+1
  right = 2*i+2

  if left < n and array[left] > array[largest]:
    largest = left

  if right < n and array[right] > array[largest]:
    largest = right

  if largest != i:
    array[i], array[largest] = array[largest], array[i]
    heapify(array, n, largest)
  

def heapSort(arr):
  #building maxHeap
  n = len(arr)

  for i in range(n//2, -1, -1):
    heapify(arr, n, i)
  
  for i in range(n-1, 0, -1):
    arr[i], arr[0] = arr[0], arr[i]

    heapify(arr, i, 0)

  # for i in range(n):
  #   print(arr[i])


myarr = [1,8,4,3,5]
heapSort(myarr)
    
