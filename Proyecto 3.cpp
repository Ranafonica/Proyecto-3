#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
#include <vector>
#include <unordered_map>
#include <random>
#include <set>
#include <ctime>
#include <iomanip>

using namespace std;

vector<int> generateRandomUniqueData(int size) {
    vector<int> data;
    set<int> uniqueData;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, size * 10);

    while (uniqueData.size() < size) {
        uniqueData.insert(dis(gen));
    }

    for (int num : uniqueData) {
        data.push_back(num);
    }

    return data;
}

void SelectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n ; ++i) {
        for (int j = i; j < n ; ++j) {
            if (arr[j] < arr[i]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

double getResultFromAlg(vector<int>& arr) {
    time_t start, end;
    double time_taken;
    time(&start);
    ios_base::sync_with_stdio(false);
    SelectionSort(arr);
    time(&end);
    time_taken = double(end - start);
    return time_taken;
}

int main(int argc, char* argv[]) {
    vector<int> arr = generateRandomUniqueData(10);

    unordered_map<string, double> results;
    results["SelectionSort"] = getResultFromAlg(arr);

    int id = 1;
    for (const auto& pair : results) {
        const string& key = pair.first;
        double value = pair.second;
        cout << id << ". " << key << ", " << fixed << setprecision(5) << value << endl;
        id++;
    }

    return 0;
}
