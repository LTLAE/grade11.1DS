#include "sort.h"

int Random(int min, int max) {
    return (rand() % (max - min + 1)) + min;    //return a num in range [min,max]
}

void initArray(int *array, int size) {
    cout << "Unsorted random array:" << endl;
    for (int timer = 0; timer < size; timer++) {
        array[timer] = Random(10, 99);
        cout << array[timer] << '\t';
    }
    cout << endl;
}

int main() {
    int array[16];
    initArray(array, sizeof(array) / 4);
    cout << "Bubble sort:" << endl;
    BubbleSort(array, sizeof(array) / 4);

    initArray(array, sizeof(array) / 4);
    cout << "Insertion sort:" << endl;
    InsertionSort(array, sizeof(array) / 4);

    initArray(array, sizeof(array) / 4);
    cout << "Selection sort:" << endl;
    SelectionSort(array, sizeof(array) / 4);

    initArray(array, sizeof(array) / 4);
    cout << "Merge sort:" << endl;
    MergeSort(array, 0, sizeof(array) / 4);

    initArray(array, sizeof(array) / 4);
    cout << "Shaker sort:" << endl;
    ShakerSort(array, sizeof(array) / 4);

    initArray(array, sizeof(array) / 4);
    cout << "Quick sort:" << endl;
    QuickSort(array, 0, sizeof(array) / 4);

    initArray(array, sizeof(array) / 4);
    cout << "Heap sort:" << endl;
    HeapSort(array, sizeof(array) / 4);



}
