#include<stdio.h>

struct Node{
    int data;
    struct Node* next;
};
struct Node* head=NULL;
struct Node* head1=NULL;
struct Node* head2=NULL;
struct Node* newnode=NULL;
struct Node* temp=NULL;

void createnode(int val){
    newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=val;
newnode->next=NULL;
}
struct Node* insertatbeg(int val,struct Node* head){
    createnode(val);
    if(head==NULL){
        head=newnode;
    }
    else{
        newnode->next=head;
        head=newnode;
    }
    return head;
}

struct Node* deleteatbeg(struct Node* head){
    if(head==NULL){
        printf("empty\n");
    }
    else if(head->next==NULL){
        free(head);
        head=NULL;
    }
    else{
        temp=head;
        head=head->next;
        free(temp);
    }
    return head;
}

struct Node* insertatend(int val,struct Node* head){
    createnode(val);
    if(head==NULL){
        head=newnode;
    }
    else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
    return head;
}

void display(struct Node* head){
    temp=head;
    if(head==NULL){
        printf("empty\n");
    }
    else{
        while(temp!=NULL){
            printf("%d",temp->data);
            temp=temp->next;
        }
    }
}

int main(){
    int val;
    int choice;
    while(1){
        printf("enter a choice 1.insert in stack 2.delete from stack 3. insert in queue 4.delete from stack 5. display stack 6.display queue 7.exit\n");
        scanf("%d",&choice);
    switch(choice){
        case 1: printf("enter a value\n");
            scanf("%d",&val);
            head1=insertatbeg(val,head1);
            break;

        case 2:head1=deleteatbeg(head1);
                break;

        case 3:printf("enter a value\n");
                scanf("%d",&val);
                head2=insertatend(val,head2);     
                break;
        case 4:head2=deleteatbeg(head2);
                break;
                
        case 5:  display(head1);
                    break;   
        case 6: display(head2);
                    break;
        case 7:return 0;
    }
    }

}

