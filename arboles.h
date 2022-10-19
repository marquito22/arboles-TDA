#ifndef ARBOLES_H_INCLUDED
#define ARBOLES_H_INCLUDED

struct ArbolesE;
typedef struct ArbolesE * ArbolesP;

///constructores
ArbolesP crearArbolVacio();
ArbolesP crearArbol();
void crearArboles(ArbolesP a[]);
///mostrar
void mostrarArbol(ArbolesP a);
void mostrarArboles(ArbolesP a[]);
///leer Archivo "arboles"
void leerArchivo(ArbolesP a[]);
ArbolesP transformarEnTexto(char c[50]);
///Agregar arboles
void agregarArbol(ArbolesP arboles[],char nombre[20],int e,float a);
///Modificar arboles
void modificarArbol(ArbolesP arboles[],char nombre[20]);
///Eliminar arboles
void eliminarArboles(ArbolesP arboles[],char nombre[20]);
///Guardar los datos en el archivo
void guardarEnArchivo(ArbolesP arboles[]);
#endif // ARBOLES_H_INCLUDED
