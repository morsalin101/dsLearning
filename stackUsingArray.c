//Stack using Array

#include<stdio.h>
int stack[10];
int top = -1;

int push(int data){
    if(top>9){
        printf("Stack in full!\n");
        return -1;

       }
       else
       {
       top++;
       stack[top]=data;
       printf("%d in pushed!\n", data);
       }
       }

int pop(){
        if(top<0){
             printf("Stack is Empty!\n");
             return -1;
        }

   else
   {

        return stack[top--];
   }

}


    int main(){
    push(5); push(7); push(9);
    printf("poped %d \n", pop());
    printf("poped %d \n", pop());
    printf("poped %d \n", pop());


    return 0;


    }
