//StudentStack
//stack using link list
#include <stdio.h>
#include <stdlib.h>

typedef struct Student{
    int id;
    char name[60];
    float cgpa;
} student;


typedef struct StudentStack{
    student st;
    struct StudentStack *next;
} node;


void push(node *stack, student data){
    node *temp;
    temp=(node*)malloc(sizeof(node));
    temp->st=data;
    temp->next=NULL;
    while(stack->next!=NULL)
        stack=stack->next;
    stack->next=temp;
    printf("Student ID:%d inserted!\n", data.id);
}

student pop(node *stack){
    student data;
    node *temp;
    if(stack->next == NULL){
        printf("Stack is empty \n");
        return data;
    }
    while(stack->next->next!=NULL)
        stack=stack->next;
    temp=stack->next;
    data=temp->st;
    stack->next=temp->next;
    return data;
}

int main() {
    // stack using linked list
    node *stack;
    stack=(node*)malloc(sizeof(node));
    stack->next=NULL;

    student s;
    s.id=101;
    strcpy(s.name,"Abdur Rahim");
    s.cgpa=3.75;

    push(stack, s);

    s.id=102;
    strcpy(s.name,"Karim Mia");
    s.cgpa=3.50;

    push(stack, s);

    printf("Popped data....\n");
    printf("Student ID\tName\tCGPA\n");
    s=pop(stack);
    printf("%d %s %f\n",s.id,s.name,s.cgpa);
    s=pop(stack);
    printf("%d %s %f\n",s.id,s.name,s.cgpa);

    return 0;
}

 