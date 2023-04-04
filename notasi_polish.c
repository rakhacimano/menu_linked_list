#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAKS 100

typedef char itemType;
typedef struct
{
    itemType data[MAKS];
    int count;
} stack;

void infix_to_postfix(char *infix, char *postfix);

void init_stack(stack *s);
int is_empty(stack *s);
int is_full(stack *s);
void push_data(itemType x, stack *s);
itemType pop_data(stack *s);

itemType top(stack *s);

int is_operator(char c);
int is_priority(char operator1, char operator2);

stack tumpukan;

int main()
{
    char infix[MAKS], postfix[MAKS];
    char ulang;

    puts("MENGUBAH NOTASI INFIX MENJADI POSTFIX");
    puts("DENGAN MEMANFAATKAN STRUKTUR STACK\n");

    do
    {
        fflush(stdin);
        printf("Ekspresi Infix : ");
        fgets(infix, MAKS, stdin);

        infix_to_postfix(infix, postfix);

        puts("");

        printf("Ungkapan Postfix : %s\n\n", postfix);
        fflush(stdin);

        printf("Ulang?(y/t) : ");
        ulang = getchar();
        puts("");
    }
    while(ulang == 'y' || ulang == 'Y');

    return 0;
}

void infix_to_postfix(char *infix, char *postfix)
{
    int i = 0, j = 0;

    init_stack(&tumpukan);

    while (infix[i] != '\0')
    {
        if (infix[i] == ' ' || infix[i] == '\t' || infix[i] == '\n')
        {
            i++;
            continue;
        }
        if (infix[i] >= '0' && infix[i] <= '9')
        {
            postfix[j++] = infix[i];
            while (infix[i + 1] >= '0' && infix[i + 1] <= '9')
            {
                i++;
                postfix[j++] = infix[i];
            }
            postfix[j++] = ' ';
        }

        else if (is_operator(infix[i]))
        {
            while (!is_empty(&tumpukan) && top(&tumpukan) != '(' && is_priority(top(&tumpukan), infix[i]))
            {
                postfix[j++] = pop_data(&tumpukan);
                postfix[j++] = ' ';
            }
            push_data(infix[i], &tumpukan);
        }
        else if (infix[i] == '(')
        {
            push_data(infix[i], &tumpukan);
        }
        else if (infix[i] == ')')
        {
            while (!is_empty(&tumpukan) && top(&tumpukan) != '(')
            {
                postfix[j++] = pop_data(&tumpukan);
                postfix[j++] = ' ';
            }
            if (!is_empty(&tumpukan) && top(&tumpukan) == '(')
            {
                pop_data(&tumpukan);
            }
            else
            {
                printf("Kurung tidak seimbang\n");
                return;
            }
        }
        else
        {
            printf("Input tidak valid\n");
            return 0;
        }
        i++;
    }

    while (!is_empty(&tumpukan))
    {
        if (top(&tumpukan) == '(')
        {
            printf("Kurung tidak seimbang\n");
            return;
        }
        postfix[j++] = pop_data(&tumpukan);
        postfix[j++] = ' ';
    }

    postfix[j] = '\0';

}

void init_stack(stack *s)
{
    s->count = 0;
}

int is_empty(stack *s)
{
    return s->count == 0 ? 1 : 0;
}

int is_full(stack *s)
{
    return s->count == MAKS ? 1 : 0;
}

void push_data(itemType x, stack *s)
{
    if (is_full(s))
    {
        printf("Stack penuh, data tidak dapat disimpan.\n");
    }
    else
    {
        s->data[s->count] = x;
        s->count++;
    }
}

itemType pop_data(stack *s)
{
    itemType temp;

    if (is_empty(s))
    {
        printf("Stack kosong, push data terlebih dahulu\n");
    }
    else
    {
        --(s->count);
        temp = s->data[s->count];
        return temp;
    }
}

itemType top(stack *s)
{
    return s->data[s->count - 1];
}

int is_operator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int is_priority(char operator1, char operator2)
{
    if (operator1 == '+' || operator1 == '-')
    {
        return operator2 == '+' || operator2 == '-' ? 1 : 0;
    }
    else if (operator1 == '*' || operator1 == '/')
    {
        return operator2 == '+' || operator2 == '-' ? 1 : (operator2 == '*' || operator2 == '/' ? 1 : 0);
    }
    else if (operator1 == '^')
    {
        return operator2 == '+' || operator2 == '-' || operator2 == '*' || operator2 == '/' ? 1 : 0;
    }
    return 0;
}
