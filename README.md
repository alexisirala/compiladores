Tarea 1 de compiladores

# Analizador lexico JSON

Este proyecto implementa un analizador léxico en C

## Uso

Compilar con:
```sh
gcc main.c anlex.c -o anlex_compiled
```
Ejecutar con:

```sh
./anlex_compiled examples/fuente.txt examples/output.txt
```

## Integrante

- Alexis Irala

## Descripción

- Lee `fuente.txt` línea por línea.
- Genera `output.txt` con los tokens encontrados en cada línea.
- Reporta errores léxicos por consola y continúa con la siguiente línea.
