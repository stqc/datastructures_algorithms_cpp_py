#include<iostream>
using namespace std;
class linked{
public:
    int data;
    linked *next;
};

void fill_list(linked *node){

for (int i =0; i <10; i ++){
    cin>>node->data;
    linked *new_node = new linked();
    node->next = new_node;
    node = node->next;
}

}

void print(linked *node){
    cout<<node->data<<"->";
    node = node->next;
    while(true){
        cout<<node->data<<"->";
        node=node->next;
        if(!node->next){
            break;
        }
    }

}
void reverse_list(linked **node){

    linked *first= *node; // pointer first points to the pointer of node
    linked *second = first->next; // pointer second points to first->next
    linked *third = second->next; // pointer third points to second->next



    while(second->next){ //loop till second->next is not null
        first->next = third; // first-> next now points to third
        second->next = *node; // second->next now points to the head node
        *node=second; // pointer node which is the pointer to head now points to second
        second = third; // second is now third
        third = third->next; // third is now third->next

    }

}

int main(){

linked *node = new linked();

fill_list(node);
cout<<"Before Reversing\n\n";
print(node);
reverse_list(&node);
cout<<"\n\nAfter Reversing\n\n";
print(node);
cout<<"\n";

}
