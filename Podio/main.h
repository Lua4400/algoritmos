#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MINIMO(X,Y) ((X)>(Y)?(Y):(X))
#define TAM_NYA 50


typedef struct sNodo
{
    void*dato;
    size_t tamDato;
    struct sNodo*sig;
}tNodo;

typedef tNodo*tLista;

typedef struct
{
    char nya[TAM_NYA];
    float tiempo;
}tPersona;


//lista
void crearLista(tLista*pl);
int poner_en_listaIni(tLista*pl, const void*dato, size_t tam);
int borrar_de_lista_Dato(tLista*pl, void*dato, int (*cmp)(const void*, const void*));
void vaciarLista(tLista*pl);

int comparaTiempos(const void*a, const void*b);
void insertarDatos(tLista*pl);
void procesoPodio(tLista*pl,int (*cmp)(const void*, const void*), void (*accion)(const void*, void*));
void imprimirPers(const void*dato, void*param);
void imprimirLista(tLista*pl, void (*accion)(const void*, void*));
//busquedas
tNodo*buscarMenor(tLista*pl,int(*cmp)(const void*,const void*));
tNodo* buscarIgual(tLista*pl, const void*dato,int(*cmp)(const void*,const void*));

#endif // MAIN_H_INCLUDED
