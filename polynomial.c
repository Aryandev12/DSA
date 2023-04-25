#include<stdio.h>
#include<stdlib.h>
struct node{
    int pow;
    int coef;
    struct node *next;
};
struct node * create(){
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    return newnode;
}
void insert(struct node **s,int power,int co)
{
    struct node *newnode,*t;
    newnode=create();
    newnode->pow=power;
    newnode->coef=co;
    newnode->next=NULL;
    if(*s==NULL)
    *s=newnode;
    else
    {
        t=*s;
        while(t->next!=NULL)
        {
            t=t->next;
        }
        t->next=newnode;
    }

}
void display(struct node **s)
{
    struct node *t;
    t=*s;
    while(t!=NULL)
    {
        printf("%dX^%d + ",t->coef,t->pow);
        t=t->next;
    }
    printf(" 0");
    printf("\n");
}
struct node * add(struct node **s1,struct node **s2)
{
    struct node *temp=NULL,*t1,*t2;
    int co,po;
    t1=*s1;
    t2=*s2;    
    while(t1!=NULL)
 {
    if((t1)->pow==(t2)->pow)
    {
        co=(t1)->coef+(t2)->coef;
        po=(t1)->pow;
        insert(&temp,po,co);
        t1=t1->next;
        t2=t2->next;
    }
 }
    return temp;
}
int main()
{    int i=1,pow,c;
    struct node *head1=NULL,*head2=NULL,*head3=NULL;
    while(i<=4) 
    {   printf("enter %d coefficient of first polynomial-\n",i);
        scanf("%d",&c);
        printf("enter power-\n");
        scanf("%d",&pow);
        insert(&head1,pow,c);
        i++;
    }
    i=1;
    while(i<=4)
    {   printf("enter %d  coefficient of second polynomial-\n",i);
        scanf("%d",&c);
        printf("enter power-\n");
        scanf("%d",&pow);
        insert(&head2,pow,c);
        i++;
     
    }
    display(&head1);
    display(&head2);
    head3=add(&head1,&head2); 
    display(&head3);
    return 0;

}