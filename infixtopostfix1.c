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
{   
    char item;
    if(!isEmpty(s))
    {
        item=s->array[s->top];
        s->top--;  
        return item;  
    }
    return '\0';
}

int precedence(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':
                 return 1;
        case '*':
        case '/':
                 return 2;
        case '^':
                 return 3;
    }
    return -1;
}

void infixToPostfix(char *ch)
{   
    struct ArrayStack *temp;
    int i=0,j=0;
    push(temp,'(');
    char p[20];
    while(ch[i]!='\0')
    {   
        if(isalnum(ch[i]))
        {
            p[j]=ch[i];
            j++;
        }
        else if(ch[i]=='(')
        {
            push(temp,ch[i]);
        }
        else if(ch[i]==')')
        {
            while(temp->array[temp->top]!='(' && !isEmpty(temp))
            {
                p[j]=pop(temp);
                j++;
            }
            if(temp->array[temp->top]=='(')
            {
                pop(temp);
            }
        }
        else
        {
            while(precedence(ch[i])<=precedence(temp->array[temp->top]) && !isEmpty(temp))
            {
                p[j]=pop(temp);
                j++;
            }
            push(temp,ch[i]);
        }
        i++;
    }
    while(temp->array[temp->top]!='(' && !isEmpty(temp))
    {
        p[j]=pop(temp);
        j++;
    }
    p[j]='\0';
    for(i=0;p[i]!='\0';i++)
    {
    printf("%c",p[i]);
    }
}

int main()
{   
    char ch[20];
    printf("Enter the infix expression: ");
    gets(ch);
    infixToPostfix(ch);
    return 0;
} 
