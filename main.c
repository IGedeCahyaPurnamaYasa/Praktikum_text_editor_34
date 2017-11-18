#include <stdio.h>
#include <stdlib.h>

typedef struct data
{
    char huruf;
    struct data *next,*prev;
}data;

void add();
void tampil();
void del();
void shift();

data *head,*next,*prev,*temp,*tail,*point;
int stts = 0,i=0,inpt;
int main()
{
    int pil;
    system("cls");
    if(stts == 0)
    {
        printf("Berapa banyak inputan : ");
        scanf("%d", &inpt);
        stts = 1;
    }
    printf("Menu : ");
    printf("\n1. Add\n2. Print\n3. Del\n4. Shift");
    printf("\n\nPilihan : ");
    scanf("%d", &pil);
    switch(pil)
    {
        case 1 : add(inpt);
                 break;
        case 2 : tampil();
                 break;
        case 3 : del();
                 break;
        case 4 : shift();
                 break;
    }
    return 0;
}

void add()
{
    if(i<inpt)
    {
        temp= (data*) malloc(sizeof(data));
        printf("\nMasukan Huruf : ");
        fflush(stdin);
        scanf("%c",&temp->huruf);
        if(head == NULL)
        {
            head = (data*) malloc(sizeof(data));
            head->next = temp;
            point = temp;
            temp->next = NULL;
            temp->prev = head;
        }

        else
        {
            if(point->next == NULL)
            {
                point->next = temp;
                temp->prev = point;
                point = temp;
                temp->next = NULL;
            }
            else if(point->next != NULL)
            {
                point->next->prev = temp;
                temp->next = point->next;
                point->next = temp;
                temp->prev = point;
                point = temp;
            }
        }
        i++;
    }
    else
    {
        printf("Input sudah maksimal");
        getch();
    }

    main();
}

void tampil ()
{
    system("cls");
    if (head == NULL)
    {
        printf("Kosong");
    }
    else
    {
        printf("\n\tData yang ada : ");
        for(temp=head->next;temp != NULL;temp=temp->next)
        {
            printf("%c", temp->huruf);
        }
    }
    getch();
    main();
}

void del()
{
    temp = point;
    if(head == NULL || head->next == NULL)
    {
        printf("Tidak ada data");
        getch();
    }
    else
    {
        printf("\n\nKarakter %c sudah dihapus\n", temp->huruf);
        if(point->next == NULL && point->prev == head)
        {
            free(temp);
            head=NULL;
        }
        else if (point->prev == head && point->next != NULL)
        {
            head->next = point->next;
            point->prev=head;
            point=point->prev;
            free(temp);
        }
        else if(point==head)
        {
            main();
        }
        else
        {
            point=point->prev;
            if(temp->next == NULL)
            {
                point->next = NULL;
            }
            else
            {
                point->next = temp->next;
                temp->next->prev = point;
            }
            free(temp);
        }
        i--;
        getch();
    }
    main();
}

void shift()
{
    int pil;
    printf("1. Shift Left\n2. Shift Right");
    printf("\nPilihan : ");
    scanf("%d", &pil);
    switch (pil)
    {
        case 1 : if(point == NULL)
                     break;
                 else if(point->prev == head || point==head)
                 {
                     point=head;
                 }
                 else
                 {
                     point=point->prev;
                 }
                 break;
        case 2 : if(point->next == NULL)
                 {
                     break;
                 }
                 else
                 {
                     point=point->next;
                 }
                 break;
    }
    main();
}
