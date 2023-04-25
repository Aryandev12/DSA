#include<stdio.h>
#include<stdlib.h>
//self referential structure.
 struct node{
    int info;
    struct node *link;
};

struct node *START=NULL;
//creation of node using malloc in heap memory .malloc returns address of heap memory and store in the pointer variable.
struct node * createNode(){
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
    temp->link=NULL;
    t=START;
    if(START==NULL)
    START=temp;
    else{
        temp->link=START;
        START=temp;
    }
}
//insertion of node at last 
void insertNode(){
    struct node *temp,*t;
    temp=createNode();
    printf("enter a number");
    scanf("%d",&temp->info);
    temp->link=NULL;
    if(START==NULL)
    START=temp;
    else{
        t=START;
        while(t->link!=NULL)
        {
            t=t->link;
        }
        t->link=temp;
    }
} 
//deletion of first node.
void deletefirstNode(){
    struct node *r;
    if(START==NULL)
    printf("list is empty");
    else
    {
        r=START;
        START=START->link;
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
        while(t->link->link!=NULL)
        {
            t=t->link;
        }
        q=t->link;
        t->link=NULL;
        free(q);
    }

}
//deletion at k position.
void deletion_at_k_position()
{
    struct node *t,*q;
    int k,i=0;
    printf("\nenter the position of the data you want to delete");
    scanf("%d",&k);
    t=START;
    if(START==NULL)
    printf("list is empty");
    else{
        while(i<(k-2)){
            t=t->link;
            i++;
        }
        q=t->link;
        t->link=t->link->link;
        q->link=NULL;
        free(q);
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
            t=t->link;
        } 
    }
}  
//linear searching  
void linearsearch(){
    struct node *t;
    int n,count=0,flag=0;
    printf("enter the number you want to search-");
    scanf("%d",&n);
    if(START==NULL)
    printf("list is empty");
    else{
        t=START;
        while(t!=NULL)
        {
            count++;
            if(t->info==n)
            {   
                flag=1;
                break;
            }
            t=t->link;
        }
        if(flag==1){
            printf("Number is found at %d position",count);
        }
        else{
            printf("number is not in the list");
        }
    }
}   
//menu bar
int menu()
{
    int ch;
    printf(" ");
    printf("\n1.Add value to the List-");
    printf("\n2.Delete first value-");
    printf("\n3.View List-");
    printf("\n4 enter new node at k position");
    printf("\n5.insert at begining");
    printf("\n6.delete at last");
    printf("\n7.delete at K position");
    printf("\n8.Searching");
    printf("\n9.Reverse");
    printf("\n10.Exit");
    printf("\nEnter your choice-");
    scanf("%d",&ch);
    return (ch);
}
// insertion of new node at kth position
void insertionatk()
{
    int k,i;
    struct node *p,*newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("enter data -");
    scanf("%d",&newnode->info);
    newnode->link=NULL;
    printf("\nenter the position where you want to insert element ");
    scanf("%d",&k);
    p=START;
    for(i=0;i<k-1;i++)
    {
        p=p->link;
    }    
    newnode->link=p->link;
    p->link=newnode;
}
// reversal of  a node 
void reverse(){
    struct node *t1,*t2;
    t1=NULL;
    t2=NULL;
    while(START!=NULL)
    {
      t2=START->link;
      START->link=t1;
      t1=START;
      START=t2;
    }
     START=t1;
}[]
int main()
{
    while(1)
    {   system("cls");
        switch(menu())
        {
            case 1: insertNode();
                    break;
            case 2: deletefirstNode();
                    break;
            case 3: viewList();
                    break;
            case 4: insertionatk();
                    break;
            case 5: insertatbegining();
                     break;
            case 6: deletelastNode();
                    break;
            case 7: deletion_at_k_position();
                    break;  
            case 8: linearsearch();
                    break;  
            case 9: reverse();
                    break;  
            case 10: exit(0);
                    break;     
            default : printf("invalid choice");
        }
        
     system("pause");

    
    }
    return 0;
}


