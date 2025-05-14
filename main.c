#include "main.h"
int main()
{
    tLista lista;
    crearLista(&lista);
    insertarDatos(&lista);
    topN(&lista, imprimirEnteros, 3, compararEnteros);
    vaciarLista(&lista);
    return 0;
}
