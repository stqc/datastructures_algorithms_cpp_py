#node class
class node:
    def __init__(self,data):
        self.data = data
        self.left = None
        self.right = None
#tree class
class btree:
    def __init__(self,element):
        self.head = node(element) #initialise the tree with a node
        self.temp = self.head #creating a temporary reference to the head

    def insert_element(self,element): #method to insert a new node
            if self.temp.data > element: #if the data in temp is greater than the elment to add
                if self.temp.left: #if left node is not null
                    self.temp=self.temp.left #set temp to left 
                    self.insert_element(element)#recuresive call to the insert_element method
                else:#if left is empty
                    self.temp.left = node(element)#assign a new node to left
            else:#if the element to add is smaller than the element in head
                if self.temp.right:#if the right node is not empty
                    self.temp=self.temp.right#set temp to right
                    self.insert_element(element)#recuresive call to the insert_element method
                else:#if right node is empty
                    self.temp.right = node(element)#assign a new node to right
            self.temp=self.head#reset temp to head

#method to remove element from the tree
def remove_element(tree,element,parent=None):#parameters: the tree , element to remove , parent(default to none)
    if tree.data == element:#if the element is found
        if not tree.left and not tree.right: #if the node containing the element is a leaf node
            tree = None#set the node to None/null
        elif not tree.left: #else if left node doesn't exist
            succ = tree.right #successor is set to tree.right
            tree = succ #remove and replace the node with successor node
            if parent:#if parent is not none
                    if element > parent.data:#if parent data is less than element
                        parent.right = succ# right of parent becomes the successor
                    else:#else
                        parent.left = succ#left of parent is the successor
        elif not tree.right: #same as above but if right node doesn't exist
            succ = tree.left
            tree = succ
            if parent:
                    if element > parent.data:
                        parent.right = succ
                    else:
                        parent.left = succ
        else:#if both right and left node exist
            right = tree.right#set right to tree's right node
            if right.left:#if left node of right exists
                p = right
                while right.left:#loop till right's left node is none
                    p= right #set p to right
                    right = right.left#set right to the left of current right node
                    
                p.left =None #set current right node's left to none since it'll be replacing the deleted node


            tree.data = right.data#replace the element to be deleted with the leftmost element of the right most sub-tree


        if parent:
                if element > parent.data:
                    parent.right = tree
                else:
                    parent.left = tree

    else:#if element is not found
        if tree.data > element: #if element is smaller than current node
            temp = tree.left #set temp to left of tree
            remove_element(temp,element,parent=tree)#recuresive call to remove_element (parameters: tree,element,parent )
        elif tree.data<element:#same as above if thr element to delete is larger
            temp = tree.right
            remove_element(temp,element,parent=tree)




tr = btree(100)


def show_tree(tree, level):#method to show the tree
    if tree is None:
        return None
    else:
        show_tree(tree.right, level+4)

        print(' '* level+"->",tree.data)

        show_tree(tree.left, level+4)

tr.insert_element(50)
tr.insert_element(200)
tr.insert_element(25)
tr.insert_element(210)
tr.insert_element(30)
tr.insert_element(190)
tr.insert_element(35)
tr.insert_element(23)
tr.insert_element(56)
tr.insert_element(29)
tr.insert_element(33)
tr.insert_element(47)
tr.insert_element(78)
tr.insert_element(115)
tr.insert_element(28)
tr.insert_element(52)
show_tree(tr.head,0)
print('\n____________')
remove_element(tree=tr.head,element=100)
show_tree(tr.head,0)
