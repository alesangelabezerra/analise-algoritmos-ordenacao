#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;
using namespace std::chrono;

void bubbleSort(vector<int>& v) {
    int n = v.size();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (v[j] > v[j+1]) {
                swap(v[j], v[j+1]);
            }
        }
    }
}

void selectionSort(vector<int>& v) {
    int n = v.size();
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (v[j] < v[min_idx]) {
                min_idx = j;
            }
        }
        swap(v[i], v[min_idx]);
    }
}

void insertionSort(vector<int>& v) {
    int n = v.size();
    for (int i = 1; i < n; i++) {
        int key = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > key) {
            v[j+1] = v[j];
            j = j - 1;
        }
        v[j+1] = key;
    }
}

void shellSort(vector<int>& v) {
    int n = v.size();
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = v[i];
            int j;
            for (j = i; j >= gap && v[j - gap] > temp; j -= gap) {
                v[j] = v[j - gap];
            }
            v[j] = temp;
        }
    }
}

int partition(vector<int>& v, int low, int high) {
    int pivot = v[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (v[j] < pivot) {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[high]);
    return i + 1;
}

void quickSort(vector<int>& v, int low, int high) {
    if (low < high) {
        int pi = partition(v, low, high);
        quickSort(v, low, pi - 1);
        quickSort(v, pi + 1, high);
    }
}

void merge(vector<int>& v, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = v[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = v[m + 1 + j];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            v[k] = L[i];
            i++;
        } else {
            v[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        v[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        v[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& v, int l, int r) {
    if (l >= r) {
        return;
    }
    int m = l + (r - l) / 2;
    mergeSort(v, l, m);
    mergeSort(v, m + 1, r);
    merge(v, l, m, r);
}

int main() {
    srand(time(NULL));

    vector<int> sizes = {10, 100, 1000, 10000, 100000, 1000000};

    for (int n : sizes) {
        vector<int> v(n);
        
        for (int i = 0; i < n; ++i) {
            v[i] = rand() % 1000000;
        }

        auto start = high_resolution_clock::now();
        
        // Bubble Sort
        vector<int> v1 = v;
        bubbleSort(v1);

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Bubble Sort (" << n << "): " << duration.count() << " microseconds" << endl;

        // Selection Sort
        vector<int> v2 = v;
        start = high_resolution_clock::now();
        selectionSort(v2);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        cout << "Selection Sort (" << n << "): " << duration.count() << " microseconds" << endl;

        // Insertion Sort
        vector<int> v3 = v;
        start = high_resolution_clock::now();
        insertionSort(v3);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        cout << "Insertion Sort (" << n << "): " << duration.count() << " microseconds" << endl;

        // Shell Sort
        vector<int> v4 = v;
        start = high_resolution_clock::now();
        shellSort(v4);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        cout << "Shell Sort (" << n << "): " << duration.count() << " microseconds" << endl;

        // Quick Sort
        vector<int> v5 = v;
        start = high_resolution_clock::now();
        quickSort(v5, 0, n - 1);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        cout << "Quick Sort (" << n << "): " << duration.count() << " microseconds" << endl;

        // Merge Sort
        vector<int> v6 = v;
        start = high_resolution_clock::now();
        mergeSort(v6, 0, n - 1);
        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        cout << "Merge Sort (" << n << "): " << duration.count() << " microseconds" << endl;

        v.clear();
    }

    return 0;
}
