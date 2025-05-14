#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MINIMO(X,Y) ((X)>(Y)?(Y):(X))

typedef struct sNodo
{
    void*dato;
    size_t tamDato;
    struct sNodo*sig;
}tNodo;

typedef tNodo*tLista;


void crearLista(tLista*pl);
int insertarOrdLista(tLista*pl, const void*dato, size_t tam, int (*cmp)(const void*, const void*));
void vaciarLista(tLista*pl);
int compararEnteros(const void*a, const void*b);
int insertarIniLista(tLista*pl, const void*dato, size_t tam);
int sacar_de_listaIni(tLista*pl, void*dato, size_t tam);
int sacar_de_lista(tLista*pl, const void*dato, int (*cmp)(const void*, const void*));



void topN(tLista*pl, void (*accion)(const void*, void*), int top,int (*cmp)(const void*, const void*));
tNodo* buscarMenor(tLista* pl, int (*cmp)(const void*, const void*));
void imprimirEnteros(const void*dato, void *param);
void insertarDatos(tLista*pl);
#endif // MAIN_H_INCLUDED
