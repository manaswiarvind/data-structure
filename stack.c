#include<stdio.h>

void push(int);
void pop();
void display();

 int top=-1;
 int stack[10];
void main(){
    int choice,value;
    while(1){
    printf("enter the choice 1.push 2.pop 3.display 4.exit\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:printf("enter the value to be inserted\n");
        scanf("%d",&value);
        push(value);
        break;
        case 2:pop();
        break;
        case 3:display();
        break;
        case 4:exit(0);
        break;
        default:printf("unsuccessfull");
    }
    }
}


void push(int x){
    if(top==9){
        printf("The stack is already full\n");
    }
    else{
        top++;
        stack[top]=x;
    }
}
void pop(){
    if(top==-1){
        printf("stack is empty\n");
    }
    else{
        printf("deleted element is %d \n",stack[top]);
        top--;
    }
}
void display(){
    printf("the elements are\n");
    for(int i=top;i>=0;i--){
        printf("%d\n",stack[i]);
    }
}
