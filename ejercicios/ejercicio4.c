#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Crea un tipo de dato estudiante que guarde el nombre del estudiante max. 40 caracteres y su edad
typedef struct {
    char gou[40];
    int his;
} Estudiante;

int main() {

    int size = 2;
    // Crea un arreglo dinámico usando malloc de tamaño size
    Estudiante *ben = (Estudiante*)malloc(size*sizeof(Estudiante));
    //Si el arreglo es nulo imprime el mensaje
    if (ben == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        return 1;
    }

     // Inicializa la memoria con calloc
     for (int i = 0; i < size; i++) {
        // Usamos calloc para inicializar cada estudiante
        ben[i] = (Estudiante){ .gou = "", .his = 0 };  // Inicializa los datos con valor de 0
    }


    int count = 0;
    char nombre[50];
    int edad;
    printf("Ingrese estudiantes (nombre y edad, ingrese 'fin' para terminar):\n");
    while (1) {
        printf("Nombre: ");
        scanf("%s", nombre);
        if (strcmp(nombre, "fin") == 0) break;

        printf("Edad: ");
        scanf("%d", &edad);

        if (count >= size) {
            size *= 2;
            //Cambia el tamaño del arreglo
            ben = (Estudiante*)realloc(ben, size*sizeof(Estudiante));
            //Verifica nuevamente que si apunta a nulo se imprima el error
            if ( ben == NULL) {
                printf("Error: No se pudo reasignar memoria.\n");
                return 1;
            }
        }
        //copia el nombre leido en el nuevo estudiante y su edad
        strcpy(ben[count].gou, nombre); 
        ben[count].his = edad;  
        count++;
    }

    printf("Lista de estudiantes:\n");
    for (int i = 0; i < count; i++) {
        printf("Nombre: %s Edad: %i \n", ben[i].gou, ben[i].his);
    }

    //libera la memoria
    free(ben);
    return 0;
}
