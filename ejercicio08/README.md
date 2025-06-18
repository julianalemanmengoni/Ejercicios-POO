# Ejercicio 8 - Login JWT con Qt y FastAPI

Este ejercicio conecta un login Qt con un backend FastAPI y gestiona tokens JWT.

## Funcionalidad

- Login con usuario y clave
- Solicitud HTTP POST a `/auth/login`
- Almacena el token JWT en memoria
- Usa el token para acceder a recursos protegidos

## Cómo usar

1. Cambiá la URL del endpoint en `login.cpp` si no estás usando `localhost:8000`
2. Ejecutá FastAPI con una ruta `/auth/login` que devuelva un `access_token`
3. Abrí y ejecutá el proyecto en Qt Creator
