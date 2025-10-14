#include<stdio.h>
#define size 50
int q[size];
int f=-1;
int r=-1;

int isfull(){
    return r==size-1;
}

int isempty(){
    return r==-1 && f==-1;
}

void insert(int x){
    if(isfull()){
        printf("overflow\n");
    }
    else if(f==-1 && r==-1){
        f=0;
        r=0;
    }
    else{
        r++;
    }
    q[r]=x;
}

void delete(){
    if(isempty()){
        printf("underflow");
    }
    else if(f==r){
        f=-1;
        r=-1;
    }
    else{
        f++;
    }
}

void display(){
    if(f==-1){
        printf("isempty\n");
    }
    for(int i=f;i<=r;i++){
        printf("queue[%d]:%d\n ",i,q[i]);
    }
}


int main(){
    int ch;
    int x;
    while(1){
        printf("1.insert 2.delete 3.display\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("enter element to be inserted\n");
                scanf("%d",&x);
                insert(x);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            default:
            printf("invalid choice");            
        }
    }
}
