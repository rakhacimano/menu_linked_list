#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef int itemType;
typedef struct
{
    itemType data[MAX];
    int count;
} stack;

void inisialisasi(stack *s);
int is_empty(stack *s);
int is_full(stack *s);
void push_data(itemType value, stack *s);
itemType pop_data(stack *s);

void desimal_to_biner(int desimal);
void desimal_to_oktal(int desimal);
void desimal_to_heksa(int desimal);

void menu_konversi(desimal, pilihan);

int main()
{
    int desimal, pilihan;
    char ulang;

    do
    {
        fflush(stdin);
        printf("Masukkan Angka Desimal : ");
        scanf("%d", &desimal);

        puts("\nPILIH KONVERSI  KE : ");
        puts("Menu Konversi\n1. BINER\n2. OKTAL\n3. HEKSA\n4. KELUAR\n");

        printf("Masukkan Pilihan Anda : ");
        scanf("%d", &pilihan);

        puts("");
        menu_konversi(desimal, pilihan);

        fflush(stdin);
        printf("\nUlang?(y/t) : ");
        ulang = getchar();
        puts("");

    } while(ulang == 'y' || ulang == 'Y');

    return 0;
}

menu_konversi(desimal, pilihan)
{
    if(pilihan == 1)
        desimal_to_biner(desimal);
    else if(pilihan == 2)
        desimal_to_oktal(desimal);
    else if(pilihan == 3)
        desimal_to_heksa(desimal);
    else
        exit(0);
}

void inisialisasi(stack *s)
{
    s->count = 0;
}

int is_empty(stack *s)
{
    return s->count == 0;
}

int is_full(stack *s)
{
    return s->count == MAX;
}

void push_data(itemType value, stack *s)
{
    if (is_full(s))
    {
        puts("Stack is full");
    }
    else
    {
        s->data[s->count] = value;
        s->count++;
    }
}

itemType pop_data(stack *s)
{
    if (is_empty(s))
    {
        puts("Stack is empty");
        return -1;
    }
    else
    {
        s->count--;
        return s->data[s->count];
    }
}

void desimal_to_biner(int desimal)
{
    int sisa_bagi;
    stack biner;
    inisialisasi(&biner);

    int sisa = desimal;
    while (sisa != 0)
    {
        sisa_bagi = sisa % 2;
        push_data(sisa_bagi, &biner);
        sisa /= 2;
    }

    printf("biner: ");
    while (!is_empty(&biner))
    {
        printf("%d", pop_data(&biner));
    }
    printf("\n");
}

void desimal_to_oktal(int desimal)
{
    stack oktal;
    inisialisasi(&oktal);

    int sisa = desimal;
    while (sisa != 0)
    {
        int sisa_bagi = sisa % 8;
        push_data(sisa_bagi, &oktal);
        sisa /= 8;
    }

    printf("oktal: ");
    while (!is_empty(&oktal))
    {
        printf("%d", pop_data(&oktal));
    }
    printf("\n");
}

void desimal_to_heksa(int desimal)
{
    stack nilai_heks;
    inisialisasi(&nilai_heks);

    int sisa = desimal;
    while (sisa != 0)
    {
        int sisa_bagi = sisa % 16;
        if (sisa_bagi < 10)
        {
            push_data(sisa_bagi + '0', &nilai_heks);
        }
        else
        {
            push_data(sisa_bagi - 10 + 'A', &nilai_heks);
        }
        sisa /= 16;
    }

    printf("heksa: ");
    while (!is_empty(&nilai_heks))
    {
        printf("%c", pop_data(&nilai_heks));
    }
    printf("\n");
}
