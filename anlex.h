#ifndef ANLEX_H
#define ANLEX_H

#include <stdio.h>

// Definiciones de tokens
typedef enum {
    L_CORCHETE,   // [
    R_CORCHETE,   // ]
    L_LLAVE,      // {
    R_LLAVE,      // }
    COMA,         // ,
    DOS_PUNTOS,   // :
    STRING,       // "..."
    NUMBER,       // 123, 45.6, 1e10, etc.
    PR_TRUE,      // true, TRUE
    PR_FALSE,     // false, FALSE
    PR_NULL,      // null, NULL
    ERR_LEX,      // error léxico
    EOF_TOKEN     // fin de archivo
} TokenType;

// Prototipo de la función de análisis por línea
void analizar_linea(const char *linea, FILE *fout, int nro_linea);

#endif
