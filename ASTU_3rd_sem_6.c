#include <stdio.h>
#include <stdlib.h>

int i, j;

void MainMenu ();
void BubbleSort( int [], int);
void SelectionSort (int [], int);
void InsertionSort (int [], int);
void QuickSort (int [], int, int);
void Display (int [], int);

int main()
{
	int a[50], size = 0;
	int choice;
	
	for(; ;)
	{
		MainMenu ();
		printf ("\n\nEnter your choice (1-7): ");
		scanf ("%d", &choice);
		switch (choice)
		{
			case 1: printf ("\nEnter the size of the array: ");
			       	scanf ("%d", &size);
			      	printf ("\nEnter the elements of the array:\n");
			       	for (i = 0; i < size; ++i)
			       	{
						printf ("Enter the element %d: ", i + 1);
						scanf ("%d", &a[i]);
			       	}
			       	break;
			       	
			case 2:	if (size == 0)
						printf ("\nThe array is empty!\n");
					else
					{
						BubbleSort (a, size);
					 	Display (a, size);
					}
					break;
						
					
			case 3:	if (size == 0)
						printf ("\nThe array is empty!\n");
					else
					{
						SelectionSort (a, size);
						Display (a, size);
					}
					break;
					
			case 4:	if (size == 0)
						printf ("\nThe array is empty!\n");
					else
					{
						InsertionSort (a, size);
						Display (a, size);
					}	
					break;
					
			case 5:	if (size == 0)
						printf ("\nThe array is empty!\n");
					else
					{
						QuickSort (a, 0, size - 1);
						printf ("\nSorted successfully using Quick Sort!\n");
						Display (a, size);
					}	
					break;
							
			case 6:	if (size == 0)
						printf ("\nThe array is empty!\n");
					else
						Display (a, size);
					break;
					
			case 7:	exit(0);
					break;
					
			default: printf ("\nInvalid Choice!!\n");
					 break;
		}
	}
	return 0;
}

void MainMenu()
{
	printf ("\n\t\t\t*MAIN MENU*");
	printf ("\n\t\t1. Enter the Array.");
	printf ("\n\t\t2. Bubble Sort (Ascending)");
	printf ("\n\t\t3. Selection Sort (Ascending)");
	printf ("\n\t\t4. Insertion Sort (Ascending)");
	printf ("\n\t\t5. Quick Sort (Ascending)");
	printf ("\n\t\t6. Display.");
	printf ("\n\t\t7. Exit.");
}

void BubbleSort (int ar[], int n)
{
	int temp;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < (n - i) - 1; ++j)
		{
			if (ar[j] > ar[j+1])
			{
				temp = ar[j];
				ar[j] = ar[j+1];
				ar[j+1] = temp;
			}
		}
	}
	printf ("\nSorted successfully using Bubble Sort!\n");
}

void SelectionSort (int AR[], int N)
{
	int small, pos, temp;
	for (i = 0; i < N - 1; ++i)
	{
		small = AR[i];
		pos = i;
		for (j = i + 1; j < N; ++j)
		{
			if (AR[j] < small)
			{
				small = AR[j];
				pos = j;
			}
		}
		temp = AR[i];
		AR[i] = AR[pos];
		AR[pos] = temp;
	}
	printf ("\nSorted successfully using Selection Sort!\n");
}

void InsertionSort (int A[], int M)
{
	int temp;
	for (i = 1; i <= M - 1; ++i)
	{
		temp = A[i];
		j = i - 1;
		while (temp < A[j] && (j >= 0))
		{
			A[j+1] = A[j];
			j = j - 1;
		}
		A[j+1] = temp;
	}
	printf ("\nSorted successfully using Insertion Sort!\n");
}

void QuickSort (int A[], int first, int last)
{
	int i, j, pivot, temp;

   	if (first < last) 
	{
    	pivot = first;
      	i = first;
      	j = last;

      	while (i < j)
		{
        	while (A[i] <= A[pivot] && i < last)
            	i++;
            	
         	while (A [j] > A[pivot])
            	j--;
            	
         	if(i < j)
			{
            	temp = A[i];
            	A[i] = A[j];
            	A[j] = temp;
         	}
      	}

      	temp = A[pivot];
      	A[pivot] = A[j];
      	A[j] = temp;
      	printf ("\nThe Array now is: ");
		for (i = 0; i < 10; ++i)
		{
			printf ("%d ", A[i]);
		}
		printf ("\n");
      	
      	QuickSort (A, first, j - 1);
      	QuickSort (A, j + 1, last);
	}
}

void Display (int ar[], int N)
{
		printf ("\nThe Array now is: ");
		for (i = 0; i < N; ++i)
		{
			printf ("%d ", ar[i]);
		}
		printf ("\n");
}
