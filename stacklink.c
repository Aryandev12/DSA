#include<stdio.h>
#include<stdlib.h>

//self referential structure.
struct Stack{
    int info;
    struct Stack *next;
};

struct Stack *createstack(){
    struct Stack *stack;
    stack = (struct Stack *)malloc(sizeof(struct Stack));
    return stack;
}

void push(struct Stack **s, int data) {
    struct Stack *temp, *t;
    temp = createstack();
    temp->next = NULL;
    temp->info = data;
    t = *s;
    if (*s == NULL)
        *s = temp;
    else {
        temp->next = *s;
        *s = temp;
    }
}

int pop(struct Stack **s) {
    struct Stack *r;
    int k;
    if (*s == NULL) {
        printf("UNDERFLOW\n");
        return 0;
    } else {
        r = *s;
        k = r->info;
        *s = r->next;
        r->next = NULL;
        free(r);
        return k;
    }
}

int menu() {
    int ch;
    printf("\n1. Push a number");
    printf("\n2. Pop a number");
    printf("\n3. Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &ch);
    return ch;
}

int main() {
    int k, item=0;
    struct Stack *stack;
    stack = createstack();
    while (1) {
        switch (menu()) {
            case 1:
                printf("Enter the number you want to push: ");
                scanf("%d", &k);
                push(&stack, k);
                break;
            case 2:
                printf("Pop item: ");
                item = pop(&stack);
                printf("%d",item);
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("\nInvalid Choice\n");
        }
    }
    return 0;
}
