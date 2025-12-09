#include<stdio.h>

typedef struct ListNode{
    int data;
    struct ListNode* left;
    struct ListNode* right;
}Node;

Node* createNode(int value){
    Node* newnode=(Node*)malloc(sizeof(Node));
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

void insertNode(Node* newnode,Node* root){
    if(newnode->data<root->data){
        if(root->left!=NULL){
            insertNode(newnode,root->left);
        }
        else{
            root->left=newnode;
        }
    }
    else{
        if(root->right!=NULL){
            insertNode(newnode,root->right);
        }
        else{
            root->right=newnode;
        }
    }
}

void inorder(Node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
   }
}

void postorder(Node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
                printf("%d ",root->data);
   }
}

void preorder(Node* root){
    if(root!=NULL){
         printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
               
   }
}

int main(){
    int value;
    Node* root=NULL;
    Node* newnode;
    int choice;
    while(1){
        printf("Enter choice 1.insert 2. preorder 3. postorder 4.inorder 5.exit\n");
        scanf("%d",&choice);

switch(choice){

    case 1:printf("enter value\n");
    scanf("%d",&value);
    newnode=createNode(value);
    if(root==NULL){
        root=newnode;
    }
    else{
        insertNode(newnode,root);
    }
    break;

    case 2:preorder(root);
            break;
    case 3:postorder(root);
            break;
    case 4:inorder(root);
            break;
    case 5: return 0;                
}        
    }
}