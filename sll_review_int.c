#include <stdio.h>
#include <stdlib.h>

typedef struct simpul Node;
struct simpul
{
    int data;
    Node *next;
};

Node *head = NULL, *p, *tail, *hapus, *phapus;

//Fungsi Alokasi, Tampil, Bebas, dan Insert Awal
void alokasi();
void sll_insert_awal();
void tampil();
void bebas();

//Fungsi Menu
void menu_all();
void pengurutan();
void pencarian();
void penghapusan();

//Variabel Global
char ulang;
int menu_review;

int main()
{
    while(menu_review != 4)
    {
        puts("DAFTAR MENU");
        puts("1. Penambahan Secara Terurut\n2. Pencarian Data\n3. Penghapusan Data\n4. Exit");

        printf("\nPILIH MENU : ");
        scanf("%d", &menu_review);

        menu_all(menu_review);
    }

    return 0;
}

void menu_all()
{
    switch(menu_review)
    {
    case 1:
        do
        {
            puts("");
            puts("==Pengurutan Data Tertentu==");
            puts("");
            pengurutan();
            fflush(stdin);

            puts("");
            tampil();
            puts("");

            printf("Tambah Data?(y/t) : ");
            ulang = getchar();
        } while(ulang == 'y' || ulang == 'Y');
        puts("");
        puts("ISI SLL TERMUTAKHIR");
        tampil();
        puts("");
        break;

    case 2:
        do
        {
            puts("");
            puts("==Pencarian Data Tertentu==");
            puts("");
            pencarian();
            fflush(stdin);

            tampil();
            puts("Cari Data Lagi?(y/t) : ");
            ulang = getchar();
        } while(ulang == 'y' || ulang == 'Y');
        puts("");
        tampil();
        break;

    case 3:
        puts("==Hapus Tertentu==");
        puts("");

        fflush(stdin);

        if(head == NULL)
            puts("ISI SLL DULU");
        else
            penghapusan();

        puts("");
        tampil();
        break;

    default:
        puts("Alhamdulillah, Tugas Review Sukses!");
        puts("SLL TERISI");
        tampil();
    }
}

void alokasi()
{
    p = (Node *)malloc(sizeof(Node));

    if(p == NULL)
    {
        puts("Alokasi Memori Gagal!");
        exit(0);
    }
    else
    {
        printf("Nilai Yang Ingin Disimpan: ");
        scanf("%d", &p->data);

        p->next = NULL;
    }
}

void pengurutan()
{
    fflush(stdin);
    alokasi();
    fflush(stdin);

    if(head == NULL || p->data < head->data)
        sll_insert_awal();
    else
    {
        tail = head;
        while(tail->next != NULL && tail->next->data < p->data)
            tail = tail->next;
        p->next = tail->next;
        tail->next = p;
    }
}

void pencarian()
{
    int key, counter = 0;
    Node *cari;

    printf("Key Yang Dicari: ");
    scanf("%d", &key);

    cari = head;
    while(cari != NULL)
    {
        if(cari->data == key)
            counter++;
        cari = cari->next;
    }

    printf("\nKey %d Ditemukan %d Kali\n\n", key, counter);
}

void penghapusan()
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

void sll_insert_awal()
{
    if(head != NULL)
        p->next = head;
    head = p;
}

void bebas()
{
    free(hapus);
    hapus = NULL;
}

void tampil()
{
    Node *baca;
    baca = head;

    puts("==ISI SLL==");
    while(baca != NULL)
    {
        printf("%d\n", baca->data);
        baca = baca->next;
    }
}
