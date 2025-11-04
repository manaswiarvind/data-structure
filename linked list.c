#include<stdio.h>

struct Node{
int data;
struct Node* next;
};

struct Node* temp=NULL;
struct Node* newnode=NULL;
struct Node* head=NULL;
struct Node* last=NULL;

void createnode(int val){
    newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=val;
    newnode->next=NULL;
}

void insertbeg(int val){
    createnode(val);
if(head==NULL){
    head=newnode;
}
else{
    newnode->next=head;
    head=newnode;
}
}

void insertend(int val){
createnode(val);
if(head==NULL){
    head=newnode;
}
else{
    last=head;
    while(last->next!=NULL){
        last=last->next;
    }
    last->next=newnode;
}
}

void insertatpos(int val,int pos){
createnode(val);
if(head==NULL){
    head=newnode;
}
else{
    temp=head;
    for(int i=1;i<pos;i++){
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}
}

void display(){
temp=head;
while(temp!=NULL){
    printf("%d\n",temp->data);
    temp=temp->next;
}
}

int main(){
insertbeg(4);
insertbeg(5);
insertend(10);
insertend(12);
insertatpos(100,2);
display();
}
