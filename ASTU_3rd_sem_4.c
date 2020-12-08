//Priority queue using linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int priority;
	int info;
	struct node *link;
} NODE;

NODE *front = NULL;

void enqueue (int, int); //Insert the element and priority in Queue
void dequeue (); //Deletion of highest priority element from the Queue
void display (); //Print the data of Queue

int main()
{
	int choice, item, priority;
	while (1)	
	{	
		printf ("\t\tMAIN MENU\n");
		printf("\t1. Insert in prority queue\n");
		printf("\t2. Delete from priority queue\n");
		printf("\t3. Display the priority queue\n");
		printf("\t4. Exit\n");
		
		printf("\nEnter your choice : ");
		scanf("%d", &choice);
		printf( "\n");

		switch(choice)
		{
			case 1:
				printf ("Input the item value to be added in the queue : ");
				scanf ("%d", &item);
				printf ("Enter its priority : ");
				scanf ("%d", &priority);
				enqueue (item, priority);
				printf ("\n");

				break;
			
			case 2:
				dequeue ();
				printf ("\n");		
				break;
	
			case 3:
				display ();
				printf ("\n");
				break;
	
			case 4:
				exit (0);
				
			default :
				printf ("Invalid choice!\n");
				printf ("\n");
				break;

		}
	};

	return 0;
}
/*End of main*/

void enqueue (int item, int priority)
{
	NODE *tmp, *q;

	tmp = (NODE *) malloc (sizeof (NODE));
	tmp -> info = item;
	tmp -> priority = priority;
	/*Queue is empty or item to be added has priority more than first item*/
	if( front == NULL || priority < front -> priority )
	{
		tmp -> link = front;
		front = tmp;
	}
	else
	{
		q = front;
		
		while (q->link != NULL && q -> link -> priority <= priority )
			q = q -> link;
			
		tmp -> link = q -> link;
		q -> link = tmp;
	}
}
/*End of insert*/

/*Begin of del*/
void dequeue ()
{
	NODE *tmp;
	if (front == NULL)
		printf ("Queue Underflow.\n");
	else
	{
		tmp = front;
		printf ("Deleted item is %d\n", tmp -> info);
		front = front -> link;
		free (tmp);
	}
}
/*End of del*/

/*Begin of display*/
void display ()
{
	NODE *ptr;
	ptr = front;
	if (front == NULL)
		printf ("Queue is empty.\n");
	else
	{	
		printf ("The priority queue is :\n");
		printf ("Priority       Item\n");
		while (ptr != NULL)
		{
			printf ("%5d        %5d\n", ptr -> priority, ptr -> info);
			ptr = ptr -> link;
		}
	}
}
/*End of display*/
