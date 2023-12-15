#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <algorithm>
#include <vector>

using namespace std;
using namespace chrono;

// Función para generar un vector sin duplicados de tamaño aleatorio en el rango [minSize, maxSize]
vector<int> sinDuplicados(int minSize, int maxSize) {
    random_device rd;
    mt19937 gen(rd());

    int size = uniform_int_distribution<int>(minSize, maxSize)(gen);

    vector<int> arr(size);
    iota(arr.begin(), arr.end(), 0);
    shuffle(arr.begin(), arr.end(), gen);

    return arr;
}

// Función para generar un vector con duplicados de tamaño aleatorio en el rango [minSize, maxSize]
vector<int> conDuplicados(int minSize, int maxSize) {
    random_device rd;
    mt19937 gen(rd());

    int size = uniform_int_distribution<int>(minSize, maxSize)(gen);

    vector<int> arr(size);
    generate(arr.begin(), arr.end(), [&]() { return uniform_int_distribution<int>(0, size)(gen); });

    return arr;
}

// Función para generar un vector ordenado de tamaño aleatorio en el rango [minSize, maxSize]
vector<int> ordenado(int minSize, int maxSize) {
    vector<int> arr = sinDuplicados(minSize, maxSize);
    sort(arr.begin(), arr.end());
    return arr;
}

// Función para generar un vector inversamente ordenado de tamaño aleatorio en el rango [minSize, maxSize]
vector<int> inversamenteOrdenado(int minSize, int maxSize) {
    vector<int> arr = sinDuplicados(minSize, maxSize);
    sort(arr.rbegin(), arr.rend());
    return arr;
}

// Implementación del algoritmo de ordenamiento: Selection Sort (Algoritmo Cuadrático)
void selectionSort(vector<int>& arr) {
    int size = arr.size();
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// Implementación del algoritmo de ordenamiento: Bubble Sort (Algoritmo Cuadrático)
void bubbleSort(vector<int>& arr) {
    int size = arr.size();
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Implementación del algoritmo de ordenamiento: Insertion Sort (Algoritmo Cuadrático)
void insertionSort(vector<int>& arr) {
    int size = arr.size();
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// Implementación del algoritmo de ordenamiento: Shell Sort (Algoritmo Cuadrático)
void shellSort(vector<int>& arr) {
    int size = arr.size();
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; ++i) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// Implementación del algoritmo de ordenamiento: Merge Sort (Algoritmo Logaritmo)
void merge(vector<int>& arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[middle + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

// Implementación del algoritmo de ordenamiento: Merge Sort (Algoritmo Logaritmo)
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

// Función de partición para Quick Sort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Implementación del algoritmo de ordenamiento: Quick Sort (Algoritmo Logaritmo)
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Función para mantener la propiedad de heap durante la construcción de un heap
void heapify(vector<int>& arr, int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
    }
}

// Implementación del algoritmo de ordenamiento: Heap Sort (Algoritmo Logaritmo)
void heapSort(vector<int>& arr) {
    int size = arr.size();
    for (int i = size / 2 - 1; i >= 0; --i) {
        heapify(arr, size, i);
    }

    for (int i = size - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Función envolvente para el algoritmo de ordenamiento Merge Sort
void wrapMergeSort(vector<int>& arr) {
    mergeSort(arr, 0, arr.size() - 1);
}

// Función envolvente para el algoritmo de ordenamiento Quick Sort
void wrapQuickSort(vector<int>& arr) {
    quickSort(arr, 0, arr.size() - 1);
}

// Función para liberar la memoria de un arreglo dinámico
void liberarMemoria(int* arr) {
    delete[] arr;
}

// Función para medir el tiempo de ejecución de un algoritmo de ordenamiento
template <typename Func>
double medirTiempo(Func func, vector<int>& arr) {
    auto start = chrono::high_resolution_clock::now();
    func(arr);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    return duration.count();
}

// Función principal para ejecutar la carrera entre algoritmos
void ejecutarCarrera(vector<int>& arr) {
    // Vector para almacenar los tiempos de cada algoritmo
    vector<pair<string, double>> tiempos;

    // Lista de algoritmos
    vector<pair<void (*)(vector<int>&), string>> algoritmos = {
        {selectionSort, "Selection Sort"},
        {insertionSort, "Insertion Sort"},
        {shellSort, "Shell Sort"},
        {bubbleSort, "Bubble Sort"},
        {wrapMergeSort, "Merge Sort"},
        {heapSort, "Heap Sort"},
        {wrapQuickSort, "Quick Sort"}
    };

    // Ejecutar cada algoritmo y medir el tiempo
    for (const auto& algorithm : algoritmos) {
        auto algoritmo = algorithm.first;
        auto nombreAlgoritmo = algorithm.second;

        vector<int> copiaArr = arr;

        cout << "Se encuentra ejecutando " << nombreAlgoritmo << "..." << endl;

        auto tiempoInicio = chrono::steady_clock::now(); // Marcar el tiempo de inicio
        algoritmo(copiaArr);
        auto tiempoFin = chrono::steady_clock::now(); // Marcar el tiempo de fin

        double tiempoTotal = chrono::duration<double>(tiempoFin - tiempoInicio).count();
        tiempos.push_back({nombreAlgoritmo, tiempoTotal});

        cout << nombreAlgoritmo << " su tiempo ha sido de " << tiempoTotal << " segundos" << endl;
    }

    // Imprimir el ganador
    auto ganador = min_element(tiempos.begin(), tiempos.end(), [](const pair<string, double>& a, const pair<string, double>& b) {
        return a.second < b.second;
    });

    cout << "\nEL GANADOR ES: " << ganador->first << " CON UN TIEMPO DE: " << ganador->second << " SEGUNDOS." << endl;
    cout << endl;
}

// Función principal del programa
int main() {
    srand(static_cast<unsigned>(time(0))); // Mover la semilla al inicio del programa

    int opcion;
    int seleccion;

    do {
        cout << "[MAIN MENU]" << endl;
        cout << "1. Seleccion de Carrera" << endl;
        cout << "2. Salir del Programa" << endl;
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                cout << endl;
                cout << "[SELECCIONE EL CAMPO PARA LA CARRERA]" << endl;
                cout << "1. Colas de espera" << endl;
                cout << "2. Trazabilidad de Objetos" << endl;
                cout << "3. Eventos por escenario" << endl;
                cout << "0. Volver al menu" << endl;
                cout << "Selecciona una opcion: ";
                cin >> seleccion;
                cout << endl;

                switch (seleccion) {
                    case 1: {
                        cout << "\nCOLAS DE ESPERA\n";

                        vector<int> conDuplicadosVec = conDuplicados(100000, 110000);
                        ejecutarCarrera(conDuplicadosVec);
                        vector<int> sinDuplicadosVec = sinDuplicados(100000, 110000);
                        ejecutarCarrera(sinDuplicadosVec);
                        vector<int> OrdenadoVec = ordenado(100000, 110000);
                        ejecutarCarrera(OrdenadoVec);
                        vector<int> InversamenteOrdenadoVec = inversamenteOrdenado(100000, 110000);
                        ejecutarCarrera(InversamenteOrdenadoVec);
                    }
                    break;

                    case 2: {
                        cout << "\nTRAZABILIDAD DE OBJETOS\n";

                        vector<int> conDuplicadosVec = conDuplicados(15000, 22500);
                        ejecutarCarrera(conDuplicadosVec);
                        vector<int> sinDuplicadosVec = sinDuplicados(15000, 22500);
                        ejecutarCarrera(sinDuplicadosVec);
                        vector<int> OrdenadoVec = ordenado(15000, 22500);
                        ejecutarCarrera(OrdenadoVec);
                        vector<int> InversamenteOrdenadoVec = inversamenteOrdenado(15000, 22500);
                        ejecutarCarrera(InversamenteOrdenadoVec);
                    }
                    break;

                    case 3: {
                        cout << "\nEVENTOS POR ESCENARIO\n";

                        vector<int> conDuplicadosVec = conDuplicados(60000, 80000);
                        ejecutarCarrera(conDuplicadosVec);
                        vector<int> sinDuplicadosVec = sinDuplicados(60000, 80000);
                        ejecutarCarrera(sinDuplicadosVec);
                        vector<int> OrdenadoVec = ordenado(60000, 80000);
                        ejecutarCarrera(OrdenadoVec);
                        vector<int> InversamenteOrdenadoVec = inversamenteOrdenado(60000, 80000);
                        ejecutarCarrera(InversamenteOrdenadoVec);
                    }
                    break;

	                case 0: {
	                    // Volver al menú principal
	                    break;
	                }
	
	                default: {
	                    cout << "Opcion invalida, por favor intente de nuevo...\n";
	                }
	                break;
	            }
            }
            break;

            case 2: {
                cout << "Cerrando el programa...\n";
            }
            break;

            default:
                cout << "Opción no válida." << endl;
        }

    } while (opcion != 2);

    return 0;
}


