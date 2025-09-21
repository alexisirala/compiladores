#include <stdio.h>
#include <stdlib.h>
#include "anlex.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Uso: %s <archivo_fuente> <archivo_salida>\n", argv[0]);
        return 1;
    }

    FILE *fin = fopen(argv[1], "r");
    FILE *fout = fopen(argv[2], "w");

    if (!fin || !fout) {
        printf("No se pudo abrir uno de los archivos.\n");
        return 1;
    }

    char linea[1024];
    int nro_linea = 1;
    while (fgets(linea, sizeof(linea), fin)) {
        analizar_linea(linea, fout, nro_linea);
        nro_linea++;
    }

    // Al final del archivo, escribir EOF
    fprintf(fout, "EOF\n");

    fclose(fin);
    fclose(fout);
    return 0;
}
