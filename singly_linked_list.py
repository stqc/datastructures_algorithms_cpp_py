class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class linked_list():
    def __init__(self):
        self.head = None

x = linked_list()

def insert_begining(linked, data): #insert at the start
    z = Node(data)
    temp = linked.head
    linked.head = z
    linked.head.next = temp
    return linked

def insert_end(linked,data): #insert at end
    if linked.head is None:
        linked.head = Node(data)
        return linked
    else:
        temp = linked.head
        while temp.next is not None:
             temp = temp.next
        temp.next = Node(data)
        return linked

def insert_at(index,linked,data): #insert at an index
    if linked.head is None:
        linked.head = Node(data)
    else:
        s = linked.head
        x = 1
        while x<index and s.next:
            s= s.next
            x+=1
        temp = s.next
        s.next = Node(data)
        s.next.next = temp
    return linked

def traverse(linked):
    if  linked.head is None:
        print("Nothing to print here")
    elif linked.head.next is None:
        print(linked.head.data)
    else:
        s = linked.head
        while s.next:
            print(s.data)
            s = s.next
            if s.next is None:
                print(s.data)

def delete_from_beg(linked): #delete from the start
    linked.head = linked.head.next
    return linked

def delete_from_end(linked): #delete from the end
    if linked.head.next is None:
        linked.head = None
        return linked
    elif linked.head is None:
        print('list empty')

    else:
        s = linked.head
        while s.next.next is not None:
            s = s.next

        s.next = None
        return linked

def delete_at(index,linked): #delete from an index
    if linked.head is None:
        print('Nothing to delete here')
    elif linked.head.next is None:
        linked.head = None
        return linked
    else:
        x =1
        s = linked.head
        while x< index and s.next:
            s = s.next
            x+=1
        s.next = s.next.next

        return linked


x = insert_begining(x,9)
x = insert_end(x,25)
x = insert_begining(x,19)
x = insert_end(x,199)
x = insert_at(9,x,69)
x = insert_end(x,420)
traverse(x)
print('---------------')
x = delete_at(4,x)
#x = delete_from_beg(x)
#x = delete_from_end(x)
traverse(x)
