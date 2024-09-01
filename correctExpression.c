//Correct expression
///Using stack
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char data;
    struct Node *next;
} node;

typedef struct Status
{
    int balanced; // 1 hole correct 0 hole incorrect
    char data;    // kon char kom beshi oita
} status;

node *createNode(char data)
{
    node *head = (node *)malloc(sizeof(node));
    head->data = data;
    head->next = NULL;
    return head;
}

char missingChar(char brack)
{
    if (brack == ']')
        return '[';
    if (brack == '}')
        return '{';
    if (brack == ')')
        return '(';
    if (brack == '[')
        return ']';
    if (brack == '{')
        return '}';
    if (brack == '(')
        return ')';
}
status isBalanced(char expr[])
{
    node *stack = NULL;
    status st;

    for (int i = 0; expr[i] != '\0'; i++)
    {
        char currentChar = expr[i];

        // jodi opening bracket pai tahole stack e push hobe
        if (currentChar == '(' || currentChar == '{' || currentChar == '[')
        {
            node *node = createNode(currentChar);
            node->next = stack;
            stack = node;
        }

        // If the current character is a closing bracket, pop the top element from the stack
        else if (currentChar == ')' || currentChar == '}' || currentChar == ']')
        {
            // stack a jodi kono bracket na thake tahole eta extra
            if (stack == NULL)
            {
                st.balanced = 0;
                st.data = missingChar(currentChar);
                return st;
            }

            // Pop the top element from the stack
            char topChar = stack->data;
            node *temp = stack;
            stack = stack->next;
            free(temp);

            // pop kore dewa char ta currentChar er opposite na hole unbalanced
            if ((currentChar == ')' && topChar != '(') ||
                (currentChar == '}' && topChar != '{') ||
                (currentChar == ']' && topChar != '['))
            {
                st.balanced = 0;
                st.data = missingChar(topChar);
                return st;
            }
        }
    }

    // If the stack is not empty at the end, it's unbalanced
    if (stack != NULL)
    {
        // printf("'%c' is missing\n", stack->data);
        st.balanced = 0;
        st.data = missingChar(stack->data);
        return st;
    }

    st.balanced = 1;
    st.data = '\0';
    return st;
}

int main()
{
    char expr[100];
    // scanf("%[^\n]s", expr);
    gets(expr);

    if (isBalanced(expr).balanced)
    {
        printf("Correct\n");
    }
    else
    {
        printf("Incorrect\n");
        printf("'%c' is missing\n", isBalanced(expr).data);
    }

    getchar();

    return 0;
}

/// Burhan Uddin

///Normal way
/*
#include <stdio.h>
#include <string.h>

int main()
{
    char string[101];
    int fb = 0, sb = 0, tb = 0;
    int fbc = 0, sbc = 0, tbc = 0;
    scanf("%[^\n]s", string);
    int len = strlen(string);

    for(int i = 0; i < len; i++)
    {
        if(string[i] == '(') fb++;
        else if(string[i] == '{') sb++;
        else if(string[i] == '[') tb++;
        else if(string[i] == ')') fbc++;
        else if(string[i] == '}') sbc++;
        else if(string[i] == ']') tbc++;
    }

    if((fb == fbc) && (sb = sbc) && (tb == tbc))
    {
        printf("Correct\n");
    }
    else
        printf("Incorrect\n");

    if(fb != fbc)
    {
        if(fb > fbc) printf("')' is missing\n");
        else printf("'(' extra\n");
    }
    else if(sb != sbc)
    {
        if(sb > sbc) printf("'}' is missing\n");
        else printf("'{' extra\n");
    }
    else if(tb != tbc)
    {
        if(tb > tbc) printf("']' is missing\n");
        else printf("'[' extra\n");
    }
}
*/