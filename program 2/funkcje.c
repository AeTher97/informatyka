#include<stdio.h>
#include<stdlib.h>
#include"funkcje.h"


struct lista* insert(struct lista** wezel,struct data nowe)
{
    struct lista * wskaznik;
    struct lista * aktualny_root;
    aktualny_root=(*wezel);

    int wyjscie;
    wyjscie=0;


     wskaznik = (struct lista*)malloc(sizeof(struct lista));
    if(wskaznik==NULL)
        return NULL;

    (*wskaznik).right=NULL;
    (*wskaznik).left=NULL;
    (*wskaznik).dane=nowe;



    while(wyjscie!=1)
    {

        if((**wezel).dane.nazwisko[0]=='\0')
        {

            *wezel=wskaznik;
                return 0;
        }

        if(strcmp(nowe.nazwisko,(**wezel).dane.nazwisko)>=0)
        {
                if((**wezel).right!=NULL)
                {
                *wezel=(**wezel).right;

            }
            else
            {
                (**wezel).right=wskaznik;
                wyjscie=1;
            }


        }
        if(strcmp(nowe.nazwisko,(**wezel).dane.nazwisko)<0)
        {
                if((**wezel).left!=NULL)
                {
                *wezel=(**wezel).left;

            }
            else{
                (**wezel).left=wskaznik;
                wyjscie=1;
            }

            }
    }

    (*wezel)=aktualny_root;
    return wskaznik;

}


void inOrder(struct lista * root)
{


    if((*root).left!=NULL)
        inOrder((*root).left);


        printf("imie: %s\n",(*root).dane.imie);
        printf("nazwisko: %s\n",(*root).dane.nazwisko);
        printf("numer telefonu: %s\n",(*root).dane.numer_telefonu);
        if((*root).dane.druginumer_telefonu[0]!='0')
            printf("drugi numer telefonu: %s\n",(*root).dane.druginumer_telefonu);
        printf("\n");

    if((*root).right!=NULL)
        inOrder((*root).right);

    return;

}

void wyszukaj(struct lista * root,char * nazwisko)
{


    if(strcmp((*root).dane.nazwisko,nazwisko)==0)
    {
        printf("znaleziono wpis:\n");
        printf("imie: %s\n",(*root).dane.imie);
        printf("numer: %s\n",(*root).dane.numer_telefonu);
        if((*root).dane.druginumer_telefonu[0]!='0')
            printf("drugi numer: %s\n",(*root).dane.druginumer_telefonu);
        printf("\n");
    }


    if((*root).left!=NULL)
        wyszukaj((*root).left,nazwisko);




    if((*root).right!=NULL)
        wyszukaj((*root).right,nazwisko);

    return;

}

void minimal(struct lista * root)
{
    if((*root).left!=NULL)
    {
        minimal((*root).left);
        return;
    }


        printf("znaleziono minimalny klucz: \n");
        printf("imie: %s\n",(*root).dane.imie);
        printf("nazwisko: %s\n",(*root).dane.nazwisko);
        printf("numer telefonu: %s\n",(*root).dane.numer_telefonu);
        if((*root).dane.druginumer_telefonu[0]!='0')
            printf("drugi numer telefonu: %s\n",(*root).dane.druginumer_telefonu);
        printf("\n");

    return;

}

int liczba_wezlow(struct lista * root)
{
    int wynik=1;
    if((*root).left!=NULL)
    {
        wynik=wynik+liczba_wezlow((*root).left);
    }
    if((*root).right!=NULL)
    {
        wynik=wynik+liczba_wezlow((*root).right);
    }

    if((*root).left==NULL && (*root).right==NULL)
        return 1;

    return wynik;

}


int wysokosc_drzewa(struct lista * root)
{
    int wynik1=0;
    int wynik2=0;


    if((*root).left!=NULL)
    {
        wynik1=wysokosc_drzewa((*root).left);
    }
    if((*root).right!=NULL)
    {
        wynik2=wysokosc_drzewa((*root).right);
    }

    if((*root).left==NULL && (*root).right==NULL)
        return 1;


    if(wynik1>=wynik2)
        return wynik1+1;

    if(wynik2>wynik1)
        return wynik2+1;


    return 0;

}

void usuwanie(struct lista *root)
{

    if((*root).right!=NULL)
        usuwanie((*root).right);
    if((*root).left!=NULL)
        usuwanie((*root).left);

    if((*root).right==NULL && (*root).left==NULL)
        free(root);

    return;
}

void maximal(struct lista * root)
{
    if((*root).right!=NULL)
    {
        maximal((*root).right);
        return;
    }

        printf("znaleziono maksymalny klucz: \n");
        printf("imie: %s\n",(*root).dane.imie);
        printf("nazwisko: %s\n",(*root).dane.nazwisko);
        printf("numer telefonu: %s\n",(*root).dane.numer_telefonu);
        if((*root).dane.druginumer_telefonu[0]!='0')
            printf("drugi numer telefonu: %s\n",(*root).dane.druginumer_telefonu);
        printf("\n");



}

