#include<iostream>

using namespace std;

class linked_list{ // the linked list class

public:
    int data; // data item
    linked_list* next; // reference to another instance of the class

};

int insert_end(linked_list* node, int data){ // insert at the end

    if (node ->data == NULL){ // if list is empty insert at the start
        node->data = data;
        node->next = NULL;
    }

    else{ // else
        linked_list *new_node = new linked_list(); // make a new node
        new_node->data = data; // set new node -> data to data
        new_node->next = NULL; // set new node -> next to next
        while(node->next!=NULL){ // while node next is not null
            node = node->next; // change current node to next
        }

        node->next=new_node; // change the last node's next to next node
    }

    return 1;
}
int insert_beg(linked_list* node, int data){ // insert at the start
    if (node->data == NULL){ // if node-> data is null

        node->data = data; // set node -> data  to data
        node->next = NULL; // and node -> next to null
    }
    else{ // else
        linked_list *new_node = new linked_list(); // make a new node
        new_node ->data = node ->data; //set it's data and next to first node's data and next
        new_node ->next = node->next;
        node->data = data; // set first node's data to data
        node->next = new_node; // set first node's next to next node
    }
    return 0;
}
int insert_at(linked_list* node, int index, int data){ // insert element at an index

    if(node->data == NULL){ // if list is empty insert at first element
        node ->data = data;
        node -> next = NULL;
    }
    else{ // else run a loop till x is less than index and node->next is not null
        int x = 1;
        while(x<index && node->next!=NULL){
            node = node -> next;
            x++;
        }
        linked_list *nn = new linked_list(); // create a new node
        if (node->next == NULL){ // if node-> next is null insert at the end
            nn  ->data = data;
            nn->next = NULL;
            node->next = nn;
        }
        else{ // else insert at the required index
        nn->data = node->data;
        nn->next = node->next;
        node->data = data;
        node->next = nn;
        }
    }

}

void print(linked_list* node){ // method to print the list

    while(node!=NULL){
        cout<<node->data<<"->";
        node = node->next;
    }
    cout<<"\n";
}
void delete_at(linked_list *node, int index){ // method to delete at an index

    if (index==1){ // if index is 1 remove the first node
        linked_list *nn = new linked_list();
        nn= node->next;
        node ->data = nn ->data;
        node ->next = nn->next;
    }
    else{ // else run a loop till x is less than index -1
    int x = 1;
    while (x<index-1){
        node = node -> next; // set current node to next
        x+=1;
    }
    node->next = node->next->next;} // set current node's next to next node's next
}

void delete_beg(linked_list *node){ // method to delete from the start
        linked_list *nn = new linked_list(); // making a new node
        nn= node->next; // set new node to current node's  next
        node ->data = nn ->data; // change current node to new node
        node ->next = nn->next;
}
void delete_end(linked_list *node){ // method to delete at the end

    while( node->next->next != NULL){ // loop runs till the next node's next is NULL
        node = node->next; // change current node to next node
    }
    node->next = NULL; // set node's next to null
}

int main(){
    linked_list* s = new linked_list();
    // insertion
    cout<<"Inserting\n\n";
    insert_beg(s,67);
    print(s);
    insert_beg(s,267);
    print(s);
    insert_end(s,9);
    print(s);
    insert_at(s,9,99);
    print(s);
    insert_at(s,3,0);
    //print
    print(s);
    //deletion
    cout<<"\nDeleting\n\n";
    print(s);
    delete_at(s,1);
    print(s);
    delete_beg(s);
    print(s);
    delete_end(s);
    print(s);
    delete_end(s);
    print(s);
}
