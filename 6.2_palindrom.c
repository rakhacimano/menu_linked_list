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

void init_stack(stack *s);
int is_empty(stack *s);
int is_full(stack *s);
void push_data(itemType x, stack *s);
itemType pop_data(stack *s);

void input_string(char *string);

itemType top(stack *s);
int is_palindrome(char *string);

stack tumpukan;

int main()
{
    char string[MAKS];
    char ulang;

    puts("PROGRAM CEK PALINDROME");
    puts("DENGAN MEMANFAATKAN STRUKTUR STACK\n");

    do
    {
        input_string(string);

        fflush(stdin);

        printf("Ulang?(y/t) : ");
        ulang = getchar();
        puts("");
    }
    while(ulang == 'y' || ulang == 'Y');

    return 0;
}

void input_string(char *string)
{
    fflush(stdin);
    printf("Masukkan sebuah string : ");
    fgets(string, MAKS, stdin);
    string[strcspn(string, "\n")] = '\0';

    if (is_palindrome(string))
    {
        printf("'%s' adalah palindrome.\n\n", string);
    }
    else
    {
        printf("'%s' bukan palindrome.\n\n", string);

    }
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

int is_palindrome(char *string)
{
    int i, len;
    init_stack(&tumpukan);
    len = strlen(string);

    for (i = 0; i < len; i++)
    {
        push_data(string[i], &tumpukan);
    }

    for (i = 0; i < len; i++)
    {
        if (string[i] != pop_data(&tumpukan))
        {
            return 0;
        }
    }

    return 1;
}
