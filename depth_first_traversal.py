class node():
    def __init__(self,value,left=None,right=None):
        self.value = value
        self.left = left
        self.right = right

class tree():
    def __init__(self, value):
        self.head = node(value)
        self.temp = self.head
    def insert_value(self,value):

        if self.temp.value > value:
            if self.temp.left:
                self.temp = self.temp.left
                self.insert_value(value)
            else:
                self.temp.left = node(value)
                self.temp = self.head
        else:
            if self.temp.right:
                self.temp = self.temp.right
                self.insert_value(value)
            else:
                self.temp.right = node(value)
                self.temp = self.head
    def show(self,n,level=1):
        if n:
            self.show(n.left,level+4)
            print(' '*level,'->',n.value)
            self.show(n.right,level+4)
        else:
            return None

    def dft(self,node,value,parent):
        print(node.value)
        if node.left and node.right:
                    self.dft(parent=node,node = node.left,value = value)
                    self.dft(parent=node,node = node.right,value = value)
        else:
                if node.left:
                    self.dft(parent=node,node = node.left,value = value)
                if node.right:
                    self.dft(parent=node,node = node.right,value = value)




tr = tree(100)
tr.insert_value(10)
tr.insert_value(101)
tr.insert_value(1001)
tr.insert_value(2000)
tr.insert_value(999)
tr.insert_value(900)
tr.insert_value(11)
tr.insert_value(1)
tr.show(tr.head)
tr.dft(value=1  ,node=tr.head,parent=tr.head)
