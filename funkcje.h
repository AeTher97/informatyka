#ifndef FUNKCJE_H
#define FUNKCJE_H

struct data{

    char imie[50];
    char nazwisko[50];
    char numer_telefonu[9];
    char druginumer_telefonu[9];


};

int strcmp(char*cost, char *dfds);

struct lista{
    struct lista* right;
    struct lista* left;
    struct data dane;
};


struct lista* insert(struct lista** wezel,struct data nowe);

void inOrder(struct lista * root);

void wyszukaj(struct lista * root,char * nazwisko);

void minimal(struct lista * root);

int liczba_wezlow(struct lista * root);

int wysokosc_drzewa(struct lista * root);

void usuwanie(struct lista *root);

void maximal(struct lista * root);

#endif
