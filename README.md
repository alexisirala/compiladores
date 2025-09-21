Tarea 1 de compiladores

# Analizador lexico JSON

Este proyecto implementa un analizador léxico en C

## Uso
Compilar con:

```sh
gcc main.c anlex.c -o anlex
```
Ejecutar con:

```sh
./anlex fuente.txt output.txt
```

## Integrantes

- Alexis Irala

## Descripción

- Lee `fuente.txt` línea por línea.
- Genera `output.txt` con los tokens encontrados en cada línea.
- Reporta errores léxicos por consola y continúa con la siguiente línea.
