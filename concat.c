#include<stdio.h>
#include<stdlib.h>

struct Node{
int data;
struct Node* next;
};

struct Node* temp=NULL;

struct Node* head=NULL;
struct Node* head1=NULL;
struct Node* head2=NULL;
struct Node* last=NULL;


struct Node* insertbeg(struct Node* head,int val){
    struct Node* newnode=NULL;
    newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=val;
    newnode->next=NULL;
if(head==NULL){
    head=newnode;
}
else{
    newnode->next=head;
    head=newnode;
}
return head;
}

struct Node* insertend(struct Node* head,int val){
struct Node* newnode=NULL;
    newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=val;
    newnode->next=NULL;
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
return head;
}

struct Node* insertatpos(struct Node* head,int val,int pos){
struct Node* newnode=NULL;
    newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=val;
    newnode->next=NULL;
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
return head;
}

void display(struct Node* head){
temp=head;
while(temp!=NULL){
    printf("%d ",temp->data);
    temp=temp->next;
}
}

struct Node* concat(struct Node* head1,struct Node* head2){
 temp=head1;
 while(temp->next!=NULL){
  temp=temp->next;
 }
 temp->next=head2;
 return head1;
}

int main(){
int choice;
int val;
int pos;
while(1){
    printf("enter choice 1 in beginning 2 in end 3 at pos 4 display 5 exit 6 concat\n");
scanf("%d",&choice);
switch(choice){
case 1:
    printf("enter value to be inserted at beginning for n1\n");
    scanf("%d",&val);
    head1=insertbeg(head1,val);
    printf("enter value to be inserted at beginning for n2\n");
    scanf("%d",&val);
    head2=insertbeg(head2,val);
    break;
case 2:
    printf("enter value to be inserted at end of n1\n");
    scanf("%d",&val);
    head1=insertend(head1,val);
     printf("enter value to be inserted at end of n2\n");
    scanf("%d",&val);
    head2=insertend(head2,val);
    break;
case 3:
    printf("enter value to be inserted at a position for n1\n");
    scanf("%d",&val);
    printf("enter position\n");
    scanf("%d",&pos);
    head1=insertatpos(head1,val,pos);
    printf("enter value to be inserted at a position for n2\n");
    scanf("%d",&val);
    printf("enter position\n");
    scanf("%d",&pos);
    head2=insertatpos(head2,val,pos);
    break;
case 4:
    display(head1);
    printf("\n");
    display(head2);
    printf("\n");
    break;
case 5:
    return 0;
    break;
case 6:
    head1=concat(head1,head2);  
    break;  
}
}
}
