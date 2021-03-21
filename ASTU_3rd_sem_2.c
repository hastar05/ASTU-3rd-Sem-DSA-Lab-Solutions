#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#define size 5

void EnCQueue (int [], int);
int DeCQueue (int []);
void DisplayCQueue (int [], int, int);

int CQueue[size], count = 0, front = -1, rear = -1, x;

int main()
{
	int item;
	int choice;
	char c = 'y';
 	
 	while (c == 'y' || c == 'Y')
 	{
		printf( "\t\tMAIN MENU\n\t1. Insert Element in the Circular Queue\n\t2. Delete Element from the Circular Queue\n\t3. Display Circular Queue elements\n\t4. Exit\n");
	
		printf("\nEnter your choice (1-4): ");
		scanf("%d", &choice);
		printf( "\n");
		
		switch (choice)
		{
			case 1:	
				{
					char ch = 'y';
					while ((count <= size-1) && (ch == 'y' || ch == 'Y'))
					{
						while((x = getchar()) != '\n' && x != EOF);
						printf( "Enter the number for insertion: " );
						scanf("%d", &item );
						EnCQueue (CQueue, item);
						if (count != size-1)
						{
							while((x = getchar()) != '\n' && x != EOF);
							printf( "\nDo you want to insert more elements? (y/n): " );
							scanf("%c", &ch);
						}
						count += 1;
						if (count == size)
						{
							printf ("\nQueue full! No more elements can be inserted!\n");
						}
					}
					break;
				}
				
			case 2:
				{
					char ch = 'y';
					while (ch == 'y' || ch == 'Y')
					{	
						int res = DeCQueue (CQueue);
						if (res == -1)
						{
							printf( "\nThe circular queue is empty.\n");
							break;
						}
						count -= 1;	
						printf( "The deleted element is %d.\n", res);
						while((x = getchar()) != '\n' && x != EOF);;
						printf( "\nDo you want to delete more elements? (y/n): ");
						scanf("%c", &ch);
					}
					break;
				}
					
			case 3: DisplayCQueue (CQueue, front, rear); 
					printf("\n");
					break;
					
			case 4:;
					char ch;
					while((x = getchar()) != '\n' && x != EOF);
					printf( "Do you want to exit? (y/n): ");
					scanf("%c", &ch);
					if (ch == 'y')
						exit(0);
					break;
					
			default: printf( "Please enter a valid choice.");
					 break; 
		}
		while((x = getchar()) != '\n' && x != EOF);
		printf( "\nDO YOU WANT TO CONTINUE TO THE MAIN MENU? (y/n): ");
		scanf("%c", &c);
		printf("\n");	
	}
	return 0;
}

void EnCQueue (int Cqueue[], int ele)
{
	if ((front == 0 && rear == size-1) || (rear == (front-1)%(size-1))) 
    { 
        printf("\nThe Queue is Full."); 
        return; 
    } 
  
    else if (front == -1) /* Insert First Element */
    { 
        front = rear = 0; 
    } 
  
    else if (rear == size-1 && front != 0) 
    { 
        rear = 0; 
    } 
  
    else
    { 
        rear += 1; 
    } 
	Cqueue[rear] = ele;
}

int DeCQueue (int CQueue[])
{
	if (front == -1) 
    { 
        return -1; 
    } 
  
    int data = CQueue[front]; 
    CQueue[front] = -1; 
    if (front == rear) 
    { 
        front = -1; 
        rear = -1; 
    } 
    else if (front == size-1) 
        front = 0; 
    else
        front += 1; 
  
    return data; 
}

void DisplayCQueue (int Cqueue[], int front, int rear)
{
	int i;
	if (front == -1)
	{
		printf( "The Queue is empty.");
		return;
	}
	
	printf("Elements in the Circular Queue are:\n\t"); 
    if (rear >= front) 
    { 
        for (i = front; i <= rear; i++) 
            printf("%d ", CQueue[i]); 
    } 
    else
    { 
        for (i = front; i < size; i++) 
            printf("%d ", CQueue[i]); 
  
        for (i = 0; i <= rear; i++) 
            printf("%d ", CQueue[i]); 
    } 
}
