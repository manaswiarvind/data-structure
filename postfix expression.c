#include <stdio.h>

#define SIZE 100
int top=-1;
int stack[SIZE];

void push(int x){
    if(top==SIZE-1){
        printf("stack is full");
    }
    top++;
    stack[top]=x;
}

int pop(){
    if(top==-1){
        printf("stack is empty\n");
}
    int x=stack[top];
    top--;
    return x;
}
int main(){
    char exp[10];
    char* e;
    int n1,n2,n3;
    printf("enter exp\n");
    scanf("%s",exp);
    e=exp;
    
    while(*e!='\0'){
        if(isdigit(*e)){
            push(*e-48);
        }
        else{
            n1=pop();
            n2=pop();
             
             switch(*e){
                 case '+':n3=n1+n2;
                 break;
                 case '-':n3=n2-n1;
                 break;
                 case '*':n3=n1*n2;
                 break;
                 case '/':n3=n2/n1;
                 break;
             }
             push(n3);
        }
        e++;
    }
    printf("the result is %d",pop());
}