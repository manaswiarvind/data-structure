#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define SIZE 50
char stack[SIZE];
int top=-1;
void push(char x){
    stack[++top]=x;
}

char pop(){
    return stack[top--];
}

int hpr(char x){
    if(x=='^'){
        return 3;
    }
    else if(x=='*' || x=='/'){
        return 2;
    }
    else if(x=='+'|| x=='-'){
        return 1;
    }
    else{
        return 0;
    }
}


void main(){
    char infix[50];
    char postfix[50];
    printf("enter an infix expression\n");
    scanf("%s",infix);
    int j=0;
    int i=0;
    while(infix[i]!='\0'){
        if(infix[i]=='('){
            push('(');
        }
        else if(isalnum(infix[i])){
            postfix[j++]=infix[i];
        }
        else if(infix[i]==')'){
            while(stack[top]!='('){
                postfix[j++]=pop();
            }
            char elem=pop();
        }
        else{
            while(hpr(stack[top])>=hpr(infix[i]) && top!=-1){
                postfix[j++]=pop();
            }
            push(infix[i]);
        }
        i++;
    }
    while(top!=-1){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    printf("postfix expression is %s\n",postfix);
}