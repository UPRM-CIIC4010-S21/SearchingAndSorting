
#include <iostream>

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


int main() 
{

    int myNumbers[10] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int unsorted[10] { 0, 9, 2, 7, 4, 5, 6, 1, 8, 3 };

    cout << "Position of 0 is: " << binarySearch(0, myNumbers, 10) << endl;
    cout << "Position of 4 is: " << binarySearch(4, myNumbers, 10) << endl;
    cout << "Position of 10 is: " << binarySearch(10, myNumbers, 10) << endl;

    insertionSort(unsorted, 10);

}