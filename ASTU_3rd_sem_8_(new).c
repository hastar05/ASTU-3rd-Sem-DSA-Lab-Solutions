#include <stdio.h>
#include <stdlib.h>

void swap (int *a, int *b);
void merge (int arr[], int l, int m, int r);
void mergeSort (int arr[], int l, int r);
void heapify (int arr[], int n, int i);
void heapSort (int arr[], int n);
void printArray (int arr[], int n);

int main()
{
    int arr[] = {0, 43, 98, 12, 66, 100, 5, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int choice = 0, x;
    
    printf ("Given array is:\n");
    printArray (arr, n);
    
    printf ("\n1. Heap Sort\n2. Merge Sort\n");

    printf ("\nEnter your choice (1-2): ");
    scanf ("%d", &choice);

    if (choice == 1)
    {
        heapSort(arr, n);
        printf ("\nSuccessfully sorted using Heap Sort");
    }
    else if (choice == 2)
    {
        mergeSort (arr, 0, n - 1);
        printf ("\nSuccessfully sorted using Merge Sort");
    }
    else 
    {
        printf ("INVALID CHOICE!");
        exit (0);
    }
    printf("\nSorted array is \n");
    printArray(arr, n);
}

void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void merge (int arr[], int l, int m, int r)
{
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
    while (i < n1 && j < n2)
	{
        if (L[i] <= R[j])
		{
            arr[k] = L[i];
            i++;
        }
        else
		{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1)
	{
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2)
	{
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort (int arr[], int l, int r)
{
    if (l < r) 
	{
        int m = l + (r - l) / 2;
 
    	mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}
  
void heapify (int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
    	largest = left;
  
    if (right < n && arr[right] > arr[largest])
    	largest = right;
  
    if (largest != i)
	{
	    swap(&arr[i], &arr[largest]);
	    heapify(arr, n, largest);
    }
}
  
void heapSort (int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    	heapify(arr, n, i);
  
    for (int i = n - 1; i >= 0; i--) 
	{
    	swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray (int arr[], int n)
{
    for (int i = 0; i < n; ++i)
      	printf("%d ", arr[i]);
   	
	printf("\n");
}
