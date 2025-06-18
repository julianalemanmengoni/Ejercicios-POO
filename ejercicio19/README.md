# Ejercicio 19 - Gestión de Medicamentos

Aplicación Qt con SQLite para controlar las cajas de medicamentos de una obra social.

## Características

- Solo usa `QWidget` (sin `QMainWindow`)
- Cada caja tiene una cantidad de dosis (máx. total: 1000)
- Permite agregar, sumar y comparar cajas
- Usa `QMessageBox` y `qDebug()`
- Usa `SIGNAL()` y `SLOT()`, sin lambdas

## Compilación

1. Abrir el archivo `ejercicio19.pro` con Qt Creator
2. Compilar y ejecutar

> Asegurate de tener acceso de escritura para que cree el archivo `medicamentos.db`
