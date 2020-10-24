#include<iostream>

using namespace std;
//tree class
class tree{

    public:
        int data; //data
        tree *left; // left node
        tree *right; // right node

        tree(int a){
        this->data = a;
        this->left = NULL;
        this->right = NULL;
        }
};

void insert_into_tree(int element, tree *t){ //method to insert a node into the tree
    if (t->data>element){ // if the data in the current node is greater than the element to be inserted
        if(t->left){ //if the left node exists
            insert_into_tree(element,t->left);//recursive call to the insertion method
        }
        else{ // if left node doesn't exist
            tree *temp = new tree(element); // create a new node
            t->left=temp; // assign t's left to new node
        }
    }
    else{ // if element is greater than t's data
        if(t->right){ //if right exists
            insert_into_tree(element,t->right);//recursive call to method
        }
        else{ // if right node doesn't exist
            tree *temp = new tree(element); // create  a new node
            t->right=temp; // set the right of current node to new node
        }
    }
}
void remove_from_tree(int element, tree *t, tree *parent= NULL){ // removing a node from the tree
    if(t->data == element){// if the element is found
        if (!t->left && !t->right){ // if the element is a leaf node
            if(parent){
                if(element>parent->data){
                    parent->right=NULL; // remove the right node of the parent if the element is greater than the parent
                }
                else{ //else
                    parent->left = NULL; // remove the left node of the parent if the element is smaller than the parent
                }
            }
        }
        else if(!t->left && t->right){ //  else if left node does'nt exist but right does
                t->data = t->right->data; // replace the node to be deleted with the right node
                t->left = t->right->left;
                t->right = t->right->right;
        }
        else if(t->left && !t->right){ // else if the right node doesn't exist but the left does
                t->data = t->left->data; // replace the node to be deleted with the left node
                t->left = t->left->left;
                t->right = t->left->right;
        }
        else if(t->left && t->right){// if both left and right node exist
            tree *right = t->right; // create a new tree pointer and assign it the right value of current node
            tree *ref_right = right;// and another tree pointer and assign it to right
            if (right->left){ // if left node of right exists
            while(right->left){//loop till there is no more left
                ref_right = right; //set ref_right to right
                right = right->left; // set right to left of right
            }
            ref_right->left=NULL; //remove the left node(it is the one we will replace the deleted node with)
            t->data = right->data;//replace the deleted node data
            }
            else{ //if left of right doesn't exist
                t->data = t->left->data; //replace current node with it's left node
                t->left = NULL;
            }
        }
    }
    else{ // if element is not found
        if(element>t->data){ // if element to delete is greater than the current node
            remove_from_tree(element,t->right,t); //recursive call on the right side of the node
        }
        else{ //else
            remove_from_tree(element,t->left,t); // recursive call on the left side of the node
        }
    }
}
void show_tree(tree *t,int level =0){
if(!t){
cout<<"";
}
else{
    show_tree(t->right,level+4);
    for(int i=0; i <level; i++){
        cout<<" ";

    }
    cout<<"->"<<t->data<<"\n";
    show_tree(t->left,level+4);

}

}
int main(){
tree *node = new tree(56);

insert_into_tree(23,node);
insert_into_tree(90,node);
insert_into_tree(120,node);
insert_into_tree(70,node);
insert_into_tree(30,node);
insert_into_tree(10,node);
insert_into_tree(240,node);
show_tree(node);
cout<<"==============Removed 240=================\n";

remove_from_tree(240,node);
show_tree(node);
cout<<"==============Removed 23=================\n";

remove_from_tree(23,node);
show_tree(node);
cout<<"==============Removed 56=================\n";

remove_from_tree(56,node);
show_tree(node);
}
