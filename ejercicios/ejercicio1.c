#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Ingrese el tamano del arreglo: ");
    scanf("%i", &n);
    
    int *arr;
    arr = (int*)malloc(n *sizeof(int));
    if (arr == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        return 1;
    }

    printf("Ingrese %d valores:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%i", &arr[i]);
    }

    printf("El arreglo es: ");
    for (int i = 0; i < n; i++) {
        printf("%i ", arr[i]);
    }
    printf("\n");
    printf("Liberando memoria\n");
    free(arr);

    return 0;
}
