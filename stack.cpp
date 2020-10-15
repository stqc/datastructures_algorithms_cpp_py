/*Stacks using linked lists*/

#include<iostream>

using namespace std;
//The stack class
class stacks{ 
public:
    int data;
    stacks *next;
};

void push(stacks *s, int data){ //Push method

    if(!s->data){ // if the stack is empty
        s->data = data;
        s->next = NULL;
    }
    else{ // if the stack is not empty
        stacks *temp = new stacks();
        temp->data = s->data;
        temp->next = s->next;
        s->data = data; 
        s->next = temp;
    }
}

void pop(stacks *s){ // pop method

    stacks *temp = new stacks();
    temp = s->next;
    s->data = temp->data;
    s->next = temp->next;
}

void display(stacks *s){ // display the stack

    while(true){
        cout<<s->data<<endl;
        s= s->next;
        if(!s){
            break;
        }
    }
}

int main(){

    stacks *st = new stacks();
    cout<<"-------PUSH---------\n";
    push(st,23);
    display(st);
    cout<<"-------PUSH---------\n";
    push(st,11);
    display(st);
    cout<<"-------PUSH---------\n";
    push(st,69);
    display(st);
    cout<<"--------POP---------\n";
    pop(st);
    display(st);
    cout<<"--------POP---------\n";
    pop(st);
    display(st);

}
