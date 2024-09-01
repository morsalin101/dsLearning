///Binary tree



#include<stdio.h>
#include<stdlib.h>

struct node
{
int value;
struct node *left_child, *right_child;
};

typedef struct node Node;

Node *new_node(int value)
{
Node *tmp = (Node *)malloc(sizeof(Node));
tmp->value = value;
tmp->left_child = tmp->right_child = NULL;
return tmp;
}

void print(Node *root_node) // displaying the nodes!
{
if (root_node != NULL)
{
print(root_node->left_child);
printf("%d \n", root_node->value);
print(root_node->right_child);
}
}


Node* insert_node(Node* node, int value) // inserting nodes!
{
if (node == NULL) return new_node(value);

if (value < node->value)
{
node->left_child = insert_node(node->left_child, value);
}
else if (value > node->value)
{
node->right_child = insert_node(node->right_child, value);
}
return node;
}



int main()
{
printf("Implementation of a Binary Tree in C!\n\n");
Node *root_node = NULL;
root_node = insert_node(root_node, 10);
insert_node(root_node, 10);
insert_node(root_node, 30);
insert_node(root_node, 25);
insert_node(root_node, 36);
insert_node(root_node, 56);
insert_node(root_node, 78);
print(root_node);
return 0;
}


