#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TOPE 100
#define PILA_LLENA 0
#define TODO_OK 1
#define PILA_VACIA 0
#define ERROR 1
#define archBinDatos "datos.bin"

typedef struct
{
    char vec[TOPE];
    size_t tope;
}tPila;


//pila

void crearPila(tPila * pp);
int poner_en_pila(tPila *pp, const void * dato, size_t tam);
int sacar_de_pila(tPila * pp, void * dato, size_t tam);
int ver_tope(const tPila * pp, void * dato, size_t tam);
int pila_vacia(tPila * pp);

//ejercicio
int proceso(const char *archivo, tPila *pp);
int grabar_archivo(const char *archivo, tPila *pp);
void menu(const char * archivo, tPila *pp);

void mostrarArchivoBin(const char* arch);
void crearArchBin(const char * arch);
#endif // MAIN_H_INCLUDED
