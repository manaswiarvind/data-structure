#include <stdio.h>

#define SIZE 10
int top=-1;
char stack[SIZE];

void push(int x){
    if(top==SIZE-1){
        printf("stack is full\n");
        return;
    }
    top++;
    stack[top]=x;
}

char pop(){
    if(top==-1){
        printf("stack is empty\n");
        return;
    }
    char x=stack[top];
    top--;
    return x;
}
int main() {
    char s[10];
	printf("input a string");
	scanf("%[^\n]s",s);
	for(int i=0;i<strlen(s);i++){
	    push(s[i]);
	}
	for(int j=0;j<strlen(s);j++){
	    s[j]=pop();
	}
    printf("the reverse string is %s",s);
}

