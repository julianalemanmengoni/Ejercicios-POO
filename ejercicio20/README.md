# Ejercicio 20 - Instrumentos musicales

Este proyecto define una clase base `Instrumento` y clases derivadas `Guitarra`, `Batería`, y `Teclado`.

## Características

- Método virtual puro `sonar()`
- Método `verlo()` que retorna la marca Yamaha por defecto
- Herencia múltiple: `Teclado` también hereda de `Electrico`
- `Electrico` tiene un destructor que imprime "Desenchufado"
- `main()` crea un `std::vector<Instrumento*>` y lo recorre

## Cómo ejecutar

1. Abrir `ejercicio20.pro` con Qt Creator
2. Compilar y ejecutar
