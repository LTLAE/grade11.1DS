#include "sort.h"

void BubbleSort(int *input, int size) {
    int temp, compareCount = 0, moveCount = 0, finished = 0;
    while (finished == 0) {
        finished = 1;   //no swap, finished
        for (int traverse = 0; traverse < size - 1; traverse++) {   //bubble once
            compareCount++;
            if (input[traverse] > input[traverse + 1]) {    //swap
                finished = 0;   //swap, not finished
                temp = input[traverse + 1];
                input[traverse + 1] = input[traverse];
                input[traverse] = temp;
                moveCount++;
            }
            for (int timer = 0; timer < size; timer++) cout << input[timer] << '\t';
            cout << endl;
        }
    }
    cout << "Compared " << compareCount << " times with " << moveCount << " moves." << endl;
}

void InsertionSort(int *input, int size) {
    int temp, compareCount = 0, moveCount = 0;
    for (int sorted = 0; sorted < size - 1; sorted++) {      //sequence zone: 0 to sorted
        compareCount++;
        if (input[sorted + 1] < input[sorted]) {  //pick the first number in unsorted
            int insertionPoint;
            for (insertionPoint = sorted; input[sorted + 1] < input[insertionPoint] && insertionPoint >= 0; insertionPoint--)  compareCount++;  //find a place for the number
            insertionPoint++;
            temp = input[sorted + 1];
            for (int timer = sorted + 1; timer > insertionPoint; timer--) {   //move all numbers after the insertion point 1 block
                input[timer] = input[timer - 1];
                moveCount++;
            }
            input[insertionPoint] = temp;    //insert the number
        }
        //output input of each time
        for (int timer = 0; timer < size; timer++) cout << input[timer] << '\t';
        cout << endl;
    }
    cout << "Compared " << compareCount << " times with " << moveCount << " moves." << endl;
}

void SelectionSort(int *input, int size) {
    int minPos, minNum, compareCount = 0, moveCount = 0;
    for (int sorted = 0; sorted < size; sorted++) { //sequence zone: 0 to sorted
        minPos = sorted;    //set minPos as first number of unsorted
        for (int timer = sorted; timer < size; timer++) {
            compareCount++;
            minPos = input[timer] < input[minPos] ? timer : minPos;    //get position of the smallest number
        }
        minNum = input[minPos];
        for (int timer = minPos; timer > sorted; timer--) {   //move all numbers from sorted to minPos 1 block
            input[timer] = input[timer - 1];
            moveCount++;
        }
        input[sorted] = minNum;
        //output input of each time
        for (int timer = 0; timer < size; timer++) cout << input[timer] << '\t';
        cout << endl;
    }
    cout << "Compared " << compareCount << " times with " << moveCount << " moves." << endl;
}

void ShakerSort(int *input, int size) {
    int temp, compareCount = 0, moveCount = 0, finished = 0, traverse = 0;
    while (finished == 0) {
        finished = 1;   //no swap, finished
        for (int timer = 0; timer < size; timer++) cout << input[timer] << '\t';
        cout << endl;
        if (traverse == 0) {    //bubble ->

            for (; traverse < size - 1; traverse++) {
                compareCount++;
                if (input[traverse] > input[traverse + 1]) {    //swap
                    finished = 0;   //swap, not finished
                    temp = input[traverse + 1];
                    input[traverse + 1] = input[traverse];
                    input[traverse] = temp;
                    moveCount++;
                }
            }
        } else {    //bubble <-
            for (; traverse > 0; traverse--) {
                compareCount++;
                if (input[traverse - 1] > input[traverse]) {    //swap
                    finished = 0;   //swap, not finished
                    temp = input[traverse - 1];
                    input[traverse - 1] = input[traverse];
                    input[traverse] = temp;
                    moveCount++;
                }
            }
        }
    }
    for (int timer = 0; timer < size; timer++) cout << input[timer] << '\t';
    cout << endl;
    cout << "Compared " << compareCount << " times with " << moveCount << " moves." << endl;
}

int quickCompareCount = 0, quickMoveCount = 0;
void QuickSort(int *input, int start, int end) {
    QuickSortRun(input,start,end);
    for (int timer = 0; timer < end; timer++) cout << input[timer] << '\t';
    cout << endl;
    cout << "Compared " << quickCompareCount << " times with " << quickMoveCount << " moves." << endl;
}

void QuickSortRun(int *input, int start, int end) {
    if (start < end) {
        int front = start, rear = end, temp;    //front and rear as pointers
        temp = input[start];
        while (front != rear) {
            for (; front < rear && input[rear] > temp; rear--);
            quickCompareCount++;
            input[front] = input[rear]; //move number from back to front
            quickMoveCount++;
            for (; front < rear && input[front] <= temp; front++);
            quickCompareCount++;
            input[rear] = input[front]; //move number from front to back
            quickMoveCount++;
        }
        input[front] = temp;    //put back start element
        quickMoveCount++;
        //output process
        for (int timer = 0; timer < end; timer++) cout << input[timer] << '\t';
        cout << endl;

        QuickSortRun(input, start, front - 1);
        QuickSortRun(input, front + 1, end);
    }
}

int heapCompareCount = 0, heapMoveCount = 0;
void HeapSort(int *input, int size) {
    heapCompareCount = 0;
    heapMoveCount = 0;
    for (int timer = size / 2 - 1; timer >= 0; timer--) {   //make array a heap
        HeapAdjust(input, size, timer);
    }
    //sort
    for (int timer = size - 1; timer >= 0; timer--) {    //size = 16, array[size - 1] = array[15]
        int temp;
        temp = input[0];
        input[0] = input[timer];
        input[timer] = temp;    //move the largest number to the end of the array
        heapMoveCount++;
        HeapAdjust(input, timer, 0);    //start from root aka array[0]
    }
    for (int timer = 0; timer < size; timer++) cout << input[timer] << '\t';
    cout << endl;
    cout << "Compared " << heapCompareCount << " times with " << heapMoveCount << " moves." << endl;
}

void HeapAdjust(int *input, int size, int Root) {
    int temp;
    int largest = Root;
    int leftChild = 2 * Root + 1;
    int rightChild = 2 * Root + 2;
    //swap Root with left child or right child
    //added left/right child < size bcuz leaves of this tree don't have nullptr
    if (input[leftChild] > input[largest] && leftChild < size) {
        largest = leftChild;
        heapCompareCount++;
    }
    if (input[rightChild] > input[largest] && rightChild < size) {
        largest = rightChild;
        heapCompareCount++;
    }
    if (largest != Root) {  //swap
        temp = input[Root];
        input[Root] = input[largest];
        input[largest] = temp;
        heapMoveCount++;
        HeapAdjust(input, size, largest);
    }
    for (int timer = 0; timer < size; timer++) cout << input[timer] << '\t';
    cout << endl;
}

int mergeCompareCount = 0, mergeMoveCount = 0;
void MergeSort(int *input, int start, int end) {
    for (int mergeCount = 0; mergeCount < end - start; mergeCount*=2) { //merge log2(n) timers
        int timer;
        for (timer = 0; timer + 2 * mergeCount - 1 < end - start; timer = timer + 2 * mergeCount)   Merge(input, timer, timer + mergeCount - 1, timer + 2 * mergeCount - 1);
        if (timer + mergeCount - 1 < end - start - 1)   Merge(input, timer, timer + mergeCount - 1, timer - 1);
    }
}

void Merge(int *input, int start, int end, int middle) {    //merge start to middle and middle+1 to end
    char process[end - start + 1];
    int timer1 = start, timer2 = middle + 1, processTimer = 0;
    while (timer1 < middle && timer2 < end) {   //when both arrays are not finished
        if (input[timer1] <= input[timer2]) {   //array1[timer1] is smaller, move it to process[processTimer]
            process[processTimer] = input[timer1];
            timer1++;
            processTimer++;
        } else {    //array2[timer2] is smaller, move it to process[processTimer]
            process[processTimer] = input[timer2];
            timer2++;
            processTimer++;
        }
    }
    //when an array reached its end, copy other numbers from another array to process
    while(timer1 <= middle) {
        process[processTimer] = input[timer1];
        timer1++;
        processTimer++;
    }
    while(timer2 <= end) {
        process[processTimer] = input[timer2];
        timer2++;
        processTimer++;
    }
    //copy numbers from process to input
    for (processTimer = start; processTimer < end; processTimer++) input[processTimer] = process[processTimer];
}