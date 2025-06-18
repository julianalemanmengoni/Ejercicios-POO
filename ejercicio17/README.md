# Ejercicio 17 - Botones personalizados y fondo

Este proyecto Qt utiliza Qt Designer para construir una ventana con 5 botones coloridos, cada uno basado en la clase personalizada `Boton`.

## Funcionalidades

- Clase `Boton` hereda de `QWidget` y redefine `paintEvent` para pintarse de color.
- Método `colorear(Boton::Color)` permite asignar colores definidos por enumeración.
- Señal `signal_clic()` se emite al hacer clic.
- Distribución con `QGridLayout` y espaciadores.
- Fondo dibujado con `drawImage`.

## Cómo ejecutar

1. Abrir `ejercicio17.pro` con Qt Creator.
2. Compilar y ejecutar.
3. Los botones deben visualizarse como en la imagen de referencia.
