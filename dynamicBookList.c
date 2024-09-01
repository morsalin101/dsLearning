//Dynamic Book List
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct Book{
    int bookid;
    char title[60];
    float price;
    struct Book *next;
}book;

int showmenu(){
        int ch;
        system("cls");
        printf("\t\t\t\tMenu\n");
        printf("1. Add a Book\n");
        printf("2. Delete a Book\n");
        printf("3. Search a Book\n");
        printf("4. Display Books\n");
        printf("5. Save Data to File\n");
        printf("6. Read Data from File\n");
        printf("7. EXIT\n");
        printf("ENTER YOUR CHOICE:");
        scanf("%d",&ch);
        return ch;
}

void addBook(book *list){
    book *temp;
    int bookid;
    char title[60];
    float price;

    temp=(book*) malloc(sizeof(book));
    printf("Enter book id:");
    scanf("%d",&bookid);
    fflush(stdin);
    printf("Enter book title:");
    gets(title);
    fflush(stdin);
    printf("Enter book price:");
    scanf("%f",&price);

    temp->bookid=bookid;
    strcpy(temp->title,title);
    temp->price=price;
    temp->next=NULL;


    while(list->next!=NULL)
        list=list->next;

    list->next=temp;
    printf("%d ID is added in Book List!\n",bookid);
    getch();
}

void delBook(book *list)
{
    book *temp;
    int bookid;
    printf("Enter book ID:");
    scanf("%d",&bookid);

    while (list->next->bookid!=bookid)
        list=list->next;

    temp=list->next;
    list->next=temp->next;
    free(temp);
    printf("%d ID is deleted in Book List!\n",bookid);
    getch();

}

void displayBook(book *list)
{
    printf("Book List\n");
    printf("---------------------\n");
    printf("ID\tTitle\tPrice\n");

    while (list!=NULL){
        printf("%d\t%s\t%f\n",list->bookid,list->title,list->price);
        list=list->next;
    }
    getch();

}

void searchBook(book *list)
{
    int flag=0;
    int bookid;
    printf("Enter book ID:");
    scanf("%d",&bookid);

    while (list->next!=NULL){
        if(list->bookid==bookid){
            flag=1;
            break;}
        list=list->next;
    }

    if(flag==1)
        printf("%d Book ID is found!",bookid);
    else
        printf("Not Found!!");
    getch();
}

void saveData2File(book *list){
    FILE *fp;
    fp=fopen("books.dat","wb");
    book b;

    if(fp==NULL){
        printf("Failed to open file!!");
        return;
    }

    while(list!=NULL){
        b.bookid=list->bookid;
        strcpy(b.title,list->title);
        b.price=list->price;

        fwrite(&b,sizeof(b),1,fp);
        list=list->next;
    }
        printf("Data saved to file books.dat!");
    fclose(fp);
    getch();
}

void readDataFromFile(book *list){
    FILE *fp;
    fp=fopen("books.dat","rb");
    book b;

    book *temp;

    if(fp==NULL){
        printf("Failed to open file!!");
        return;
    }

    while(list->next!=NULL)
        list=list->next;

    while(fread(&b,sizeof(b),1,fp)){
        temp=(book*)malloc(sizeof(book));
        temp->next=NULL;

        temp->bookid=b.bookid;
        strcpy(temp->title,b.title);
        temp->price=b.price;

  //      printf("%d %s %f\n",b.bookid,b.title,b.price);
  //      exit(0);

        list->next=temp;
        list=list->next;

    }

    fclose(fp);
    printf("Read from file success!!");
    getch();
}


int main()
{
    int ch;
    char c;
    book *list;
    list=(book *)malloc(sizeof(book));
    list->next=NULL;

    while(1){
        ch=showmenu();
        switch(ch){
         case 1:
            addBook(list);
//            printf("\n\nDo you wish to continues?(Y/N):");
//            scanf("%c",&c);
//            if(c=='n' || c=='N')
               break;

         case 2:
             delBook(list);
             break;
         case 3:
              searchBook(list);
              break;
         case 4:
               displayBook(list->next);
               break;
         case 5:
                saveData2File(list->next);
                break;
         case 6:
                readDataFromFile(list);
                break;
         case 7:
                exit(0);

        }


    }

   return 0;
}
