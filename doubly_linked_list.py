class node: # Node class
    def __init__(self,data,previous,next):
        self.data = data
        self.previous  = previous
        self.next = next

class doubly_list: #doubly linked list head
    def __init__(self):
        self.head = None

l = doubly_list() #new doubly linked list

def insert_at_start(data,linked): #insertion at the start of the list
    if linked.head is None: #if the list is empty
        linked.head = node(data=data, previous = None, next = None) #assign head as new Node
    else: #if the list is not empty
        temp = linked.head #set a temporary variable as head
        linked.head = node(data=data,previous=None,next = temp) #change the value of the head  and change next to temp
        temp.previous = linked.head # setting previous value of temp as the new head


def insert_at_end(data,linked): #insertion at the end
    if linked.head is None: #if the list is empty
        linked.head = node(data,prvious=None,next=None) #assign head a new node
    else: #if the list is not empty
        temp = linked.head #set temp as the head
        while temp.next is not None: #traverse till temp.next is not None
            temp = temp.next
        temp.next = node(data=data,previous=temp,next=None) #set temp.next to a new Node

def insert_at_index(data,linked,index):# insertion at an index
    if linked.head is None: #if the list is empty
        linked.head = node(data=data,previous=None,next=None) #assign head a new Node
    else:#if the list is not empty
        count =1 #set the counter to 1
        s = linked.head #set s as the head of the list
        while count<index and s.next is not None: #loop till count is less than index and s.next is not None
            s = s.next #set s to s.next
            count+=1 #increment count
        if s.previous is None: #if s.previous is None
            insert_at_start(data,linked) #insert value at the start
        elif s.next is None: #if s.next if None
            insert_at_end(data,linked) #insert at the end
        else: #lastly if above conditions fail
            temp = s.previous #set temp to s.previous
            temp.next = node(data=data,next=s,previous=temp) #assign temp.next to a new node
            s.previous = temp.next #set s.previous to temp.next

def delete_from_start(linked): #delete from the start
    if linked.head is None: #if the list is empty
        print('Nothing to delete')
    else: #if the list is not empty
        linked.head = linked.head.next #set liked.head to linked.head.next
        linked.head.previous = None #and set linked.head.previous to None

def delete_from_end(linked): #delete from the end
    if linked.head is None: #if list is empty
        print("Nothing to delete")
    else:#if list is not empty
        s = linked.head # set s as head
        while s.next is not None: #loop till s.next is not None
            s = s.next #set s to s.next
        s = s.previous #set to s.previous
        s.next = None #set s.next to None

def delete_at_index(linked,index): #delete at an index
    if linked.head is None: #if list is empty
        print('Nothing to delete')
    else:#if list is not empty
        count = 1 #set counter to 1
        s = linked.head #set s as head
        while count < index and s.next is not None: #loop till count is less than index and s.next is not None
            s = s.next #set s to next
            count+=1#increment count
        if s.next is None: #if s.next is None
                delete_from_end(linked) #delete from the end
        elif s.previous is None: #if s.previous is None
            delete_from_start(linked) #delete from the start
        else: # if above conditions fail
                temp = s.next #set temp to s.next
                temp.previous = s.previous #set temp.previous to s.previous
                s.previous.next = temp #set the next of previous node to temp


def traverse(linked): #traverse
    s= linked.head
    print("Traversal from head to tail")
    while s.next is not None:
        print(s.data)
        s = s.next
    print(s.data)
    print("Traversal from tail to head")
    while s.previous is not None:
        print(s.data)
        s = s.previous
    print(s.data)

print("======================insertion============================")
insert_at_start(34,l)
insert_at_start(45,l)
insert_at_start(89,l)
insert_at_end(69,l)
insert_at_index(99,l,2)
insert_at_index(13,l,9)
traverse(l)
print("======================Deletion============================")
delete_from_start(l)
delete_from_end(l)
delete_at_index(l,3)
traverse(l)
