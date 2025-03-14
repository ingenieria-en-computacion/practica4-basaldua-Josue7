#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n;
    printf("Ingrese el numero de filas: ");
    scanf("%i", &m);
    printf("Ingrese el numero de columnas: ");
    scanf("%i", &n);

    int *matrix = (int *)calloc(m * n, sizeof(int));
    if (matrix == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        return -1;
    }

    printf("Matriz inicializada con ceros:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%i ", matrix[i * n + j]);
        }
        printf("\n");
    }

    printf("Ingrese las coordenadas (fila, columna) y el valor para modificar (ej. 1 2 5):\n");
    int row, col, value;
    //lee los varlores solicitados
    scanf("%i %i %i", &row, &col, &value);
    matrix[(row-1) * n + (col-1)] = value;
    
    printf("Matriz actualizada:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%i ", matrix[i * n + j]);
        }
        printf("\n");
    }

    free(matrix);
    return 0;
}
