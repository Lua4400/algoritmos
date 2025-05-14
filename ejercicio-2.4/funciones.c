#include "main.h"

void crearPila(tPila * pp)
{
    pp->tope = 0;
}

int poner_en_pila(tPila *pp, const void * dato, size_t tam)
{
    if(TOPE < pp->tope+ sizeof(size_t)+tam)
    {
        return PILA_LLENA;
    }

    memcpy(pp->vec+pp->tope, dato, tam);
    pp->tope+=tam;

    memcpy(pp->vec+pp->tope, &tam, sizeof(size_t));

    pp->tope+=sizeof(size_t);

    return TODO_OK;
}

int sacar_de_pila(tPila * pp, void * dato, size_t tam)
{
    size_t tam_dato;

    if(pp->tope == 0)
        return PILA_VACIA;
    pp->tope-=sizeof(size_t);

    memcpy(&tam_dato, pp->vec + pp->tope, sizeof(size_t));

    pp->tope-=tam;

    memcpy(dato, pp->vec+pp->tope, tam_dato> tam? tam: tam_dato);
    return TODO_OK;
}

int ver_tope(const tPila * pp, void * dato, size_t tam)
{
    size_t tam_dato;
    if(pp->tope == 0)
        return 0; //pila vacia

    memcpy(&tam_dato, pp->vec + pp->tope -sizeof(size_t), sizeof(size_t));

    memcpy(dato, pp->vec+pp->tope-sizeof(size_t)-tam, tam_dato> tam? tam : tam_dato);
    return TODO_OK;
}

int pila_vacia(tPila * pp)
{
    return pp->tope ==0? 1:0;
}
int proceso(const char *archivo, tPila *pp)
{
    int numero;
    FILE *pf = fopen(archivo, "rb");

    if(!pf)
        return 0;

    while(fread(&numero, sizeof(numero), 1, pf) == 1)
    {
        poner_en_pila(pp, &numero, sizeof(int));
    }

    fclose(pf);
    return TODO_OK;
}


int grabar_archivo(const char *archivo, tPila *pp)
{
    FILE *pf = fopen(archivo, "wb");
    int numero;

    if(!pf)
        return 0;

    while(!pila_vacia(pp))
    {
        sacar_de_pila(pp, &numero, sizeof(int));
        fwrite(&numero, sizeof(numero), 1, pf);
    }

    fclose(pf);

    if(ftell(pf) == 0)
        remove(archivo);

    return TODO_OK;
}

void menu(const char * archivo, tPila *pp)
{
    int numero, idx;

    do
    {
        printf("\nMENU\n");
        printf("1. Cargar numero en la pila\n");
        printf("2. Ver tope\n");
        printf("3. Sacar de la pila\n");
        printf("4. Salir\n");
        printf("Ingrese opcion: ");
        scanf("%d", &idx);

        switch (idx)
        {
        case 1:
            printf("Ingrese un numero entero: ");
            scanf("%d", &numero);
            if(poner_en_pila(pp, &numero, sizeof(int)) == PILA_LLENA)
                printf("Pila llena.\n");
            break;

        case 2:
            if(ver_tope(pp, &numero, sizeof(int)) == 0)
                printf("Pila vacia.\n");
            else
                printf("Tope: %d\n", numero);
            break;

        case 3:
            if(sacar_de_pila(pp, &numero, sizeof(int)) == PILA_VACIA)
                printf("Pila vacia.\n");
            else
                printf("Se saco: %d\n", numero);
            break;

        case 4:
            grabar_archivo(archivo, pp); // guarda lo que queda en la pila
            break;

        default:
            printf("Opcion invalida.\n");
        }

    }
    while(idx != 4);
}

void mostrarArchivoBin(const char* arch)
{
    int n;
    FILE *pf = fopen(arch, "rb");
    if(!pf)
    {
        printf("Error al abrir el archivo");
        exit(1);
    }

    while(fread(&n, sizeof(n), 1, pf) == 1)
    {
        printf("%d\n", n);
    }

    fclose(pf);
}


void crearArchBin(const char * arch)
{
    FILE* f = fopen(arch, "wb");
    if(!f)
    {
        perror("No se pudo crear el archivo");
        exit(1);
    }

    int numeros[] = {10, 20, 30};
    int cantidad = sizeof(numeros) / sizeof(numeros[0]);

    for(size_t i = 0; i < cantidad; i++)
    {
        fwrite(&numeros[i], sizeof(int), 1, f);
    }

    fclose(f);
    printf("Archivo creado con %d enteros.\n", cantidad);
}
