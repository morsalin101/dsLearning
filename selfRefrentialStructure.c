//Self Referential DS

code1:
#include<stdio.h>
typedef struct student {
int id;
float cgpa;
struct Address{
 
int zipcode;
 
}adr;
 
}student;


int main(){
 
student st;
st.id=101;
st.cgpa=3.5;
st.adr.zipcode=2015;
printf("%d %f %d \n",st.id,st.cgpa,st.adr.zipcode);
 
return 0;
 
}
 
 
code2:
#include<stdio.h>
typedef struct Address{
int zipcode;
 
}adr;


typedef struct student{
 
int id;
float cgpa;
adr address;
 
}student;
 
 
int main(){
 
student st;
st.id=101;
st.cgpa=3.5;
st.address.zipcode=2015;
printf("%d %f %d \n",st.id,st.cgpa,st.address,st.address.zipcode);
return 0;
 
}
 
code3:
 
#include<stdio.h>

typedef struct Address{
int zipcode; 
}adr;


typedef struct student{ 
int id;
float cgpa;
adr address; 
}student;
 
 
int main(){
 
student st={100,3.5,{2015}};
printf("%d %f %d \n",st.id,st.cgpa,st.address,st.address.zipcode);
return 0;
 
}
 
code4 :
 
 
#include <stdio.h>
#include<stdlib.h>
typedef struct address{
 
int zipcode;
 
}adr;
typedef struct student{
 
    int id;
    float cgpa;
    adr address;
}student;
int main(){
 
    student *pt;
    pt=(student*)malloc(sizeof(student));
    pt->id=101;
    pt->cgpa=3.5;
    pt->address.zipcode=2015;
    printf("%d %f %d \n",pt->id,pt->cgpa,pt->address.zipcode);
    return 0;
 
 
}
code5:
 
 
#include<stdio.h>
#include<stdlib.h>
 
typedef struct Address{ 
int zipcode;
}adr;

typedef struct student{
int id;
float cgpa;
adr address;
struct student *next; 
}student;
 
int main(){ 
student *head,*temp;
int x,n,i;
head=(student*)malloc(sizeof(student));
temp=head;
printf("ENter no student :");
scanf("%d",&n);
for(i=0;i<n;i++){
    printf("Enter id:");
scanf("%d",&head->id);
 
 
printf("ENter cgpa:");
scanf("%f",&head->cgpa);
printf("Enter Zip:");
scanf("%d",&head->address.zipcode);
head->next=(student*)malloc(sizeof(student));
 
head=head->next;
}
head->next=NULL;
head=temp;
while(head->next!=NULL){
 
    printf("%d %f %d\n",head->id,head->cgpa,head->address.zipcode);
    head=head->next;
}
 
return 0;
}
 
 
 