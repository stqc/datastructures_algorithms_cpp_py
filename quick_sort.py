x=[3,12,1,5,0,99,76,12,90,-1]


def quick_sort(x):
    if len(x)>1: #if the length of the list is greater than 1 then..
        i=1
        j=1
        pivot = x[0] #setting pivot as the first value of the list
        
        while j<len(x): #while the value of j is less than the length of the list
            if x[j]<pivot: 
                temp = x[j]
                x[j] = x[i] #if jth value of the list is less than the pivot then we swap the ith value with jth value
                x[i] = temp # and incrememt both i and j
                i+=1
                j+=1    
            elif x[j]>=pivot:#if jth value is greater than or equal to pivot we increment j
                j+=1
        x.insert(i-1,x.pop(0)) #putting the pivot in it's correct position
        
        x[:i]=quick_sort(x[:i])#recursive call on the left side of the pivot
        x[i:]=quick_sort(x[i:])#recursive call on the right side of the pivot
    return x
        
        
print(quick_sort(x))
