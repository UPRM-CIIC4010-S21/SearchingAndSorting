
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Tail recursive implementation of Binary Search
int binarySearch(int key, int numbers[], int size, int start, int end)
{
    if (start == end) {
        if (numbers[start] == key) {
            return start;
        }
        else {
            return -1;
        }
    }
    else if (start > end) {
        return -1;
    }
    else {
        int middle = (start + end) / 2;
        if (numbers[middle] == key) {
            return middle;
        }
        else if (key < numbers[middle]) {
            return binarySearch(key, numbers, size, start, middle - 1);
        }
        else {
            return binarySearch(key, numbers, size, middle+1,end);
        }
    }
}

/*
 * Return the position of the key within the array if it exists
 * Otherwise returns -1;
 */
int binarySearch(int key, int numbers[], int size) 
{
    return binarySearch(key, numbers, size, 0, size-1);
}


void selectionSort(int *numbers, int size)
{

    for (int i=0; i<size; i++) {

        int minPos = i;
        for(int j=i; j<size; j++) {
            if (numbers[j] < numbers[minPos]) {
                minPos = j;
            }
        }
        int temp = numbers[i];
        numbers[i] = numbers[minPos];
        numbers[minPos] = temp;
    }

}

void insertionSort(int *numbers, int size) 
{
    for (int i=1; i<size; i++) {
        int j = i;
        while ((j >= 0)  && (numbers[j] < numbers[j-1])) {
            int temp = numbers[j];
            numbers[j] = numbers[j-1];
            numbers[j-1] = temp;
            j--;
        }
    }
}

void merge(int *lHalf, int lSize, int *rHalf, int rSize, int *result, int resultSize)
{
    int i = 0;
    int j = 0;
    int k = 0;
    while ((i<lSize) && (j<rSize)) {
        if (lHalf[i] < rHalf[j]) {
            result[k] = lHalf[i];
            k++; i++;
        } else {
            result[k] = rHalf[j];
            k++; j++;
        }
    }
    while (i<lSize) {
        result[k] = lHalf[i];
        k++; i++;    
    }
    while (j<rSize) {
        result[k] = rHalf[j];
        k++; j++;    
    }
}

void mergeSort(int *numbers, int size)
{

    if (size <= 1) return;

    int mid = size / 2;
    int *leftHalf = new int[mid];
    int *rightHalf = new int[size - mid];
    for (int i=0; i<mid; i++) {
        leftHalf[i] = numbers[i];
    }
    for (int i=mid; i<size; i++) {
        rightHalf[i-mid] = numbers[i];
    }
    mergeSort(leftHalf, mid);
    mergeSort(rightHalf, size - mid);
    merge(leftHalf, mid, rightHalf, size - mid, numbers, size);

}

bool evenFirst(int i, int j)
{

    if ((i % 2 == 0) && (j % 2 == 0)) {
        return i < j;
    }
    if ((i % 2 == 1) && (j % 2 == 1)) {
        return i<j;
    }
    return (i % 2 == 0);
}

int main() 
{

    int myNumbers[10] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int unsorted[10] { 0, 9, 2, 7, 4, 5, 6, 1, 8, 3 };

    cout << "Position of 0 is: " << binarySearch(0, myNumbers, 10) << endl;
    cout << "Position of 4 is: " << binarySearch(4, myNumbers, 10) << endl;
    cout << "Position of 10 is: " << binarySearch(10, myNumbers, 10) << endl;

    mergeSort(unsorted, 10);

    vector<int> unsortedVector1 { 0, 9, 2, 7, 4, 5, 6, 1, 8, 3 };

    sort(unsortedVector1.begin(), unsortedVector1.end(),evenFirst);

    vector<int> unsortedVector2 { 0, 9, 2, 7, 4, 5, 6, 1, 8, 3 };

    sort(unsortedVector2.begin(), unsortedVector2.end(),
         [](int i, int j) {
             if ((i % 2 == 0) && (j % 2 == 0))
             {
                 return i < j;
             }
             if ((i % 2 == 1) && (j % 2 == 1))
             {
                 return i < j;
             }
             return (i % 2 == 0);
         });
}