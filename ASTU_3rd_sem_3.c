#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node 
{
   int info;
   struct node *link;
};

struct node *first = NULL;

void insert_at_begin (int);
void insert_at_end(int);
void insert_at_index (int, int);
void delete_from_begin ();
void delete_from_end ();
void delete_from_index (int);
void display ();

int count = 0;

int main() 
{
    int data, x;
    char c = 'y';
    int choice;
    while (c == 'y' || c == 'Y')
 	{
		printf ( "\t\tMAIN MENU\n\t");
		printf ("1. Insertion at beginning\n\t");
		printf ("2. Insertion at end\n\t");
		printf ("3. Insertion at index\n\t");
		printf ("4. Deletion from beginning\n\t");
		printf ("5. Deletion from end\n\t");
		printf ("6. Deletion from index\n\t");
		printf ("7. Display the linked list\n\t");
		printf ("8. Exit\n");
	
		printf( "\nEnter your choice (1-8): ");
		scanf("%d", &choice);
		printf( "\n");
		
		switch (choice)
		{
			case 1:	
				{
					char ch = 'y';
					while (ch == 'y' || ch == 'Y')
					{
						while((x = getchar()) != '\n' && x != EOF);
						printf( "Enter the number for insertion: " );
      					scanf("%d", &data);
      					insert_at_begin (data);
      					while((x = getchar()) != '\n' && x != EOF);
      					printf ("\nDo you want to insert more elements? (y/n): ");
      					scanf ("%c", &ch);
					}
					break;
				}
				
			case 2:
				{
					char ch = 'y';
					while (ch == 'y' || ch == 'Y')
					{
						while ((x = getchar()) != '\n' && x != EOF);
						printf( "Enter the number for insertion: " );
      					scanf("%d", &data);
      					insert_at_end (data);
      					while((x = getchar()) != '\n' && x != EOF);
      					printf ("\nDo you want to insert more elements? (y/n): ");
      					scanf ("%c", &ch);
					}
					break;
				}
				
			case 3:
				{
					char ch = 'y';
					while (ch == 'y' || ch == 'Y')
					{
						int index;
						printf ("Enter the index where you want to insert the element (0-%d): ", count);
						scanf ("%d", &index);
						if (index > count || index < 0)
						{
							printf ("\nInvalid index!!.\n");
							break;
						}
						printf( "Enter the number for insertion: " );
      					scanf("%d", &data);
						insert_at_index (data, index);
						while((x = getchar()) != '\n' && x != EOF);
						printf ("\nDo you want to insert more elements? (y/n): ");
      					scanf ("%c", &ch);
      				}
					break;	
				}
									
			case 4:
				{
					char ch = 'y';
					while (ch == 'y' || ch == 'Y')
					{
						delete_from_begin ();
						while((x = getchar()) != '\n' && x != EOF);
						printf ("\nDo you want to delete more elements? (y/n): ");
      					scanf ("%c", &ch);
      				}
					break;
				}
				
			case 5: 
				{
					char ch = 'y';
					while (ch == 'y' || ch == 'Y')
					{
						delete_from_end ();
						while((x = getchar()) != '\n' && x != EOF);
						printf ("\nDo you want to delete more elements? (y/n): ");
      					scanf ("%c", &ch);
      				}
					break;
				}
				
			case 6: 
				{
					char ch = 'y';
					while (ch == 'y' || ch == 'Y')
					{
						int index;
						while((x = getchar()) != '\n' && x != EOF);
						printf ("Enter the index where you want to delete the element from (0-%d): ", count - 1);
						scanf ("%d", &index);
						if (index > count - 1 || index < 0)
						{
							printf ("\nInvalid index!!\n");
							break;
						}
						delete_from_index (index);
						while((x = getchar()) != '\n' && x != EOF);
						printf ("\nDo you want to delete more elements? (y/n): ");
      					scanf ("%c", &ch);
      				}
					break;
				}	
				
			case 7: display();
					break;
				
			case 8:
				{
					char ch = 'y';
					while((x = getchar()) != '\n' && x != EOF);
					printf( "Do you want to exit? (y/n): ");
					scanf("%c", &ch);
					if (ch == 'y')
						exit(0);
					break;
				}
					
			default: printf( "Invalid choice!!\n");
					 break; 
		}
		while((x = getchar()) != '\n' && x != EOF);
		printf( "\nDO YOU WANT TO CONTINUE TO THE MAIN MENU? (y/n): ");
		scanf("%c", &c);
		printf("\n");	
	}
	return 0;
}


void insert_at_begin (int data)
{
    struct node *ptr = (struct node*) malloc (sizeof (struct node));
    ptr -> info = data;
    
    if (first == NULL)
    {
    	first = ptr;
    	first -> link = NULL;
    	count++;
    	return;
	}
    
    ptr -> link = first;
    first = ptr;
    count++;
}

void insert_at_end (int data)
{
	struct node *ptr, *temp;

  	ptr = (struct node*) malloc (sizeof (struct node));
	ptr -> info = data;


  	if (first == NULL)
	{
    	first = ptr;
    	first -> link = NULL;
    	count++;
    	return;
  	}

  	temp = first;

  	while (temp -> link != NULL)
    	temp = temp -> link;

  	temp -> link = ptr;
  	ptr -> link = NULL;
  	count++;
}

void insert_at_index (int data, int index)
{
	if (index == 0)
	{
		insert_at_begin (data);
		printf ("\nInsertion successful.\n");
		return;
	}
	struct node *ptr = (struct node*) malloc (sizeof (struct node));
   	struct node *temp = first;
   	int i;
   	for (i = 0; i < index - 1; i++)
   	{
       	temp = temp -> link;
   	}
   	ptr -> info = data;
   	ptr -> link = temp -> link;
   	temp -> link = ptr;
   	printf ("\nInsertion successful.\n");
  	count++;
}

void delete_from_begin ()
{
	if (first == NULL)
	{
    	printf ("Linked list is empty.\n");
    	return;
  	}
  	
	struct node *ptr;
	int n;
	
	n = first -> info;
  	ptr = first;
  	first = ptr -> link;
  	free (ptr);
  	count--;

  	printf("%d deleted from the beginning successfully.\n", n);	
}

void delete_from_end ()
{
	if (first == NULL)
	{
    	printf ("Linked list is empty.\n");
    	return;
  	}
  	
	int n;
  	if (count == 1)
  	{
  		n = first -> info;
  		struct node *temp = first;
  		first = NULL;
  		free (temp);
  		printf("%d deleted from the end successfully.\n", n);
  		return;
	}
  	
	struct node *ptr = first;
    struct node *temp = first -> link;
     	
	while(temp -> link != NULL)
    {
        ptr = ptr -> link;
        temp = temp -> link;
    }
    n = temp -> info;
    ptr -> link = NULL;
    free(temp);
    count--;
    
    printf("%d deleted from the end successfully.\n", n);	
}

void delete_from_index (int index)
{
	if (index == 0)
	{
		delete_from_begin ();
		return;
	}
	int n;
	struct node *ptr = first;
    struct node *temp = first -> link;
  	
  	int i;
    for (i = 0; i < index - 1; i++)
    {
        ptr = ptr -> link;
        temp = temp -> link;
    }
    n = temp -> info;
    ptr -> link = temp -> link;
    free (temp);
    count--;
    
    printf("%d deleted from the index %d successfully.\n", n, index);	
}

void display ()
{
	struct node *ptr = first;
	printf ("Traversal and display of linked list:\n\t");
	while (ptr != NULL)
	{
		printf ("%d -> ", ptr -> info);
		ptr = ptr -> link;
	}
	printf("\n");
}
