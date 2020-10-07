#include<iostream>
using namespace std;
class doubly_linked_list{

public:
    doubly_linked_list *prev;
    doubly_linked_list *next;
    int data;
};
doubly_linked_list *last = new doubly_linked_list();

int display_head_to_tail(doubly_linked_list *node){
    cout<<node->data<<"->";
    node= node->next;
    while(true){
        cout<<"<-"<<node->data<<"->";
        node = node ->next;
        if(!node->next){
            cout<<"<-"<<node->data;
            break;
        }
    }

return 0;

}

int display_tail_to_head(doubly_linked_list *node){
    node = last;
    cout<<node->data<<"->";
    node = node->prev;
    while(true){
        cout<<"<-"<<node->data<<"->";
        node = node->prev;
        if(!node->prev){
            cout<<"<-"<<node->data;
            break;
        }

    }
    return 0;
}

void insert_at_start(doubly_linked_list *node,int data){

   if (node->data == NULL){
    node->data = data;
    node->next = NULL;
    node -> prev = NULL;
    last = node;
   }
   else{
    doubly_linked_list *new_node = new doubly_linked_list();
    new_node->data = node->data;
    new_node->next = node->next;
    node->data = data;
    node->next = new_node;
    new_node->prev = node;
   }
}

void insert_at_end(doubly_linked_list *node,int data){

    if(node->data==NULL){
        node->data= data;
        node->next = NULL;
        node->prev = NULL;
        last = node;
    }
    else{
        while(node->next){
            node = node->next;
        }
    doubly_linked_list *new_node = new doubly_linked_list();
    new_node->data = data;
    new_node->prev = node;
    node->next = new_node;
    new_node->next = NULL;
    last = new_node;
    }
}

void insert_at_index(doubly_linked_list *node, int data, int index){

    if (node->data==NULL){
        node->data = data;
        node->next = NULL;
        node->prev = NULL;
        last = node;
    }
    else{
        int counter = 1;

        while(counter<index && node->next){
            node = node->next;
            counter++;
        }
        if (!node->prev){
            insert_at_start(node,data);
        }
        else if (!node->next){
            insert_at_end(node,data);
        }
        else{
            doubly_linked_list *new_node = new doubly_linked_list();

            new_node->data = data;
            new_node->prev = node->prev;
            new_node->next = node;
            node->prev->next = new_node;
            node->prev = new_node;
        }
    }

}

void delete_start(doubly_linked_list *node){

    doubly_linked_list *new_node = new doubly_linked_list();
    node->data = node->next->data;
    node->next = node->next->next;
    node->next->prev = node;

}

void delete_end(doubly_linked_list *node){

    while(node->next){
        node = node->next;
    }
    node = node->prev;
    node->next = NULL;
    last = node;
}

void delete_at_index(doubly_linked_list *node, int index){

int    counter = 1;
    while(counter<index && node->next){
        node=node->next;
        counter++;
    }
    if(!node->prev){
        delete_start(node);
    }
    else if(!node->next){
        delete_end(node);
    }
    else{
        doubly_linked_list *new_node = new doubly_linked_list();

        new_node = node;
        node = node->prev;
        node->next = new_node->next;
        node = node->next;
        node->prev = new_node->prev;
    }
}

int main(){
doubly_linked_list *s = new doubly_linked_list();

insert_at_start(s,45);
insert_at_start(s,76);
insert_at_end(s,56);
insert_at_end(s,98);
insert_at_index(s,10,3);
insert_at_index(s,10,2);
display_head_to_tail(s);
cout<<"\n";
display_tail_to_head(s);
cout<<"\nDeletion";
cout<<"\n";
delete_start(s);
cout<<"===============================================\n";
display_head_to_tail(s);
cout<<"\n";
display_tail_to_head(s);
cout<<"\n";
delete_end(s);
cout<<"===============================================\n";
display_head_to_tail(s);
cout<<"\n";
display_tail_to_head(s);
cout<<"\n===============================================";
delete_at_index(s,2);
cout<<"\n";
display_head_to_tail(s);
cout<<"\n";
display_tail_to_head(s);


}
