#include <stdio.h>
#include <stdlib.h>
#include "arboles.h"
#define TAM 100


int main()
{
    ArbolesP arboles[TAM];

    leerArchivo(arboles);

    crearArboles(arboles);

    agregarArbol(arboles,"laurel",210,2.55);
    agregarArbol(arboles,"secuoya caucho",21,2.10);
    agregarArbol(arboles,"gikgo biloba",110,3.19);

    mostrarArboles(arboles);

    modificarArbol(arboles,"laurel");

    mostrarArboles(arboles);

    eliminarArboles(arboles,"Cocotero");
    eliminarArboles(arboles,"Falsa Acacia");

    mostrarArboles(arboles);

    guardarEnArchivo(arboles);

    return 0;
}
