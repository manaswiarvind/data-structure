#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node* next;
};

struct Node* temp=NULL;
struct Node* newnode=NULL;
struct Node* head=NULL;
struct Node* last=NULL;
struct Node* next=NULL;
struct Node* current=NULL;
struct Node* prev=NULL;

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
    printf("%d ",temp->data);
    temp=temp->next;
}
}

void reverse(){
  prev=NULL;
  current=head;
  next=NULL;
  while(current!=NULL){
    next=current->next;
    current->next=prev;
    prev=current;
    current=next;
  }
  head=prev;        
}

int main(){
int choice;
int val;
int pos;
while(1){
    printf("enter choice 1 in beginning 2 in end 3 at pos 4 display 5 exit 6 reverse\n");
scanf("%d",&choice);
switch(choice){
case 1:
    printf("enter value to be inserted at beginning\n");
    scanf("%d",&val);
    insertbeg(val);
    break;
case 2:
    printf("enter value to be inserted at end\n");
    scanf("%d",&val);
    insertend(val);
    break;
case 3:
    printf("enter value to be inserted at a position\n");
    scanf("%d",&val);
    printf("enter position\n");
    scanf("%d",&pos);
    insertatpos(val,pos);
    break;
case 4:
    display();
    break;
case 5:
    return 0;
    break;
case 6:
    reverse();
}
}
}
