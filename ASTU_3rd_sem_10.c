//Binary and Linear Search
#include <stdio.h>
#include <stdlib.h>

void BubbleSort (int *, int);
void linearSearch (int *, int, int);
int binarySearch (int *, int, int);

int x;

int main()
{
    int size, i, ele;
    char check = 'y';
        
    printf("Enter the size of the array: ");
    scanf("%d", &size);
  
    int *arr = (int *) malloc (size * sizeof(int));
        
    printf("\nEnter the elements of the array: \n");
    for (i = 0; i < size; ++i)
    {
        printf("\tElement %d: ", i);
        scanf("%d", &arr[i]);
    }
        
    printf ("\nThe entered array is: ");
    for (i = 0; i < size; i++)
    {
        printf ("%d, ", arr[i]);
    }
    printf ("\n");
        
    while (check == 'y' || check == 'Y')
    {
        int c;
        printf("\n1. Linear search\n2. Binary search\n3. Exit\n");
            
        while((x = getchar()) != '\n' && x != EOF);
        printf ("\nEnter your choice: ");
        scanf("%d", &c);
        printf ("\n");
            
        switch(c)
        {
            case 1:
                printf("Enter the element to find: ");
                scanf("%d", &ele);
                printf ("\n");
                linearSearch(arr, ele, size);
                break;
                
            case 2:
                {
                    BubbleSort(arr, size);
                    printf ("The sorted array is: ");
                    for (i = 0; i < size; i++)
                    {
                        printf ("%d, ", arr[i]);
                    }
                    printf ("\n");
                    printf("\nEnter the element to find: ");
                    scanf("%d", &ele);
                    printf ("\n");
                    int pos = binarySearch(arr, ele, size);
                    if (pos == -1)
                    {
                        printf ("Element not found!\n");
                    }
                        
                    else
                    {
                        printf("The number is in position %d of the array.\n", pos);
                    }
                    break;
                }
                
            case 3:
                exit(0);
    
            default:
                printf("Invalid Input!\n");
                break;
        }
        while((x = getchar()) != '\n' && x != EOF);
        printf("\nDo you want to search for another element? (y/n): ");
        scanf("%c", &check);
    }                  
    return 0;
}
    
   

void BubbleSort (int *A, int n)
{
    int isSorted = 0, i, j;
    for (i = 0; i < n-1; i++)
    {
        isSorted = 1;
        for (j = 0; j < n-i-1; j++)
        {
            if (A[j]>A[j+1])
            {
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                isSorted = 0;
            }
            
        }
        if (isSorted)
        {
            return;
        }
        
    }
    
}

void linearSearch (int *a, int element, int size)
{
    int i, flag = 0;
    for (i = 0; i < size; i++)
    {
        if (a[i] == element)
        {
            printf("The number is in position %d of the array.\n", i);
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        printf ("Element not found!\n");
    }

}

int binarySearch (int *a, int element, int size)
{
    int low = 0;
    int high = size - 1;
    
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (a[mid] == element)
        {
            return mid;
        }
        
        else if (a[mid] < element)
        {
            low = mid + 1;
        }
    
        else
        {
            high = mid - 1;
        }
    }
    
    return -1;
}
