#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct ArrayStack{
    int top;
    int capacity;
    char *array;
};
struct ArrayStack* createstack(int cap){
    struct ArrayStack *s;
    s=(struct ArrayStack *)malloc(sizeof(struct ArrayStack));
    s->top=-1;
    s->capacity=cap;
    s->array=(char *)malloc(sizeof(char)*cap);
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
void push(struct ArrayStack *s,char item)
{
    if(!isFull(s))
    {
        s->top++;
        s->array[s->top]=item;
    }
}
char pop(struct ArrayStack *s)
{   char item;
    if(!isEmpty(s))
    {
        item=s->array[s->top];
        s->top--;  
        return item;  
    }
    return 0;
}
int main()
{   
    struct ArrayStack *temp;
    char ch[20],p[20];
    int i;
    for(i=0,i<=18;i++)
    {
        scanf("%c",&ch[i]);
        scanf("\n");
    }
    ch[19]=')';
    push(temp,'(');
        for(i=0;i<=18,i++)
        {   
            if(isalnum(ch[i]))
            {
                p[i]=ch[i];
            }
            if(ch[i]=='+' || ch[i]=='-' || ch[i]=='*' || ch[i]='/')
            {
               
            }
            if(ch[i]=='(')
            {
                push(temp,a[i]);
            }
            if(ch[i]==')')
            {
                while(ch[i]!='(')
                {
                    p[i]=pop(temp);
                    i++;
                }
                pop(temp);
            }
           
        }



    return 0;

}