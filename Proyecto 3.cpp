#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <algorithm>

using namespace std;

//---------------------------------GENERACION DE DATOS---------------------------------
// Orden Aleatorio
void generarAleatorio(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100000 + 1;
    }
}
// Orden Aleatorio con Duplicados
void generarAleatorioConDuplicados(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100000 + 1;
    }
    random_shuffle(arr, arr + size);
}
// Orden Ordenado
void generarOrdenado(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = i + 1;
    }
}
// Orden Inversamente Ordenado
void generarInversamenteOrdenado(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = size - i;
    }
}

//---------------------------------FUNCIONES DE ORDENAMIENTO---------------------------------
void selectionSort(int arr[], int size) {
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

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertionSort(int arr[], int size) {
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

void shellSort(int arr[], int size) {
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

void merge(int arr[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int L[n1], R[n2];

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

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

int partition(int arr[], int low, int high) {
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

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void heapify(int arr[], int size, int i) {
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

void heapSort(int arr[], int size) {
    for (int i = size / 2 - 1; i >= 0; --i) {
        heapify(arr, size, i);
    }

    for (int i = size - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
//---------------------------------FUNCIONES MEDICION TIEMPO ORDENAMIENTO---------------------------------
// Función para medir el tiempo de ejecución de algoritmos de ordenamiento que toman dos argumentos
template <typename Func>
double medirTiempo(Func func, int arr[], int size) {
    auto start = chrono::high_resolution_clock::now();
    func(arr, size);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    return duration.count();
}

// Función para medir el tiempo de ejecución de algoritmos de ordenamiento que toman tres argumentos
template <typename Func>
double medirTiempo(Func func, int arr[], int left, int right) {
    auto start = chrono::high_resolution_clock::now();
    func(arr, left, right);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    return duration.count();
}
//---------------------------------FUNCION CAMPO ESPECIFICO---------------------------------
void ejecutarCarrera(int arr[], int size, const string& campo) {
    cout << "Empieza la carrera en " << campo << "." << endl;
    // Selection Sort
    cout << "Selection Sort: " << medirTiempo(selectionSort, arr, size) << " segundos." << endl;
    // Bubble Sort
    cout << "Bubble Sort: " << medirTiempo(bubbleSort, arr, size) << " segundos." << endl;
    // Insertion Sort
    cout << "Insertion Sort: " << medirTiempo(insertionSort, arr, size) << " segundos." << endl;
    // Shell Sort
    cout << "Shell Sort: " << medirTiempo(shellSort, arr, size) << " segundos." << endl;
    // Funcion que permite tomar 3 argumentos:
    // Merge Sort
	cout << "Merge Sort: " << medirTiempo(mergeSort, arr, 0, size - 1) << " segundos." << endl;
    // Quick Sort
	cout << "Quick Sort: " << medirTiempo(quickSort, arr, 0, size - 1) << " segundos." << endl;
    // Heap Sort
    cout << "Heap Sort: " << medirTiempo(heapSort, arr, size) << " segundos." << endl;
    
    cout << endl;
}


int main() {
    srand(static_cast<unsigned>(time(0)));

    const int size = 25;
    int arr[size];

    // Llenar el arreglo con números aleatorios
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100 + 1;
    }

    // Mostrar el arreglo original
    cout << "Arreglo Original:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Menú
    int opcion;
    do {
    	cout << endl;
        cout << "[MAIN MENU]" << endl;
        cout << "1. Seleccion de Carrera" << endl;
        cout << "2. Salir del Programa" << endl;
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                // Seleccion de Carrera
                cout << endl;
                cout << "Seleccione el campo para la carrera:" << endl;
                cout << "1. ALEATORIO" << endl;
                cout << "2. ALEATORIO CON DUPLICADOS:" << endl;
                cout << "3. ORDENADO:" << endl;
                cout << "4. INVERSAMENTE ORDENADO" << endl;
                cout << "0. VOLVER AL MENU PRINCIPAL" << endl;

                int campoSeleccionado;
                cout << "Selecciona una opcion: ";
                cin >> campoSeleccionado;

                switch (campoSeleccionado) {
                    case 1:
                        // Aleatorio
                        generarAleatorio(arr, size);
                        ejecutarCarrera(arr, size, "Aleatorio");
                        break;

                    case 2:
                        // Aleatorio con Duplicados
                        generarAleatorioConDuplicados(arr, size);
                        ejecutarCarrera(arr, size, "Aleatorio con Duplicados");
                        break;

                    case 3:
                        // Ordenado
                        generarOrdenado(arr, size);
                        ejecutarCarrera(arr, size, "Ordenado");
                        break;

                    case 4:
                        // Inversamente Ordenado
                        generarInversamenteOrdenado(arr, size);
                        ejecutarCarrera(arr, size, "Inversamente Ordenado");
                        break;

                    case 0:
                        // Volver al Menú Principal
                        break;

                    default:
                        cout << "Opción no válida." << endl;
                }
                break;

            case 2:
                // Salir del Programa
                cout << "Saliendo del programa." << endl;
                break;

            default:
                cout << "Opción no válida." << endl;
        }

    } while (opcion != 2);

    return 0;
}

