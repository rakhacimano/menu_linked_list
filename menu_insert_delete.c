#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul
{
    int data;
    Node *next;
};

Node *head = NULL, *p, *bef, *pbef, *hapus, *phapus, *tail, *after;

void alokasi();

//Fungsi Insert
void awal();
void akhir();
void setelah();
void sebelum();

//Fungsi Delete
void delete_awal();
void delete_akhir();
void delete_tertentu();

void list_insert();
void list_delete();

int main()
{
    int *menu_sll, *menu_insert, *menu_delete;
    char *ulang;

    while(menu_sll != 3)
    {
        puts("DAFTAR MENU");
        puts("1. Insert\n2. Delete\n3. Exit");

        printf("\nPILIH MENU : ");
        scanf("%d", &menu_sll);

        list_insert(menu_sll);
        list_delete(menu_sll, menu_delete, ulang);
    }

    return 0;
}

void list_delete(menu_sll, menu_delete, ulang)
{
    if(menu_sll == 2)
    {
        puts("\n==MENU DELETE==");
        puts("1. Delete Awal\n2. Delete Akhir\n3. Delete Tertentu\n4. Exit");
        printf("\nPILIH MENU DELETE: ");
        scanf("%d", &menu_delete);

        switch(menu_delete)
        {
        case 1:
            puts("Hapus Awal: ");
            delete_awal();
            break;
        case 2:
            puts("Hapus Akhir: ");
            delete_akhir();
            break;
        case 3:
            puts("Hapus Tertentu: ");
            fflush(stdin);
            delete_tertentu();
            break;
        case 4:
            puts("Terimakasih Telah Bekerja dengan SLL");
            exit(0);
            break;
        default:
            printf("\nMenu %d Tidak ada Dalam Daftar!\n\n", menu_delete);
            break;
        }
        tampil();
    }
}

void list_insert(menu_sll, menu_insert, ulang)
{
    if(menu_sll == 1)
    {
        puts("\n==MENU INSERT==");
        puts("1. Insert Awal\n2. Insert Akhir\n3. Insert After\n4. Insert Before\n5. Exit");
        printf("\nPILIH MENU INSERT: ");
        scanf("%d", &menu_insert);

        switch(menu_insert)
        {
        case 1:
            do
            {
                fflush(stdin);
                alokasi();
                awal();
                fflush(stdin);

                printf("Lanjut? (y/t): ");
                ulang = getchar();

            }
            while(ulang == 'y' || ulang == 'Y');
            tampil();
            puts("");
            break;

        case 2:
            do
            {
                fflush(stdin);
                alokasi();
                akhir();
                fflush(stdin);

                printf("Lanjut? (y/t): ");
                ulang = getchar();

            }
            while(ulang == 'y' || ulang == 'Y');
            tampil();
            puts("");
            break;

        case 3:
            do
            {
                fflush(stdin);
                setelah();
                fflush(stdin);

                printf("Lanjut? (y/t): ");
                ulang = getchar();

            }
            while(ulang == 'y' || ulang == 'Y');
            tampil();
            puts("");
            break;

        case 4:
            do
            {
                fflush(stdin);
                sebelum();
                fflush(stdin);

                printf("Lanjut? (y/t): ");
                ulang = getchar();

            }
            while(ulang == 'y' || ulang == 'Y');
            tampil();
            puts("");
            break;

        case 5:
            puts("Terimakasih Telah Mengisi SLL");
            exit(0);
            break;

        default:
            printf("\nMenu %d Tidak ada Dalam Daftar!\n\n", menu_insert);
            break;
        }
    }
}

void alokasi()
{
    int nilai;

    p = (Node *)malloc(sizeof(Node));
    printf("Nilai Yang Ingin Disimpan: ");
    scanf("%d", &nilai);

    if(p == NULL)
    {
        puts("Alokasi Memori Gagal!");
        exit(0);
    }
    else
    {
        p->data = nilai;
        p->next = NULL;
    }
}

void awal()
{
    if(head != NULL)
        p->next = head;
    head = p;
}

void akhir()
{
    if(head == NULL)
    {
        head = p;
    }
    else
    {
        tail = head;
        while(tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = p;
    }
}

void setelah()
{
    int key;

    alokasi();
    printf("Disisipkan Setelah Node: ");
    scanf("%d", &key);

    after = head;
    while(after->data != key)
    {
        if(after->next != NULL)
        {
            after = after->next;
        }
        else
        {
            printf("%d Tidak Ada dalam SLL!", key);
            exit(0);
        }
    }

    p->next = after->next;
    after->next = p;
}

void sebelum()
{
    int key;

    alokasi();
    printf("Disisipkan Sebelum Node: ");
    scanf("%d", &key);

    bef = head;
    if(bef->data == key)
    {
        awal();
    }
    else
    {
        while(bef->data != key)
        {
            if(bef->next == NULL)
            {
                printf("%d Tidak Ada di SLL!", key);
                exit(0);
            }
            else
            {
                pbef = bef;
                bef = bef->next;
            }
        }
        p->next = bef;
        pbef->next = p;
    }

}

void delete_awal()
{
    hapus = head;
    if(hapus == NULL)
    {
        puts("Input SLL Dulu!");
    }
    else
    {
        if(hapus->next == NULL)
        {
            head = NULL;
        }
        else
        {
            head = hapus->next;
            bebas();
        }
    }
}

void delete_akhir()
{
    hapus = head;
    if(hapus->next == NULL)
    {
        delete_awal();
    }
    else
    {
        while(hapus->next != NULL)
        {
            phapus = hapus;
            hapus = hapus->next;
        }
        phapus->next = NULL;
        bebas();
    }
}

void delete_tertentu()
{
    int key;

    printf("\nNode yang ingin dihapus: ");
    scanf("%d", &key);

    hapus = head;
    if(hapus->data == key)
    {
        head = hapus->next;
        bebas();
    }
    else
    {
        while(hapus->data != key)
        {
            if(hapus->next == NULL)
            {
                printf("%d Tidak ada dalam SLL!", key);
                exit(0);
            }
            else
            {
                phapus = hapus;
                hapus = hapus->next;
            }
        }
        phapus->next = hapus->next;
        bebas();
    }
}

void bebas()
{
    free(hapus);
    hapus = NULL;
}

void tampil()
{
    Node *baca;

    puts("Isi dari SLL: ");

    baca = head;
    while(baca != NULL)
    {
        printf("%d\n", baca->data);
        baca = baca->next;
    }
}
