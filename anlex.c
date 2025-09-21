#include "anlex.h"
#include <string.h>
#include <ctype.h>

// Función auxiliar para imprimir el nombre del token en el archivo de salida
void imprimir_token(TokenType tipo, FILE *fout) {
    switch (tipo) {
        case L_CORCHETE: fprintf(fout, "L_CORCHETE "); break;
        case R_CORCHETE: fprintf(fout, "R_CORCHETE "); break;
        case L_LLAVE: fprintf(fout, "L_LLAVE "); break;
        case R_LLAVE: fprintf(fout, "R_LLAVE "); break;
        case COMA: fprintf(fout, "COMA "); break;
        case DOS_PUNTOS: fprintf(fout, "DOS_PUNTOS "); break;
        case STRING: fprintf(fout, "STRING "); break;
        case NUMBER: fprintf(fout, "NUMBER "); break;
        case PR_TRUE: fprintf(fout, "PR_TRUE "); break;
        case PR_FALSE: fprintf(fout, "PR_FALSE "); break;
        case PR_NULL: fprintf(fout, "PR_NULL "); break;
        case ERR_LEX: fprintf(fout, "ERR_LEX "); break;
        default: break;
    }
}

// Función principal para analizar una línea
void analizar_linea(const char *linea, FILE *fout, int nro_linea) {
    int i = 0;
    int len = strlen(linea);

    while (i < len) {
        // Saltar espacios y tabuladores
        if (isspace(linea[i])) {
            i++;
            continue;
        }
        // Signos de puntuación
        switch (linea[i]) {
            case '[': imprimir_token(L_CORCHETE, fout); i++; continue;
            case ']': imprimir_token(R_CORCHETE, fout); i++; continue;
            case '{': imprimir_token(L_LLAVE, fout); i++; continue;
            case '}': imprimir_token(R_LLAVE, fout); i++; continue;
            case ',': imprimir_token(COMA, fout); i++; continue;
            case ':': imprimir_token(DOS_PUNTOS, fout); i++; continue;
            case '"': { // Cadena de texto
                int j = i + 1;
                while (j < len && linea[j] != '"') j++;
                if (j < len && linea[j] == '"') {
                    imprimir_token(STRING, fout);
                    i = j + 1;
                } else { // Error léxico
                    fprintf(stderr, "Error léxico en línea %d: cadena sin cerrar\n", nro_linea);
                    imprimir_token(ERR_LEX, fout);
                    i = len; // Saltar al final
                }
                continue;
            }
            default: break;
        }
        // Números
        if (isdigit(linea[i]) || (linea[i] == '-' && isdigit(linea[i+1]))) {
            int j = i;
            if (linea[j] == '-') j++;
            while (j < len && isdigit(linea[j])) j++;
            if (j < len && linea[j] == '.') { // Decimal
                j++;
                while (j < len && isdigit(linea[j])) j++;
            }
            if (j < len && (linea[j] == 'e' || linea[j] == 'E')) { // Notación científica
                j++;
                if (linea[j] == '+' || linea[j] == '-') j++;
                while (j < len && isdigit(linea[j])) j++;
            }
            imprimir_token(NUMBER, fout);
            i = j;
            continue;
        }
        // Literales true/false/null
        if (!strncmp(&linea[i], "true", 4) || !strncmp(&linea[i], "TRUE", 4)) {
            imprimir_token(PR_TRUE, fout);
            i += 4;
            continue;
        }
        if (!strncmp(&linea[i], "false", 5) || !strncmp(&linea[i], "FALSE", 5)) {
            imprimir_token(PR_FALSE, fout);
            i += 5;
            continue;
        }
        if (!strncmp(&linea[i], "null", 4) || !strncmp(&linea[i], "NULL", 4)) {
            imprimir_token(PR_NULL, fout);
            i += 4;
            continue;
        }
        // Si no reconoce nada, error léxico
        fprintf(stderr, "Error léxico en línea %d: carácter inesperado '%c'\n", nro_linea, linea[i]);
        imprimir_token(ERR_LEX, fout);
        i++;
    }
    // Nueva línea en el archivo de salida
    fprintf(fout, "\n");
}
