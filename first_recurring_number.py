x = list(map(int,input().split())) # input array elements

seen = dict() #create an empty dict

for i in x: #loop through all elements in x
    if seen.get(i)!=None: # if the key exists in dict print i
        print(i)
        break # and break
    else: # else insert the key,value pair in the dict
        seen[i]=True
print(seen)
