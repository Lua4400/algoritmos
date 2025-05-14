#include "main.h"

void crearLista(tLista*pl)
{
    *pl=NULL;
}
int poner_en_listaIni(tLista*pl, const void*dato, size_t tam)
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
    nue->tamDato=tam;
    memcpy(nue->dato, dato, tam);
    nue->sig = *pl;
    *pl =nue;
    return 1;
}

int borrar_de_lista_Dato(tLista*pl, void*dato, int (*cmp)(const void*, const void*))
{
    tNodo*elim;

    while(*pl && (cmp((*pl)->dato, dato)!=0))
    {
        pl = &(*pl)->sig;
    }
    elim = *pl;
    if(!elim)
        return 0;
    *pl = elim->sig;
    free(elim->dato);
    free(elim);
    return 1;
}

void vaciarLista(tLista*pl)
{
    tNodo*elim;
    while(*pl)
    {
        elim = *pl;
        *pl = elim->sig;
        free(elim->dato);
        free(elim);
    }
}

/*int comparaTiempos(const void*a, const void*b)
{
    tPersona*p1 = (tPersona*)a;
    tPersona *p2=(tPersona*)b;
    return (p1->tiempo-p2->tiempo);
}*/
int comparaTiempos(const void* a, const void* b)
{
    tPersona* p1 = (tPersona*)a;
    tPersona* p2 = (tPersona*)b;

    if (p1->tiempo < p2->tiempo)
        return -1;
    else if (p1->tiempo > p2->tiempo)
        return 1;
    else
        return 0;
}


void procesoPodio(tLista*pl,int (*cmp)(const void*, const void*),void (*accion)(const void*, void*))
{
    tNodo* menor, *iguales;
    int cont=1, podio =3;
    void * auxDato;
    size_t tam;

    while(cont<=podio)
    {
        menor = buscarMenor(pl,cmp);

        if(menor)
        {
            //guardo el dato de menor xq sino lo pierdo al buscar igual
            tam = menor->tamDato;
            auxDato = malloc(tam);
            if(!auxDato)
                return;

            memcpy(auxDato, menor->dato, tam);

            printf("Puesto %d: ", cont);
            accion(menor->dato,NULL);
            borrar_de_lista_Dato(pl, menor->dato,cmp);
            iguales = buscarIgual(pl,auxDato, cmp);
            if(iguales)
            {
                printf("Puesto %d: ", cont);
                accion(iguales->dato,NULL);
                borrar_de_lista_Dato(pl, iguales->dato,cmp);

                if(cont == 2 || cont == 1)
                {
                    cont++;
                }
            }
        }
        cont++;
    }
}

void insertarDatos(tLista*pl)
{
    int n = 10;

    tPersona vec[10] = {{"luana", 1.03},
                        {"juan", 1.04},
                        {"pedro", 0.59},
                        {"tiago", 1.20},
                        {"kiara", 1.11},
                        {"martina", 1.07},
                        {"alejandra", 1.08},
                        {"francis", 1.19},
                        {"raul", 1.24},
                        {"jose", 1.38}};

    for(int i =0; i<n;i++)
    {
        poner_en_listaIni(pl, &vec[i], sizeof(tPersona));
    }
}

tNodo* buscarIgual(tLista*pl, const void*dato,int(*cmp)(const void*,const void*))
{
    while(*pl)
    {
        if(cmp((*pl)->dato,dato)==0)
        {
            return *pl;

        }
        pl = &(*pl)->sig;
    }
    return NULL;
}
tNodo*buscarMenor(tLista*pl,int(*cmp)(const void*,const void*))
{
    if(!pl || !*pl)
        return NULL;

    tNodo*enc=*pl;
    while(*pl)
    {
        if(cmp((*pl)->dato, enc->dato)<0)
        {
            enc = *pl;
        }
        pl= &(*pl)->sig;
    }

    return enc;
}

void imprimirPers(const void*dato, void*param)
{
    tPersona *p = (tPersona*)dato;

    printf(" %s %.2f\n", p->nya, p->tiempo);
}

void imprimirLista(tLista*pl, void (*accion)(const void*, void*))
{
    while(*pl)
    {
        accion((*pl)->dato, NULL);
        pl = &(*pl)->sig;
    }
}
