#include <stdio.h>
#include <stdlib.h>
#include "arboles.h"
#include <string.h>
#define TAM 100


struct ArbolesE{
    char especie[20];
    int edad;
    float altura;

};

ArbolesP crearArbolVacio(){
    ArbolesP a=malloc(sizeof(struct ArbolesE));
    strcpy(a->especie,"VACIO");
    a->edad=-1;
    a->altura=-1;
    return a;
}

ArbolesP crearArbol(){
    ArbolesP a=malloc(sizeof(struct ArbolesE));
    printf("ingrese la especie del arbol\n");
    fflush(stdin);
    gets(a->especie);
    printf("ingrese la edad del arbol\n");
    scanf("%d",&a->edad);
    printf("ingrese la altura del arbol\n");
    scanf("%f",&a->altura);
    return a;
}

void mostrarArbol(ArbolesP a){
    if(a->edad != -1){
        printf("\n Especie del arbol: %s----Edad del arbol:%d----altura del arbol:%.2f\n",a->especie,a->edad,a->altura);
    }
}
void crearArboles(ArbolesP a[]){
    for (int i=3;i<TAM;i++){
        a[i]=crearArbolVacio();
    }
};

void mostrarArboles(ArbolesP a[]){
    printf("\n-----------------------------------------------------\n");
    for(int i=0;i<TAM;i++){
        mostrarArbol(a[i]);
    }
    printf("\n-----------------------------------------------------\n");
}

void leerArchivo(ArbolesP arboles[]){

   FILE * archivo = fopen("arboles.txt","r");
   int i=0;
   while(!feof(archivo)){
    char datos[50]="";
    fgets(datos,50,archivo);
    arboles[i] = transformarEnTexto(datos);
    i++;
   }
    fclose(archivo);

}

ArbolesP transformarEnTexto(char c[50]){

    ArbolesP a=malloc(sizeof(struct ArbolesE));

    int posDelDelimitador=-1;
    int segundoDelimitador=-1;
    //buscamos primer delimitador
    for(int i=0;i<50;i++){
        if(c[i]=='+'){
            posDelDelimitador=i;
            i=100;
        }
    }
    //buscamos segundo delimitador
    for(int i=posDelDelimitador+1;i<50;i++){
        if(c[i]=='+'){
            segundoDelimitador=i;
            i=100;
        }
    }
    char especieAux[20]="";
    char edadAux[5]="";
    char alturaAux[6]="";

    for(int i=0;i<posDelDelimitador;i++){
        especieAux[i] = c[i];
    }

    for(int i=posDelDelimitador+1;i<segundoDelimitador;i++){
        edadAux[i-posDelDelimitador-1]=c[i];

    }

     for(int i=segundoDelimitador+1;i<segundoDelimitador+6;i++){
        alturaAux[i-segundoDelimitador-1]=c[i];
    }


    strcpy(a->especie,especieAux);
    a->edad=atoi(edadAux);
    a->altura=atof(alturaAux);

    return a;

}

int buscarPosVacia(ArbolesP arboles[]){
    int posVacia=-1;
    for (int i=0;i<TAM;i++){
        if(arboles[i]->edad == -1){
            posVacia=i;
            i=TAM+1;
        }
    }
    return posVacia;
}

void agregarArbol(ArbolesP arboles[],char nombre[20],int e,float a){
    int posVacia=buscarPosVacia(arboles);
    if(posVacia != -1){
        arboles[posVacia]->edad=e;
        arboles[posVacia]->altura=a;
        strcpy(arboles[posVacia]->especie,nombre);
    }
};

void modificarArbol(ArbolesP arboles[],char nombre[20]){

    for(int i=0;i<TAM;i++){
        if(strcmp(arboles[i]->especie,nombre) == 0){
            printf("\n ingrese la nueva edad para el arbol: %s\n",arboles[i]->especie);
            scanf("%d",&arboles[i]->edad);
            printf("ingrese la nueva altura para el arbol: %s\n",arboles[i]->especie);
            scanf("%f",&arboles[i]->altura);
        }
    }

};

void eliminarArboles(ArbolesP arboles[],char nombre[20]){

    for(int i=0;i<TAM;i++){
        if(strcmp(arboles[i]->especie,nombre) == 0){
            arboles[i]=crearArbolVacio();
        }
    }
};

void guardarEnArchivo(ArbolesP arboles[]){
    FILE * archivo = fopen("arbolesGuardados.txt","w");

    for(int i=0;i<TAM;i++){
            if(arboles[i]->edad != -1){
            fprintf(archivo,"%s+%d+%.2f\n",arboles[i]->especie,arboles[i]->edad,arboles[i]->altura);

        }
    }
    fclose(archivo);
}
