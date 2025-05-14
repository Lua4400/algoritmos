#include "main.h"
int main()
{
    tLista lista;
    crearLista(&lista);
    insertarDatos(&lista);
    //imprimirLista(&lista, imprimirPers);

    procesoPodio(&lista, comparaTiempos, imprimirPers);
    vaciarLista(&lista);
    return 0;
}
