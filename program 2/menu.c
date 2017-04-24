#include<stdio.h>
#include<stdlib.h>
#include"funkcje.h"
#include"menu.h"


int program()
{

    struct data dane;
    struct lista * root;
    root=NULL;
    int wybor;
    wybor=0;
    char nazwisko_do_wyszukania[50];

    root=(struct lista*)malloc(sizeof(struct lista));
    if(root==NULL)
        return -1;

    (*root).right=NULL;
    (*root).left=NULL;
    (*root).dane.nazwisko[0]='\0';

    while(wybor!=-1)
    {

        printf("wybierz funkcje: \n");
        printf("1-wprowadz dane\n");
        printf("2-wypisz cale drzewo\n");
        printf("3-wyszukaj minimum\n");
        printf("4-wyszukaj maksimum\n");
        printf("5-zlicz wezly\n");
        printf("6-wyszukaj wezel\n");
        printf("7-sprawdz wysokosc drzewa\n");
        printf("8-wyjscie\n");
        scanf("%i",&wybor);

        if(wybor==1)
        {
            printf("imie: ");
            scanf("%s",dane.imie);
            printf("nazwisko: ");
            scanf("%s",dane.nazwisko);
            printf("numer telefonu: ");
            scanf("%s",dane.numer_telefonu);
            printf("drugi numer telefonu, jesli osoba go nie posiada, wpisz 0: ");
            scanf("%s",dane.druginumer_telefonu);

           insert(&root,dane);
        }

        if(wybor==2)
        {
            inOrder(root);
            printf("\n");
        }
        if(wybor==3)
        {
            minimal(root);
        }
        if(wybor==4)
        {
            maximal(root);
        }
        if(wybor==5)
        {
            printf("liczba wezlow: %i\n\n",liczba_wezlow(root));

        }
        if(wybor==6)
        {
            printf("podaj nazwisko: ");
            scanf("%s",nazwisko_do_wyszukania);
            wyszukaj(root,nazwisko_do_wyszukania);
        }
        if(wybor==7)
        {
            printf("wysokosc drzewa to: %i\n\n",wysokosc_drzewa(root));
        }
        if(wybor==8)
        {
            wybor=-1;
        }

    }


    usuwanie(root);
    return 0;
}
