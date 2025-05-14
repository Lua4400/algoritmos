#include "main.h"

void crearLista(tLista*pl)
{
    *pl=NULL;
}

int insertarOrdLista(tLista*pl, const void*dato, size_t tam, int (*cmp)(const void*, const void*))
{
    tNodo*nue;
    int men;
    while(*pl && (men= cmp(dato, (*pl)->dato))>0)
    {
        pl = &(*pl)->sig;
    }
    nue = (tNodo*)malloc(sizeof(tNodo));
    if(!nue)
        return 0;
    nue->dato = malloc(tam);
    if(!nue->dato)
    {
        free(nue);
        return 0;
    }
    nue->tamDato = tam;
    memcpy(nue->dato, dato, tam);
    nue->sig = *pl;
    *pl = nue;
    return 1;
}
int insertarIniLista(tLista*pl, const void*dato, size_t tam)
{
    tNodo*nue = (tNodo*)malloc(sizeof(tNodo));
    if(!nue)
        return 0;
    nue->dato = malloc(tam);
    if(!nue->dato)
    {
        free(nue);
        return 0;
    }
    nue->tamDato = tam;
    memcpy(nue->dato, dato, tam);
    nue->sig = *pl;
    *pl = nue;
    return 1;
}
int sacar_de_listaIni(tLista*pl, void*dato, size_t tam)
{
    tNodo*elim = *pl;
    if(!pl)
        return 0;
    memcpy(dato, elim->dato, MINIMO(tam, elim->tamDato));
    *pl = elim->sig;
    free(elim);
    free(elim->dato);
    return 1;
}
int sacar_de_lista(tLista*pl, const void*dato, int (*cmp)(const void*, const void*))
{
    tNodo*elim;

    while(*pl)
    {
        if(cmp((*pl)->dato, dato)==0)
        {
            elim = *pl;
            *pl = elim->sig;
            free(elim->dato);
            free(elim);
            return 1;
        }
        pl = &(*pl)->sig;
    }
    return 0;
}
void vaciarLista(tLista*pl)
{
    tNodo * elim;
    while(*pl)
    {
        elim = *pl;
        *pl = elim->sig;
        free(elim->dato);
        free(elim);
    }
}

int compararEnteros(const void*a, const void*b)
{
    return (*(int*)a-*(int*)b);
}

void topN(tLista*pl, void (*accion)(const void*, void*), int top,int (*cmp)(const void*, const void*))
{
    int TopN =0;
    tNodo * men;

    while(TopN< top)
    {
        men = buscarMenor(pl,cmp);
        if(men)
        {
            accion(men->dato,NULL);
            sacar_de_lista(pl, men->dato, cmp); //lo tengo q sacar d lista xq sino se me queda repetido para las otras busquedas
            TopN++;
        }
    }
}
void topNSinDupli(tLista*pl, void (*accion)(const void*, void*), int top,int (*cmp)(const void*, const void*))
{
    int TopN =0;
    tNodo * men;

    while(*pl && TopN< top)
    {
        men = buscarMenor(pl,cmp);
        if(men)
        {
            accion(men->dato,NULL);
            sacar_de_lista(pl, men->dato, cmp); //lo tengo q sacar d lista xq sino se me queda repetido para las otras busquedas
            TopN++;
        }
    }
}

tNodo* buscarMenor(tLista* pl, int (*cmp)(const void*, const void*))
{
    if (!pl || !*pl)
        return NULL;

    tNodo* menor = *pl; //pongo el primer ele como el menor

    while(*pl)
    {
        if (cmp((*pl)->dato, menor->dato) < 0) {
            menor = *pl;
        }
        pl = &(*pl)->sig;
    }
    return menor;
}


void imprimirEnteros(const void*dato, void* param)
{
    printf("%d ", *(int*)dato);
}

void insertarDatos(tLista*pl)
{
    int n=10;
    int vec[10] = {8,9,1,2,6,2,4,8, 5, 7};

    for(int i=0; i<n; i++)
    {
        insertarIniLista(pl, &vec[i], sizeof(int));
    }
}
