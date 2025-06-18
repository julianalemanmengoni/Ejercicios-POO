# Ejercicio 22 - Simulador de Sensor con funciones inline

Este ejercicio evalúa el rendimiento de funciones inline vs. funciones normales en C++ usando Qt.

## Funciones medidas

- getValorBruto() → inline implícito
- getValorBrutoOffline() → función externa
- getValorNormalizado() → inline explícito
- getValorNormalizadoOffline() → función externa

## Prueba de rendimiento

Se ejecutan cada una de las funciones 10 millones de veces y se mide el tiempo con `QElapsedTimer`.

## Cómo compilar

1. Abrí `ejercicio22.pro` con Qt Creator
2. Compilá y ejecutá
3. Observá los resultados en la consola
