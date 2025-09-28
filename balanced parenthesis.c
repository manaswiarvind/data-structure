#include <stdio.h>

#define SIZE 100
int top=-1;
char stack[SIZE];

void push(char x){
        if(top==SIZE-1){
            printf("the stack is full");
            return;
        }
        top++;
        stack[top]=x;
}
char pop(){
    if(top==-1){
        printf("the stack is empty");
        return;
    }
    char s=stack[top];
    top--;
    return s;
}

int ismatching(char c1,char c2){
    if(c1=='(' && c2==')'){
        return 1;
    }
    else if(c1=='{' && c2=='}'){
        return 1;
    }
    else if(c1=='[' && c2==']'){
        return 1;
    }
    else{
        return 0;
    }
}
int isbalanced(char* l){
    for(int i=0;i<strlen(l);i++){
        if(l[i]=='(' || l[i]=='{' || l[i]=='['){
            push(l[i]);
        }
        else if(l[i]==')' || l[i]=='}' || l[i]==']'){
            if(top==-1){
                return 0;
            }
            else if(!ismatching(pop(),l[i])){
                return 0;
            }
        }
    }
    if(top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    char l[10];
    printf("enter string with parenthesis\n");
    scanf("%s",l);
    if(isbalanced(l)){
        printf("balanced");
    }
    else{
        printf("not balanced");
    }
    
}