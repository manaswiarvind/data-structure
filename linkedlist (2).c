#include<stdio.h>

struct Node{
int data;
struct Node* next;
};

struct Node* temp=NULL;
struct Node* newnode=NULL;
struct Node* head=NULL;
struct Node* last=NULL;
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

deletebeg(){
    if(head==NULL){
        printf("empty list\n");
        return;
    }
    else if(head->next==NULL){
        free(head);
        head=NULL;
    }
    else{
        temp=head;
        head=temp->next;
        free(temp);
    }
}

deleteend(){
    if(head==NULL){
        printf("empty\n");
        return;
    }
    else if(head->next==NULL){
        free(head);
        head=NULL;
    }
    else{
        temp=head;
        prev=NULL;
        while(temp->next!=NULL){
            prev=temp;
            temp=temp->next;
        }
        prev->next=NULL;
        free(temp);
    }
}

deleteatpos(int pos){
    if(head==NULL){
        printf("empty list\n");
        return;
    }
    else if(pos==1 && head->next==NULL){
        free(head);
        head=NULL;
    }
    else{
        prev=NULL;
        temp=head;
        for(int i=1;i<pos;i++){
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        free(temp);
    }
}

void display(){
temp=head;
while(temp!=NULL){
    printf("%d ",temp->data);
    temp=temp->next;
}
}

int main(){
int choice;
int val;
int pos;
while(1){
    printf("enter choice 1 insert in beginning 2. insert in end 3. insert at pos 4.delete at beg 5.delete at end 6.delete at pos 7. display 8. exit\n");
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
case 4:deletebeg();
        break;
case 5:deleteend();
        break;
case 6:deleteatpos(pos){
    printf("enter position\n");
    scanf("%d\n",&pos);
    break;
}    
case 7:
    display();
    break;
case 8:
    return 0;
    break;
}
}
}
