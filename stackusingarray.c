#include<stdio.h>
#include<stdlib.h>
struct ArrayStack{
    int top;
    int capacity;
    int *array;
};
struct ArrayStack* createstack(int cap){
    struct ArrayStack *s;
    s=(struct ArrayStack *)malloc(sizeof(struct ArrayStack));
    s->top=-1;
    s->capacity=cap;
    s->array=(int *)malloc(sizeof(int)*cap);
    return s;
}
int isFull(struct ArrayStack *s)
{
    if(s->top==s->capacity-1)
    {
        printf("stack is full or stack over flow");
        return 1;
    }
    return 0;
}
int isEmpty(struct ArrayStack *s)
{
    if(s->top==-1)
    {
        printf("underflow");
        return 1;
    }
    return 0;
}
void push(struct ArrayStack *s,int item)
{
    if(!isFull(s))
    {
        s->top++;
        s->array[s->top]=item;
    }
}
int pop(struct ArrayStack *s)
{   int item;
    if(!isEmpty(s))
    {
        item=s->array[s->top];
        s->top--;  
        return item;  
    }
    return 0;
}
int menu()
{   int ch;
    printf("\n1.Push a number ");
    printf("\n2.Pop a number");
    printf("\n3.exit");
    printf("\nenter ypur choice-");
    scanf("%d",&ch);
    return ch;
}
int main()
{   int n,k,item;
    struct ArrayStack *stack;
    printf("enter the capacity-");
    scanf("%d",&n);
    stack=createstack(n);
    while(1)
    {
        switch(menu())
        {
            case 1: printf("enter the number you want to push-");
                    scanf("%d",&k);
                    push(stack,k);
                    break;

            case 2: printf("pop item-");
                    item=pop(stack);
                    printf("%d",item);
                    break;
            case 3: exit(0);
                    
        }
    }
    return 0;

}