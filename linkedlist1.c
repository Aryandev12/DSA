#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node * createnode(){
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    return (newnode);
}
 struct node insertnode(struct node **s,int info){
    struct node *temp,*p;
    temp=createnode();
    temp->next=NULL;
    temp->data=info;
    if(*s==NULL)
    *s=temp;
    else{
        p=*s;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=temp;
    }

 }
 struct node display(struct node **s)
 {
    struct node *p;
    p=*s;
    while(p!=NULL){
        printf("%d  ",p->data);
        p=p->next;
    }
 }
int main()
{   
    int k,i=1;
    struct node *head1=NULL,*head2=NULL,*head3=NULL;
    while(i<=4){
        printf("enter data for first polyomial-\n");
        scanf("%d",&k);
        insertnode(&head1,k);
        i++;
    }
    i=0;
    while(i<=4)
    {
        printf("enter data for second polynomial");
        scanf("%d",&k);
        insertnode(&head2,k);
        i++;
    }
    display(&head1);
    printf("\n");
    display(&head2);
    return 0;
}