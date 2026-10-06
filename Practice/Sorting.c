/* Sorting Algorithm's */
#include <stdio.h>

/* 1 ===> Bubble Sort */
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
}

/* 2 ===> Insertion Sort */
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++) // case 1: we assume first element is sorted already
    {
        int key = arr[i];              // Save the first value of unsorted part of array into key
        int j = i - 1;                 // index for placing the element to its correct position
        while (j >= 0 && key < arr[j]) // case 2 : traverse till j is greater or equal to 0 and key is smaller then the value of arr of j
        {
            arr[j + 1] = arr[j]; // shift the element toward for making vacant space for correct element
            j--;                 // return to previous position
        }
        arr[j + 1] = key; // put the correct value then continue to next element
    }
}

/* 3 ===> Selection Sort */
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - i - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }
        if (minIdx != i)
        {
            int t = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = t;
        }
    }
}

int main()
{
    int arr[] = {5, 12, 14, 6, 7, 8, 9, 10, 2, 3, 4, 11, 18, 19, 20};
    int n = sizeof(arr) / sizeof(int);
    printf("Array Before Sorting  : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    // bubbleSort(arr, n);
    // insertionSort(arr, n);
    // selectionSort(arr, n);
    printf("\nArray After Sorting  : ");
    for (int j = 0; j < n; j++)
    {
        printf("%d ", arr[j]);
    }
    printf("\n");
    return 0;
}