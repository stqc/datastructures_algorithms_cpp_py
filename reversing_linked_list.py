class node: #Node class
    def __init__(self,data=None,next=None):
        self.data= data
        self.next = next

class linked_list: #linked list class
    def __init__(self,head=None):
        self.head = head


linked_list = linked_list() #a new linked list object

# inputting data
linked_list.head = node(data=input())
s = linked_list.head

for i in range(4):
    s.next = node(data=input())
    s = s.next

s = linked_list.head

print('------------------------pre-reverse--------------------------------')
while 1:
    print(s.data)
    s= s.next
    if not s:
        break

first = linked_list.head #reference to the initial head of the list
second = first.next #reference to the initial second element of the list
third = second.next #reference to the initial third element of the list

while second.next is not None: #loop till second.next is not None
    first.next = third #set first.next to third
    second.next = linked_list.head #set second.next to the current head value
    linked_list.head = second #change the current head value to second

    second = third #change second to third
    third = third.next #change third to third.next
#when the loop exits do the last swap
first.next = third #change first.next to third
second.next = linked_list.head #set second.next to current head
linked_list.head = second #set linked_list.head as second

s= linked_list.head
print('------------------------post-reverse--------------------------------')
while 1:
    print(s.data)
    s= s.next
    if not s:
        break
