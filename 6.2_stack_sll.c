#include <stdio.h>
#include <stdlib.h>

typedef int itemType;

typedef struct simpul
{
    itemType data;
    struct simpul *next;
} Node;

typedef struct
{
    Node *head;
} stack;

void init_stack(stack *s);
int is_empty(stack *s);

void push_data(itemType x, stack *s);
itemType pop_data(stack *s);
void show_data(stack *s);

void menu_stack(stack *s);

//Variabel Global
Node *p, *hapus;
char ulang;
int pilih_stack;
itemType data_stack;

int main()
{
    stack tumpukan;
    init_stack(&tumpukan);

    while(menu_stack != 4)
    {
        puts("==DAFTAR MENU STACK SLL==");
        puts("1. Push Data\n2. Pop Data\n3. Tampil Data\n4. Exit");

        printf("\nPILIH MENU : ");
        scanf("%d", &pilih_stack);
        fflush(stdin);

        menu_stack(&tumpukan);
    }

    return 0;
}

void menu_stack(stack *s)
{
    switch(pilih_stack)
    {
    case 1:
        puts("\n===1. PUSH DATA===");
        printf("Data Yang Mau di-PUSH : ");
        scanf("%d", &data_stack);

        puts("");

        push_data(data_stack, s);

        break;

    case 2:
        puts("");

        puts("\n===2. POP DATA===");
        pop_data(s);

        break;

    case 3:
        puts("\n===3. TAMPIL DATA===");

        show_data(s);
        break;

    default:
        puts("Terimakasih");
    }
}

void init_stack(stack *s)
{
    s->head = NULL;
}

int is_empty(stack *s)
{
    return (s->head == NULL);
}

void push_data(itemType nilai, stack *s)
{
    p = (Node *)malloc(sizeof(Node));

    if(p == NULL)
    {
        puts("Alokasi Memori Gagal!\n");
        return;
    } else
    {
        p->data = nilai;

        p->next = s->head;
        s->head = p;
    }
}

itemType pop_data(stack *s)
{
    if(is_empty(s))
    {
        puts("Stack Kosong, Isi SLL Dulu!\n");
        return;
    } else
    {
        hapus = s->head;
        itemType data_hapus = hapus->data;

        s->head = hapus->next;

        free(hapus);
        return hapus;
    }
}

void show_data(stack *s)
{
    Node *baca;
    baca = s->head;

    puts("==Isi Stack==");
    if(is_empty(s))
    {
        puts("Stack Kosong!\n");
        return;
    } else
    {
        while(baca != NULL)
        {
            printf("%d\n", baca->data);
            baca = baca->next;
        }
        puts("");
    }
}
