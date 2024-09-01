//dynamic list

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Result{
    float cgpa;
}result;

typedef struct Student{
    int id;
    char name[50];
    result rlt;
    struct Student *next;
}student;


int main(){
    int n,i;
    student *head,*temp;
    printf("How many Student info You Wanty to store:");
    scanf("%d",&n);

    head=(student*)malloc(sizeof(student));
    temp=head;

    for(i=0;i<n;i++)
        {
            printf("Enter Student id:");

            scanf("%d",&head->id);
            fflush(stdin);

            printf("Enter Student Name:");
            gets(head->name);
            fflush(stdin);

            printf("Enter Student CGPA:");

            scanf("%f",&head->rlt.cgpa);
            fflush(stdin);

        head->next=(student*)malloc(sizeof(student));
        head=head->next;
        }

    head->next="NULL";
    head=temp;

    for(i=0;i<n;i++) 
    {
    printf("Id: %d\t Name: %s\t %f\n", head->id, head->name, head->rlt.cgpa);
    head=head->next;
    }
    return 0;
}