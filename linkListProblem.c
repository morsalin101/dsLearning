///link list problem
//Unsolved code
//Problem:- the add_front is not working
//Question added by Md. Nawshin Zaman

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int id;
    int data;
    struct Node *next;
}node;

void add_end(node *list)
{
    system("cls");
    node *temp;
    temp = (node*)malloc(sizeof(node));

    while(list->next != NULL)
    {
        list = list->next;
    }

    printf("Id: ");
    scanf("%d", &temp->id);
    printf("Data: ");
    scanf("%d", &temp->data);
    temp->next = NULL;

    list->next = temp;
}

void add_front(node *list)
{
    system("cls");
    node *temp;
    temp = (node*)malloc(sizeof(node));

    printf("Id: ");
    scanf("%d", &temp->id);
    printf("Data: ");
    scanf("%d", &temp->data);
    temp->next = list;

    list = temp;
}

void add_after(node* list)
{
    system("cls");
    int id;
    printf("Enter the ID of which after you want to put data: ");
    scanf("%d", &id);
    while(list->id != id)
    {
        list = list->next;
        if(list == NULL)
        {
            printf("ID not found!\n");
            system("pause");
            return;
        }
    }

    node* temp;
    temp = (node*)malloc(sizeof(node));

    printf("Id: ");
    scanf("%d", &temp->id);
    printf("Data: ");
    scanf("%d", &temp->data);

    temp->next = list->next;
    list->next = temp;


}

void display_all(node *list)
{
    system("cls");
    printf("All Data with ID\n");
    printf("-----------------------\n");

    while(list != NULL)
    {
        printf("ID-%d \t Data-%d\n", list->id, list->data);
        list = list->next;
    }
    system("pause");
}

int main(void)
{
    node *list;
    list = (node*) malloc(sizeof(node));
    list->id = 1000;
    list->data = 0;
    list->next = NULL;

    int op;
    while(1)
    {
        system("cls");
        printf("1. Add element at end\n");//ok
        printf("2. Add element at front\n");
        printf("3. Add element in after\n");
        printf("4. Add element in before\n");
        printf("5. Delete element from end\n");
        printf("6. Delete element from front\n");
        printf("7. Delete element after\n");
        printf("8. Delete element before\n");
        printf("9. Show all\n");//ok
        printf("10. Search info by id\n");
        printf("0. Exit\n");

        scanf("%d", &op);

        switch(op)
        {
        case 1:
            add_end(list);
            break;
        case 2:
            add_front(list);
            break;
        case 3:
            add_after(list);
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            display_all(list);
            break;
        case 10:
            break;
        case 0:
            break;

        }
        if(op == 0)
        {
            free(list);
            break;
        }

    }


    return 0;
}
