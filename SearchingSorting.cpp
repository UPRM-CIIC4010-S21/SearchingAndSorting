
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


void mergeHalves(int *left, int lSize, int *right, int rSize, int *result)
{
    int i = 0, j = 0, k = 0;

    while (j < lSize && k < rSize) 
    {
        if (left[j] < right[k]) {
            result[i] = left[j];
            j++;
        }
        else {
            result[i] = right[k];
            k++;
        }
        i++;
    }
    while (j < lSize) {
        result[i] = left[j];
        j++; i++;
    }
    while (k < rSize) {
        result[i] = right[k];
        k++; i++;
    }
}

void mergeSort(int numbers[], int size) {

    if (size <= 1) return;

    int mid = size / 2;

    int *leftHalf = new int[mid];
    for (size_t j = 0; j < mid;j++)
        leftHalf[j]=numbers[j];

    int *rightHalf = new int[size-mid];
    for (size_t j = mid; j < size; j++)
        rightHalf[j-mid] = numbers[j];

    mergeSort(leftHalf, mid);
    mergeSort(rightHalf, size-mid);
    mergeHalves(leftHalf, mid, rightHalf, size-mid, numbers);
    delete [] leftHalf;
    delete [] rightHalf;
}


int partition(int *numbers, int left, int right) {
    int pivotIndex = left + (right - left) / 2;
    int pivotNumber = numbers[pivotIndex];
    int i = left, j = right;
    while(i <= j) {
        while(numbers[i] < pivotNumber) {
            i++;
        }
        while(numbers[j] > pivotNumber) {
            j--;
        }
        if(i <= j) {
            int temp = numbers[i];
            numbers[i] = numbers[j];
            numbers[j] = temp;
            i++;
            j--;
        }
    }
    return i;
}

void quickSortHelper(int *numbers, int left, int right) {
    if(left < right) {
        int pivotIndex = partition(numbers, left, right);
        quickSortHelper(numbers, left, pivotIndex - 1);
        quickSortHelper(numbers, pivotIndex, right);
    }
}

void quickSort(int *numbers, int size) {
    quickSortHelper(numbers, 0, size-1);
}

bool evenComparator(int i, int j)
{
    if ((i % 2 == 0) && (j % 2 == 0)) {
        // Both numbers are even
        return i < j;
    }
    else if (i % 2 == 0) {
        return true;
    }
    else {
        return false;
    }
}

int main() 
{

    int sorted[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int unsorted[10] = { 0, 9, 2, 8, 4, 7, 6, 5, 3, 1 };

    vector<int> unsortedVector1 { 0, 9, 2, 8, 4, 7, 6, 5, 3, 1 };
    vector<int> unsortedVector2 { 0, 9, 2, 8, 4, 7, 6, 5, 3, 1 };

    cout << "Position of 0 is: " << binarySearch(0, sorted, 10) << endl;
    cout << "Position of 4 is: " << binarySearch(4, sorted, 10) << endl;
    cout << "Position of 10 is: " << binarySearch(10, sorted, 10) << endl;

    quickSort(unsorted, 10);

    sort(unsortedVector1.begin(), unsortedVector1.end(), evenComparator);

    sort(unsortedVector2.begin(), unsortedVector2.end(),
         [](int i, int j) {
            if ((i % 2 == 0) && (j % 2 == 0)) {
                // Both numbers are even
                return i < j;
            }
            else if (i % 2 == 0) {
                return true;
            }
            else {
                return false;
    }});
}