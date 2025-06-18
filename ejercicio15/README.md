# Ejercicio 15 - Login con SQLite

Este proyecto permite iniciar sesión con datos almacenados en una base de datos SQLite.  
Al ingresar correctamente, se muestra el nombre del usuario y su último ingreso.

## Archivos

- `usuarios.db`: base de datos SQLite con tabla `usuarios`.
- `login.ui`: interfaz de login creada con Qt Designer.
- `main.cpp`, `login.cpp`, `ventana.cpp`: lógica del sistema.

## Cómo ejecutar

1. Asegurate de tener `usuarios.db` en la misma carpeta que el ejecutable.
2. Abrí el archivo `ejercicio15.pro` con Qt Creator.
3. Compilá y ejecutá.
4. Usá un usuario y clave válidos (ver contenido de la base de datos con SQLiteStudio).
