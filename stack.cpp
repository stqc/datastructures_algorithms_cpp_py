#include<iostream>

using namespace std;

class stacks{
public:
    int data;
    stacks *next;
};

void push(stacks *s, int data){

    if(!s->data){
        s->data = data;
        s->next = NULL;
    }
    else{
        stacks *temp = new stacks();
        temp->data = s->data;
        temp->next = s->next;
        s->data = data;
        s->next = temp;
    }
}

void pop(stacks *s){

    stacks *temp = new stacks();
    temp = s->next;
    s->data = temp->data;
    s->next = temp->next;
}

void display(stacks *s){

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
