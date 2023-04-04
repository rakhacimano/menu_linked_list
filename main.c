#include <stdio.h>
#include <stdlib.h>

typedef struct simpul DNode;
struct simpul
{
    int data;
    DNode *prev, *next;
};

DNode *head = NULL, *p, *tail, *after, *before, *hapus;

//Fungsi Alokasi & Tampil
void alokasi();
void tampil();

//Fungsi Insert
void dll_list_insert();
void dll_insert_awal();
void dll_insert_akhir();
void dll_insert_after();
void dll_insert_before();

int main()
{
    int *menu_dll, *dll_menu_insert;
    char *ulang;

    while(menu_dll != 3)
    {
        puts("DAFTAR MENU");
        puts("1. Insert\n2. Exit\n");

        printf("\nPILIH MENU : ");
        scanf("%d", &menu_dll);

        dll_list_insert(menu_dll, dll_menu_insert, ulang);

        //MENU DLL == 2 AKAN KELUAR / EXIT
        if(menu_dll == 2)
        {
            puts("Terimakasih Telah Menggunakan Program DLL");
            exit(0);
        }
    }

    return 0;
}

void dll_list_insert(menu_dll, dll_menu_insert, ulang)
{
    if(menu_dll == 1)
    {
        puts("\n==MENU INSERT==");
        puts("1. Insert Awal\n2. Insert Akhir\n3. Insert After\n4. Insert Before\n5. Exit");
        printf("\nPILIH MENU INSERT: ");
        scanf("%d", &dll_menu_insert);

        switch(dll_menu_insert)
        {
            case 1:
                do
                {
                    fflush(stdin);
                    dll_insert_awal();
                    fflush(stdin);

                    printf("Ulang?(y/t) : ");
                    ulang = getchar();
                } while(ulang == 'y' || ulang == 'Y');
                puts("");
                tampil();
                puts("");
                break;

            case 2:
                do
                {
                    fflush(stdin);
                    dll_insert_akhir();
                    fflush(stdin);

                    printf("Ulang?(y/t) : ");
                    ulang = getchar();
                } while(ulang == 'y' || ulang == 'Y');
                puts("");
                tampil();
                puts("");
                break;

            case 3:
                if(head == NULL)
                    puts("\n==ISI DLL DULU==\n");
                else
                {
                    fflush(stdin);
                    dll_insert_after();
                    fflush(stdin);

                    puts("");
                    tampil();
                    puts("");
                }

                break;

            case 4:
                if(head == NULL)
                    puts("\n==ISI DLL DULU==\n");
                else
                {
                    fflush(stdin);
                    dll_insert_before();
                    fflush(stdin);

                    puts("");
                    tampil();
                    puts("");
                }

                break;

            case 5:
                puts("==Terimakasih Telah Mengisi DLL==");
                exit(0);
                break;

            default:
                printf("\nMenu %d Tidak ada Dalam Daftar!\n\n", dll_menu_insert);
                break;
        }
    }
}

// FUNGSI INSERT DIMULAI DI SINI
void dll_insert_awal()
{
    alokasi();

    if(head != NULL)
    {
        p->next = head;
        head->prev = p;
    }
    head = p;
}

void dll_insert_akhir()
{
    alokasi();

    tail = head;

    if(head == NULL)
        head = p;
    else
    {
        while(tail->next != NULL)
            tail = tail->next;
        p->prev = tail;
        tail->next = p;
        tail = p;
    }
}

void dll_insert_after()
{
    alokasi();

    int key;

    printf("Disisipkan AFTER Node Berapa? : ");
    scanf("%d", &key);

    after = head;

    while(after->data != key)
    {
        if(after->next == NULL)
        {
            printf("Node %d Tidak Ada Dalam DLL!", key);
            exit(0);
        }
        else
            after = after->next;
    }
    if(after->next != NULL)
    {
        p->next = after->next;
        after->next->prev = p;
    }
    p->prev = after;
    after->next = p;
}

void dll_insert_before()
{
    alokasi();

    int key;

    printf("Disisipkan BEFORE Node Berapa? : ");
    scanf("%d", &key);

    before = head;

    if(before->data == key)
    {
        if(head != NULL)
        {
            p->next = head;
            head->prev = p;
        }
        head = p;
    }
    else
    {
        while(before->data != key)
        {
            if(before->next == NULL)
            {
                printf("Node %d Tidak Ada Dalam DLL!", key);
                exit(0);
            }
            else
                before = before -> next;
        }
        p->next = before;
        p->prev = before->prev;
        before->prev->next = p;
        before->prev = p;
    }
}
// FUNGSI INSERT SELESAI DI SINI

void alokasi()
{
    p = (DNode *)malloc(sizeof(DNode));

    if(p == NULL)
    {
        puts("Alokasi Memori Gagal!");
        exit(0);
    } else
    {
        printf("Nilai Yang Ingin Disimpan : ");
        scanf("%d", &p->data);

        p->next = NULL;
        p->prev = NULL;
    }
}

void tampil()
{
    DNode *baca;

    puts("===Isi DLL===");

    baca = head;
    while(baca != NULL)
    {
        printf("%d\n", baca->data);
        baca = baca->next;
    }
}
