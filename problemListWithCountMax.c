//problem list with count max
#include<stdio.h>

typedef struct Node{
    int data;
    struct Node *next;
}node;

int count(node *pnt){

    int countt=0;
     while(pnt->next!=NULL){
        countt++;
        pnt=pnt->next;
    }
    return countt;
}
int max(node *max){
    int maxval=0;
     while(max->next!=NULL){
        if(max->data>maxval)
                maxval=max->data;
        max=max->next;
    }
    return maxval;
}

int main(){
    node *list, *temp;
    list=(node*)malloc(sizeof(node));
    int n,i;
    printf("Enter How many data You want to store:");
    scanf("%d",&n);
    temp=list;
    for(i=0;i<n;i++){
            printf("Enter Data:");
        scanf("%d",&list->data);
        list->next=(node*)malloc(sizeof(node));
        list=list->next;

    }
    list->next=NULL;
    list=temp;
     while(list->next!=NULL){
        printf("%d,\n",list->data);
    list=list->next;
    }
    list=temp;
    printf("Total element-%d\n",count(list));
    printf("Maximum is- %d\n",max(list));


    return 0;
}
