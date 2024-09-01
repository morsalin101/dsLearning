//BST to GST
///check description for code

#include<stdio.h>
#include<stdlib.h>

struct node
{
int value;
struct node *left_child, *right_child;
};

int sum=0;

typedef struct node Node;

Node *new_node(int value)
{
Node *tmp = (Node *)malloc(sizeof(Node));
tmp->value = value;
tmp->left_child = tmp->right_child = NULL;
return tmp;
}

void print_inorder(Node *root_node) // displaying the nodes!
{
if (root_node != NULL)
{
print_inorder(root_node->left_child);
printf("%d \n", root_node->value);
print_inorder(root_node->right_child);
}
}

void print_preorder(Node *root_node) // displaying the nodes!
{
if (root_node != NULL)
{
printf("%d \n", root_node->value);
print_preorder(root_node->left_child);
print_preorder(root_node->right_child);
}
}

void print_postorder(Node *root_node) // displaying the nodes!
{
if (root_node != NULL)
{
print_postorder(root_node->left_child);
print_postorder(root_node->right_child);
printf("%d \n", root_node->value);

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


void gst(Node* root_node){
        int temp;
  if(root_node!=NULL){
   gst(root_node->right_child);
   temp = root_node->value;
   root_node->value = sum;
   sum = sum + temp;
   gst(root_node->left_child);
  }else return;
}


int main()
{
printf("Implementation of a Binary Tree in C!\n\n");
Node *root_node = NULL;
root_node = insert_node(root_node, 10);
insert_node(root_node, 14);
insert_node(root_node, 8);
insert_node(root_node, 13);
insert_node(root_node, 9);
//insert_node(root_node, 16);
//insert_node(root_node, 12);

printf("Inorder\n");
print_inorder(root_node);

printf("Preorder\n");
print_preorder(root_node);

printf("Postorder\n");
print_postorder(root_node);

//convert BSt to GST
gst(root_node);

printf("Inorder GST \n");
print_inorder(root_node);

printf("Pre-order GST \n");
print_preorder(root_node);


return 0;
}


