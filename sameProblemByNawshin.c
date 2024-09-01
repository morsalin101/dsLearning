//(V2)Book management using only stack (another design) by Md. Nawshin Zaman

//Complete, but the display_books() function is mot showing in reverse order. That's a problem to solve.
//Second problem is that the time complexity of push and pop is O(n) for this code. but I want it as O(1)

///these 2 problems will be solved in V3 of the code ingshaAllah 
//Working on v-3.................(already done and added)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book
{
    int id;
    char title[80];
    float price;
} book;

typedef struct BookStack
{
    book b;
    struct BookStack *next;
} node;


int showmenu()
{
    int ch;
    system("cls");
    printf("\t\t\t\tMenu\n");
    printf("1. Add a Book to stack\n");
    printf("2. Get a Book from stack\n");
    printf("3. Display Books\n");
    printf("4. Delete a Book\n");
    printf("5. Show counts\n");
    printf("6. EXIT\n");
    printf("ENTER YOUR CHOICE: ");
    scanf("%d",&ch);
    return ch;
}

void book_push(node* stack)
{
    system("cls");
    book bo;
    char title[60];
    printf("\n\n");
    printf("\t\t\t\t----Book Info----\n\n");
    printf("\t\tEnter id:");
    scanf("%d%*c",&bo.id);
    printf("\t\tEnter title:");
    gets(title);
    strcpy(bo.title,title);
    printf("\t\tEnter book price:");
    scanf("%f",&bo.price);

    node *temp;
    temp = (node*)malloc(sizeof(node));

    temp->b = bo;
    temp->next = NULL;

    while(stack->next != NULL)
    {
        stack = stack->next;
    }
    stack->next = temp;

}

void book_pop(node *stack)
{
    system("cls");
    node *temp;
    temp = (node*)malloc(sizeof(node));

    if(stack->next == NULL)
    {
        printf("There is no books.\n");
        system("pause");
        return;
    }
    while(stack->next->next != NULL)
    {
        stack = stack->next;
    }
    temp = stack->next;

    book b;
    b = temp->b;
    stack->next = NULL;

    printf("\t\t\t\t----Popped data----\n");
    printf("Book Id: %d\n",b.id);
    printf("Book Id: %s\n",b.title);
    printf("Book Id: %.2f\n",b.price);

    free(temp);

    system("pause");
}

void display_books(node *stack)
{
    system("cls");
    node *temp1, *temp2, *temp;
    temp1 = temp2 = stack;

    book data;
    printf("\t\tBook ID\t\tTitle\tPrice\n");

    /*
    ///successfully printed in reverse order but will loose all data after 1 print.
    while(temp1->next != NULL)
    {
        temp2 = temp1;
        while(temp2->next->next != NULL)
        {
            temp2 = temp2->next;
        }
        temp = temp2->next;
        temp2->next = NULL;
        data = temp->b;
        free(temp);
        printf("\t\t%d\t\t%s\t%.2f\n",data.id,data.title,data.price);
    }*/

    while(stack->next != NULL)
    {
        stack = stack->next;
        data = stack->b;
        printf("\t\t%d\t\t%s\t%.2f\n",data.id,data.title,data.price);
    }

    system("pause");
}

void delete_book(node *stack)
{
    system("cls");
    int id;
    printf("Enter the book id you want to delete: ");
    scanf("%d",&id);

    node *temp;
    while(1)
    {
        if(stack->next == NULL)
        {
            printf("Book not found.\n");
            system("pause");
            return;
        }

        if(stack->next->b.id != id)
        {
            stack = stack->next;
        }
        else
        {
            break;
        }
    }

    temp = stack->next;
    stack->next = temp->next;
    free(temp);
    printf("%d book successfully deleted!\n",id);

    system("pause");
}

void book_count(node *stack)
{
    system("cls");
    int count = 0;

    while(stack->next != NULL)
    {
        count++;
        stack = stack->next;
    }

    printf("You have total %d book(s) in your stack!\n", count);
    system("pause");
}



int main(void)
{
    node *stack;
    stack = (node*)malloc(sizeof(node));
    stack->next = NULL;

    int ch;

    while(1)
    {
        ch = showmenu();

        switch(ch)
        {
        case 1:
            book_push(stack);//ok
            break;
        case 2:
            book_pop(stack);//ok
            break;
        case 3:
            display_books(stack); // ok, though I could not print them in reverse order correctly
            break;
        case 4:
            delete_book(stack); // ok
            break;
        case 5:
            book_count(stack);
            break;
        case 6:
            exit(0);
            break;

        }
    }


    return 0;
}
