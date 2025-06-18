# Ejercicio 16 - Login con SQLite y claves MD5

Este proyecto implementa un login que valida usuarios desde una base de datos SQLite.  
Las claves están almacenadas en formato MD5 y se recuerda automáticamente el último usuario logueado.

## Archivos

- `usuarios.db`: base de datos SQLite con usuarios y una tabla de configuración.
- `login.ui`: interfaz de login creada con Qt Designer.

## Cómo ejecutar

1. Abrí el archivo `ejercicio16.pro` con Qt Creator.
2. Compilá y ejecutá.
3. Ingresá un usuario válido con su clave (las claves están en MD5).

> Podés usar SQLiteStudio para ver el contenido de la base.
