array = [3, 7, 8, 0, 3, 2, 1, 7, 6]

def merge_sort(array):
    arlen  = len(array)
    left = array[:arlen//2]
    right = array[arlen//2:]
    if arlen>1:
         merge_sort(left)
    
         merge_sort(right)

    i=0
    j=0
    k=0
    while i<len(left) and j<len(right):
        if left[i] < right[j]:
            array[k] = left[i]
            i+=1
        else:
            array[k] = right[j]
            j+=1
        k+=1

    while i<len(left):
        array[k] = left[i]
        i+=1
        k+=1

    while j<len(right):
        array[k] = right[j]
        j+=1
        k+=1
    return array



print(array)
print(merge_sort(array))
