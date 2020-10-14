class node: #Node class
    def __init__(self,data,next=None):
        self.data = data
        self.next = next

class stack: #Stack class
    def __init__(self):
        self.head = None

test_stack = stack()

def push(stack,data): #Push method
    if stack.head is None: #if stack is empty
        stack.head = node(data = data) #create a new node for head
    else: #if stack is not empty
        temp = stack.head # store the current top value in temp
        stack.head = node(data=data,next = temp) #set stack head to a new Node

def pop(stack): #Pop method
    if stack.head is None: #if stack is empty
        print("Stack is empty")
    else: #if stack is not empty
        stack.head = stack.head.next #set stack head to stack.next

def show_stack(stack): #print the Stack
    if stack.head is None:
        print("Stack Empty")
    else:
        j=stack.head
        while True:
            print(j.data)
            j = j.next
            if not j:
                break

def peek(stack): #peek
    if stack.head is None:
        print("Stack empty")
    else:
        print(stack.head.data)

push(test_stack,12)
push(test_stack,33)
push(test_stack,3)
push(test_stack,69)
show_stack(test_stack)

print("----PEEK----")
peek(test_stack)

print("----POP----")
pop(test_stack)
show_stack(test_stack)

print("----PEEK----")
peek(test_stack)
