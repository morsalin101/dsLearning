//Merge two sorted linked list

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
}Node;

Node * head1;
Node * tail1;
Node * head2;
Node * tail2;
void take_input1(int data)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if(head1 == NULL)
    {
        head1 = newNode;
        tail1 = newNode;
        return;
    }
    tail1->next = newNode;
    tail1 = newNode;
}



void take_input2(int data)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if(head2 == NULL)
    {
        head2 = newNode;
        tail2 = newNode;
        return;
    }
    tail2->next = newNode;
    tail2 = newNode;
}

void mergeList()
{
     Node* temp = head1;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = head2;
        Node* temp1 = head1;
        for(Node* i = temp1;  i->next != NULL; i = i->next)
        {
            for(Node* j = i->next ; j != NULL; j = j->next)
            {
                if(i->data > j->data)
                {
                    int temp2 = i->data;
                    i->data = j->data;
                    j->data = temp2;
                }
            }
        }
}

void print(Node * head)
{
    Node * temp = head;
    while(temp != NULL)
    {
        printf("%d",temp->data);
        temp = temp->next;
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d",&n);
        for(int i = 1; i <= n; i++)
        {
            int x;
            scanf("%d",&x);
            take_input1(x);
        }
        scanf("%d",&m);
        for(int i = 1; i <= m; i++)
        {
            int x;
            scanf("%d",&x);
            take_input2(x);
        }
        mergeList();
        print(head1);
    }
}
