# README
## Descripción del Programa
Este programa en C++ implementa una carrera entre diferentes algoritmos de ordenamiento, evaluando su rendimiento en distintos escenarios. Los algoritmos de ordenamiento incluidos en la competencia son:

*Selection Sort*
*Insertion Sort
*Shell Sort*
*Bubble Sort*
*Merge Sort*
*Heap Sort*
*Quick Sort*
La aplicación permite al usuario seleccionar un escenario específico (Colas de Espera, Trazabilidad de Objetos o Eventos por Escenario) y ejecutar la carrera entre los algoritmos para evaluar su desempeño en condiciones diversas.

## Funcionalidades Principales
# Generación de Vectores:

sinDuplicados(int minSize, int maxSize): Genera un vector sin duplicados de tamaño aleatorio en el rango [minSize, maxSize].
conDuplicados(int minSize, int maxSize): Genera un vector con duplicados de tamaño aleatorio en el rango [minSize, maxSize].
ordenado(int minSize, int maxSize): Genera un vector ordenado de tamaño aleatorio en el rango [minSize, maxSize].
inversamenteOrdenado(int minSize, int maxSize): Genera un vector inversamente ordenado de tamaño aleatorio en el rango [minSize, maxSize].
Algoritmos de Ordenamiento:

selectionSort(vector<int>& arr): Implementa Selection Sort (Algoritmo Cuadrático).
bubbleSort(vector<int>& arr): Implementa Bubble Sort (Algoritmo Cuadrático).
insertionSort(vector<int>& arr): Implementa Insertion Sort (Algoritmo Cuadrático).
shellSort(vector<int>& arr): Implementa Shell Sort (Algoritmo Cuadrático).
mergeSort(vector<int>& arr, int left, int right): Implementa Merge Sort (Algoritmo Logarítmico).
heapSort(vector<int>& arr): Implementa Heap Sort (Algoritmo Logarítmico).
quickSort(vector<int>& arr, int low, int high): Implementa Quick Sort (Algoritmo Logarítmico).
Funciones Envueltas:

wrapMergeSort(vector<int>& arr): Función envolvente para Merge Sort.
wrapQuickSort(vector<int>& arr): Función envolvente para Quick Sort.
Medición de Tiempo:

medirTiempo(Func func, vector<int>& arr): Mide el tiempo de ejecución de un algoritmo de ordenamiento.
## Carrera entre Algoritmos:

ejecutarCarrera(vector<int>& arr): Ejecuta la carrera entre los algoritmos seleccionados para un escenario específico y muestra el tiempo de ejecución de cada algoritmo. Al final, anuncia al ganador.
# Menú Principal
El programa presenta un menú interactivo con las siguientes opciones:

## Selección de Carrera:

Permite al usuario elegir entre tres escenarios diferentes (Colas de Espera, Trazabilidad de Objetos, Eventos por Escenario) y ejecutar la carrera entre los algoritmos de ordenamiento.
Salir del Programa:

Cierra el programa.
Uso del Programa
Compilación:

Compilar el programa utilizando un compilador de C++. (Dev 5.11 c++)
Ejecución:

Ejecutar el programa resultante.
## Menú Interactivo:

Seleccionar la opción deseada del menú principal y seguir las instrucciones proporcionadas.
Escenarios de Carrera
1. Colas de Espera
Tamaño de vectores: [100,000, 110,000]
2. Trazabilidad de Objetos
Tamaño de vectores: [15,000, 22,500]
3. Eventos por Escenario
Tamaño de vectores: [60,000, 80,000]
Nota: Para regresar al menú principal en cualquier momento, seleccionar la opción '0'.
