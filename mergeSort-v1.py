def mergeSort(A):
    n = len(A)
    B = [0 for i in range(n)]
    for i in range(0, n):
        B[i] = A[i]

    ms(B, A, 0, n)
    # print(A)


def ms(B, A, l, r):
    # print(l)
    # print(' :left and right: ')
    # print(r)
    if r - l > 1:
        m = l + (r - l) // 2
        # print('m: ')
        # print(m)
        ms(A, B, l, m)
        ms(A, B, m, r)
        merge(B, A, l, m, r)


def merge(B, A, l, m, r):
    i = k = l
    j = m
    print(l,m,r)
    while i < m and j < r:
        if B[i] <= B[j]:
            A[k] = B[i]
            print(str(B[i]) + ' <= ' + str(B[j]))
            i = i + 1
            print(str(A[k]) + ' k: ' + str(k))
        else:
            A[k] = B[j]
            print(str(B[i]) + ' > ' + str(B[j]))
            j = j + 1
            print(str(A[k]) + ' k: ' + str(k))
        k = k + 1

    if i < m:
        for l in range(k, r):
            A[l] = B[i]
            i = i + 1
            print('loop i < m')
            print(str(A[l]) + ' k: ' + str(l))
    else:
        for l in range(k, r):
            A[l] = B[j]
            j = j + 1
            print('loop i >= m')
            print(str(A[l]) + ' k: ' + str(l))
    print(B)

myarr = [4, 3, 2, 9, 8, 4]
mergeSort(myarr)
