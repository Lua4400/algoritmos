#include "main.h"
int main()
{
    tPila stack;

    crearArchBin(archBinDatos);
    printf("\nARCHIVO\n");
    mostrarArchivoBin(archBinDatos);

    crearPila(&stack);
    proceso(archBinDatos, &stack);
    menu(archBinDatos, &stack);

    printf("\nARCHIVO\n");
    mostrarArchivoBin(archBinDatos);

    return 0;
}
