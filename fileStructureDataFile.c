//FruitStructureDataFile
# include <stdio.h>
# include <conio.h>
# include <string.h>


typedef struct Fruit{
        int id ;
        char name[50];
        float price;
} fruit;


main()
{
    fruit t;
    FILE *fp;
    FILE *fp2;
    int temp;
    float cgpa;
    char sname[50],c;
    int ch;
    while(1)
    {
        system("cls");
        printf("\t\t\t\tMenu\n");
        printf("1. Add a fruit in file.\n");
        printf("2. Delete a fruit from file.\n");
        printf("3. Search a fruit by name.\n");
        printf("4. Search a fruit by ID\n");
        printf("5. See all the record.\n");
        printf("6. EXIT.\n");
        printf("ENTER YOUR CHOICE:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                    fp=fopen("fruit.txt","ab");
                    while (1)
                    {
                      system("cls");
                      printf("Enter id:");
                      scanf("%d",&t.id);
                      fflush(stdin);
                      printf("\nEnter name:");
                      scanf("%s",&t.name);
                      fflush(stdin);
                      printf("\nEnter price:");
                      scanf("%f",&t.price);
                      fwrite(&t,sizeof(t),1,fp);
                      fflush(stdin);
                      printf("\n\nDo you wish to continues?(Y/N):");
                      scanf("%c",&c);
                      if(c=='n' || c=='N')
                            break;
                    }
                    fclose(fp);
                    break;
            case 2:
                    fp=fopen("fruit.txt","rb");
                    system("cls");
                    printf("Delete fruit by ID.\n");
                    printf("Enter ID:");
                    scanf("%d",&temp);
                    fp2=fopen("copy.txt","wb");

                    while(fread(&t,sizeof(t),1,fp))
                    {
                        if(temp==t.id)
                        {
//                            t.id[0]='\0';
//                            t.name[0]='\0';
//                            t.cgpa=0;
                            fwrite(&t,sizeof(t),1,fp2);
                        }
                    }
                    fclose(fp2);
                    fclose(fp);
                    system("Del fruit.txt");
                    system("Ren copy.txt fruit.txt");
                    printf("Deletion complete!\n");
                    getch();
                    break;

            case 3:
                    fp=fopen("fruit.txt","rb");
                    system("cls");
                    printf("Search fruit by name.\n");
                    printf("Enter name:");
                    scanf("%s",sname);
                    while(fread(&t,sizeof(t),1,fp))
                    {
                        if(strcmp(sname,t.name)==0)
                        {
                            printf("\n\t%d\t %s\t %f",t.id,t.name,t.price);
                            getch();
                            break;
                        }
                    }
                    fclose(fp);
                    getch();
                    break;
            case 4:
                    fp=fopen("fruit.txt","rb");
                    system("cls");
                    printf("Search fruit by ID.\n");
                    printf("Enter ID:");
                    scanf("%d",&temp);
                  //  printf("%s",sname);
                    fflush(stdin);
                    while(fread(&t,sizeof(t),1,fp))
                    {
                        if(temp==t.id)
                        {
                             printf("\n\t%d\t %s\t %f",t.id,t.name,t.price);
                            getch();
                            break;
                        }
                    }
                    fclose(fp);
                    getch();
                    break;
            case 5:
                    fp=fopen("fruit.txt","rb");
                    system("cls");
                    printf("\tList of Records in File");
                    printf("\n\tID\tName\tPrice");

                    while(fread(&t,sizeof(t),1,fp))
                    {
                      printf("\n\t%d\t %s\t %f",t.id,t.name,t.price);
                    }
                    fclose(fp);
                    getch();
                    break;

            case 6:
                    exit(1);
        }
    }
        getch();

}
