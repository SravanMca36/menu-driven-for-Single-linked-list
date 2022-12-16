#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node * create(struct node *);
void print(struct node *);
struct node * insert_beg(struct node *);
struct node * insert_end(struct node *);
struct node * insert_mid_val(struct node *);
struct node * insert_mid_pos(struct node *);
struct node * del_beg(struct node *);
struct node * del_end(struct node *);
struct node * del_mid_val(struct node *);
struct node * del_mid_pos(struct node *);
main()
{
struct node *L=NULL;
int ch;
printf("1.Creating a node and printing:\n2.Node insertion at Beginning:\n3.Node insertion at Ending:\n4.Node insertion at middle by value:\n5.Node insertion at middle by POsition:\n6.Node deletion at beginning:\n7.Node deletion at Ending:\n8.Node deletion at middle by value:\n9.Node deletion at middle by position:\n");
printf("Enter the choice:\n");
scanf("%d",&ch);
switch(ch)
{
case 1 : L=create(L);
         print(L);
         break;
case 2 : L=insert_beg(L);
         print(L);
         break;
case 3 : L=insert_end(L);
         print(L);
         break;
case 4 : L=insert_mid_val(L);
         print(L);
         break;
case 5 : L=insert_mid_pos(L);
         print(L);
         break;
case 6 : L=del_beg(L);
         print(L);
         break;
case 7 : L=del_end(L);
         print(L);
         break;
case 8 : L=del_mid_val(L);
         print(L);
         break;
case 9 : L=del_mid_pos(L);
         print(L);
         break;
}
}
void print(struct node *L)
{
while(L!=NULL)
{
printf("Element=%d\n",L->data);
L=L->next;
}
}
struct node * create(struct node *L)
{
int n,ele,i;
printf("Enter n value:\n");
scanf("%d",&n);
struct node *p,*last;
for(i=0;i<n;i++)
{
printf("enter an element:\n");
scanf("%d",&ele);
p=(struct node *)malloc(sizeof(struct node));
p->data=ele;
p->next=NULL;
if(L==NULL)
{
L=p;
last=p;
}
else
{
last->next=p;
last=p;
}
}
return L;
}
struct node * insert_beg(struct node *L)
{
 L=create(L);
 int element;
 struct node *p;
 printf("Enter an Element:\n");
 scanf("%d",&element);
 p=(struct node *)malloc(sizeof(struct node));
 p->data=element;
 p->next=NULL;
 p->next=L;
 L=p;
 return L;
}
struct node * insert_end(struct node *L)
{
 L=create(L);
 int element;
 struct node *p,*q;
 p=(struct node *)malloc(sizeof(struct node));
 printf("Enter an element:\n");
 scanf("%d",&element);
 p->data=element;
 p->next=NULL;
 q=L;
 while(q->next!=NULL)
 {
     q=q->next;
 }
 q->next=p;
 return L;
}
struct node * insert_mid_val(struct node *L)
{
    L=create(L);
    int element,val;
    struct node *p,*q;
    p=(struct node *)malloc(sizeof(struct node));
    printf("Enter an element:\n");
    scanf("%d",&element);
    p->data=element;
    p->next=NULL;
    printf("Enter a value:\n");
    scanf("%d",&val);
    q=L;
    while(q!=NULL&&q->data!=val)
    {
        q=q->next;
    }
    if(q==NULL)
    {
        printf("There is no such value");
    }
    else
    {
        p->next=q->next;
        q->next=p;
    }
    return L;
}
struct node * insert_mid_pos(struct node *L)
{
 L=create(L);
 int i,pos,element;
 struct node *p,*q;
 p=(struct node *)malloc(sizeof(struct node));
 printf("Enter the position:\n");
 scanf("%d",&pos);
 printf("Enter an Element:\n");
 scanf("%d",&element);
 p->data=element;
 p->next=NULL;
 q=L;
 if(pos==1)
 {
     p->next=L;
     L=p;
 }
 else{
    for(i=0;i<pos-2;i++)
    {
        q=q->next;
    }
    p->next=q->next;
    q->next=p;
 }
 return L;
}
struct node * del_beg(struct node *L)
{
 L=create(L);
 struct node *p;
 p=L;
 L=L->next;
 free(p);
 return L;
}
struct node * del_end(struct node *L)
{
 L=create(L);
 struct node *p,*q;
 q=L;
 while(q->next->next!=NULL)
 {
     q=q->next;
 }
 p=q->next;
 q->next=p->next;
 free(p);
 return L;
}
struct node * del_mid_val(struct node *L)
{
    L=create(L);
    int val;
    struct node *p,*q;
    printf("Enter the value:\n");
    scanf("%d",&val);
    q=L;
    if(q->data==val)
    {
        p=L;
        L=L->next;
        free(p);
    }
    else
    {
        while(q->next!=NULL&&q->next->data!=val)
        {
            q=q->next;
        }
        p=q->next;
        q->next=q->next->next;
        free(p);
    }
    return L;
}
struct node * del_mid_pos(struct node *L)

{
 L=create(L);
 int i,pos;
 printf("Enter the position:\n");
 scanf("%d",&pos);
 struct node *p,*q;
 q=L;
 for(i=0;i<pos-2;i++)
 {
     q=q->next;
 }
 p=q->next;
 q->next=p->next;
 free(p);
 return L;
}
