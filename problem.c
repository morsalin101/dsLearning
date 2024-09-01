///(V3)Book management using only stack (Most optimized design till now) by Md. Nawshin Zaman
// In this code, the most significant improvement is that the time complexity of push() and pop() is now O(1)
// By improving the time complexity, I have also become able to print my book list in LIFO format which was not possible in V-2 code.

/*
Some Characteristics:
1. the stack doesn't contain any blank node
2. I have manipulated the push() and pop() using a pointer variable name *top. This pointer always points towards the Last element that has been put inside the stack.
3. I also have to change the delete_book() functions logic, as it has to deal with the new version of the stack using the *top pointer. 
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book
{
    int id;
    char title[80];
    float price;
    struct Book *next;
} book;
book *top = NULL;


int showmenu()
{
    int ch;
    system("cls");
    printf("\t\t\t\tMenu\n");
    printf("------------------------------------------------\n");
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

void book_push(void)
{
    system("cls");
    book *temp;
    temp = (book*)malloc(sizeof(book));

    if(temp == NULL)
    {
        printf("Stack overflow!\n");
        return;
    }

    char title[60];
    printf("\n\n");
    printf("\t\t\t\t----Book Info----\n\n");
    printf("\t\tEnter id:");
    scanf("%d%*c",&temp->id);
    printf("\t\tEnter title:");
    gets(title);
    strcpy(temp->title,title);
    printf("\t\tEnter book price:");
    scanf("%f",&temp->price);

    temp->next = top;
    top = temp;

    system("pause");
}

void book_pop(void)
{
    system("cls");
    book *temp;

    if(top == NULL)
    {
        printf("There is no books.\n");
        system("pause");
        return;
    }

    temp = top;
    top = temp->next;
    temp->next = NULL;

    printf("\t\t\t\t----Popped data----\n");
    printf("Book Id: %d\n",temp->id);
    printf("Book Title: %s\n",temp->title);
    printf("Book Price: %.2f\n",temp->price);

    free(temp);

    system("pause");
}

void display_books(void)
{
    system("cls");
    book *temp;
    temp = top;
    printf("Book ID \t Book Name \t Book price\n");
    printf("--------------------------------------------------------------\n");
    while(temp != NULL)
    {

        printf("%d \t %s \t %.2f\n", temp->id, temp->title, temp->price);
        temp = temp->next;
    }
    system("pause");
}

void delete_book(void)
{
    system("cls");
    int id;
    printf("Enter the book id you want to delete: ");
    scanf("%d",&id);

    book *head, *temp;
    if(top == NULL)
    {
        printf("Book ID:%d not found.\n", id);
        system("pause");
        return;
    }

    if(top->id == id)
    {
        head = top;
        top = top->next;
        free(head);
        printf("Book Id: %d has been deleted successfully\n", id);
        system("pause");
        return;
    }

    head = top;

    while(1)
    {
        if(head->next == NULL)
        {
            printf("Book ID:%d not found.\n", id);
            system("pause");
            return;
        }

        if(head->next->id == id)
        {
            break;
        }
        else
        {
            head = head->next;
        }
    }

    temp = head->next;
    head->next = temp->next;
    free(temp);
    printf("Book Id: %d has been deleted successfully\n", id);
    system("pause");
    return;
}

void book_count(void)
{
    system("cls");
    int count = 0;

    book *head;
    head = top;

    while(head != NULL)
    {
        count++;
        head = head->next;
    }

    printf("You have total %d book(s) in your stack!\n", count);
    system("pause");
}

int main(void)
{
    int ch;

    while(1)
    {
        ch = showmenu();

        switch(ch)
        {
        case 1:
            book_push();//ok
            break;
        case 2:
            book_pop();//ok
            break;
        case 3:
            display_books(); //ok
            break;
        case 4:
            delete_book(); //ok
            break;
        case 5:
            book_count();//ok
            break;
        case 6:
            exit(0);
            break;

        }
    }

    return 0;
}

