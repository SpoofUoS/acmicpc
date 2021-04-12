#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STACK_SIZE 100

typedef char element;
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

void init_stack(StackType *s) // 스택 초기화 함수
{
    s->top = -1;
}

int is_empty(StackType *s)  // 공백 상태 검출 함수
{
    return (s->top == -1);
}

int is_full(StackType *s)  // 포화 상태 검출 함수 
{
    return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType *s, element item)  // 삽입 함수
{
    if (is_full(s)) {
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else s->data[++(s->top)] = item;
}

element pop(StackType *s) // 삭제 함수
{
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return s->data[(s->top)--];
}

element peek(StackType *s)  // 피크 함수
{
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return s->data[s->top];
}

int main()
{
    StackType s1;
    StackType s2;

    char x, y;
    int num = 0;
    int n;


    init_stack(&s1);
    init_stack(&s2);

    char str[50];

    scanf("%s", &str);
    for (int i = 0; i < strlen(str); i++)
    {
        push(&s1, str[i]);
    }

    while(!is_empty(&s1))
    {
        x = pop(&s1);
        if (x == '(')
        {
            y = pop(&s2);
            while(y != ')'){
                num++;
                y = pop(&s2);
            }
            n = pop(&s1);
            num *= (n-48);
        }
        else push(&s2, x);
    }
    while(!is_empty(&s2))
    {
        pop(&s2);
        num++;
    }
    printf("%d", num);
}