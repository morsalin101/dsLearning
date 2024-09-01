//Infix to Postfix using Stack
#include<stdio.h> 
#include<string.h> 
#define max 100 
 
char stack[max]; 
 
int top=-1; 
 
void push(char k); 
char pop(); 
 
int main() 
{ 
 int l,i; 
 char ch,e[max]; 
 int opcnt=0,popcnt=0,pushcnt=0; 
 
 printf("Enter infix exp with () to convert to postfix \n"); 
 gets(e); 
 l=strlen(e); 
 printf("The postfix is :\n"); 
 for(i=0;i<=l-1;i++) 
 { 
  ch=e[i]; 
  if(ch=='('||ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'||ch=='%') 
  { 
    push(ch); 
    opcnt++; 
    pushcnt++; 
  } 
  else if(ch!=')') 
    putchar(ch); 
  else 
   { 
    popcnt++; 
     do 
     { 
      ch=pop(); 
      if(ch!='(') 
        putchar(ch); 
     } 
     while(ch!='('); 
   } 
 } 
 printf("\nNo of push:%d",pushcnt); 
 printf("\nNo of pop:%d",popcnt); 
 printf("\nNo of operator:%d",opcnt); 
 
 
// getch(); 
return 0; 
} 
 
void push(char k) 
{ 
 if(top+1==max) 
    printf("stack is full\n"); 
 else 
 { 
    top++; 
    stack[top]=k; 
 } 
 return; 
} 
 
char pop() 
{ 
 char a; 
 if(top<0) 
 { 
     printf("stack is empty\n");return('\0'); 
 } 
 else 
 { 
     a=stack[top]; 
     top--; 
     return(a); 
 } 
}
