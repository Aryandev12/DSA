#include<stdio.h>
#include<stdlib.h>
//self referential structure.
struct node{
    struct node *prev;
    int info;
    struct node *next;
};
struct node *START=NULL;
//creation of node using malloc in heap memory .malloc returns address of heap memory and store in the pointer variable.
struct node * createNode()
{
    struct node *n=(struct node *)malloc(sizeof(struct node));
    return (n);
}
//insertion of node at starting

void insertatbegining()
{
    struct node *temp,*t;
    temp=createNode();
    printf("enter a number you want to add in the begining of the list -");
    scanf("%d",&temp->info);
    temp->next=NULL;
    temp->prev=NULL;
    t=START;
    if(START==NULL)
    START=temp;
    else{
        temp->next=START;
        START->prev=temp;
        START=temp;
    }
}

//insertion of node at last 

void insertNode()
{
    struct node *newnode,*t;
    newnode=createNode();
    printf("enter a number");
    scanf("%d",&newnode->info);
    newnode->next=NULL;
    newnode->prev=NULL;
    if(START==NULL)
    START=newnode;
    else
    {
        t=START;
        while(t->next!=NULL)
        {
            t=t->next;
        }
        t->next=newnode;
        newnode->prev=t;
    }
} 
//traversing.
void viewList()
{
    struct node *t;
    if(START==NULL)
    printf("list is empty");
    else{
        t=START;
        while(t!=NULL)
        {
            printf("%d ",t->info);
            t=t->next;
        } 
    }
}  
// insertion of new node at kth position
void insertionatk()
{
    int k,i;
    struct node *p,*newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("enter data -");
    scanf("%d",&newnode->info);
    newnode->next=NULL;
    newnode->prev=NULL;
    printf("\nenter the position where you want to insert element ");
    scanf("%d",&k);
    p=START;
    for(i=0;i<k-2;i++)
    {
        p=p->next;
    }    
    newnode->next=p->next;
    p->next->prev=newnode;
    p->next=newnode;
    newnode=p->prev;
}
//deletion of first node.
void deletefirstNode(){
    struct node *r;
    if(START==NULL)
    printf("list is empty");
    else
    {
        r=START;
        START=START->next;
        START->prev=NULL;
        r->next=NULL;
        r->prev=NULL;
        free(r);
    }
}
 //deletion of last node.
void deletelastNode(){
    struct node *t,*q;
    if(START==NULL)
    printf("list is empty");
    else{
        t=START;
        while(t->next->next!=NULL)
        {
            t=t->next;
        }
        q=t->next; 
        t->next=NULL;
        q->prev=NULL;
        free(q);
    }

}
int main()
{ while(1)
  {
    insertNode();
    insertNode();
    insertNode();
    insertNode();
    insertNode(); 
    viewList();
    deletelastNode();
    viewList();
    deletelastNode();
    viewList();
    
  }
}
