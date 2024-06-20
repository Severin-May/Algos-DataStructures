def selectionSort(array):
  size = len(array)
  min = 0

  for i in range(0, size - 1):
    min = i

    for j in range(i+1, size):
      if array[j] < array[min]:
        min = j

    array[min], array[i] = array[i], array[min]

  for i in range (0, size):
    print(array[i])

array = [1,7,4,9,2,3]

selectionSort(array)
