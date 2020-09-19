def quick_sort(x, low, high): #quick sort function using pivot as the 0th value in the list
    
    i = low 
    if low<high: #if low is less than high the following is performed
        for j in range(low,high): #main loop
                
                if x[j]<= x[low-1]: #if jth value of x i less than the pivot value
                    temp = x[i]     #we swap the ith value of the list with the jth value
                    x[i] = x[j]
                    x[j] = temp
                    i+=1
        
        temp = x[i-1] #and then we swap the i-1th value with the pivot value
        x[i-1] = x[low-1]
        x[low-1]=temp 
         
        quick_sort(x,low,i-1) #recursive calls on the left side of the list
        quick_sort(x,i+1,high) #recurssive call on the right side of the list
    
    return x

x=[3,12,1,5,0,99,76,12,90,-1,69]
print(f"before sorting: {x}")
x=quick_sort(x,1,len(x))

print(f"after sorting: {x}")
