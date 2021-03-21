#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define size 50

void Push (char);
char Pop (char [], int *);
void Display ();
int isPalindrome ();

int count = 0;
int top = -1;
char stack[size]; 

int main()
{ 
	char item;
	
	int choice, x;
	char c = 'y';
 	
 	while (c == 'y' || c == 'Y')
 	{
		printf( "\t\tMAIN MENU\n\t1. Push element into stack\n\t2. Pop element from stack\n\t3. Display stack elements\n\t4. Check if palindrome\n\t5. Exit\n");
	
		printf ( "\nEnter your choice (1-5): ");
		scanf ("%d", &choice);
		printf ("\n");
		
		switch (choice)
		{
			case 1:	
				{
					char ch = 'y';
					while ((count <= size-1) && (ch == 'y' || ch == 'Y'))
					{
						while((x = getchar()) != '\n' && x != EOF);
						printf ( "Enter the character for insertion: ");
						scanf ("%c", &item);
						Push (item);

						if (count != size-1)
						{
							while((x = getchar()) != '\n' && x != EOF);
							printf ( "\nDo you want to insert more elements?: ");
							scanf ("%c", &ch);
						}
						count += 1;
					}
					if (count == size)
					{
						printf ("\nStack full! No more elements can be inserted!\n");
					}
					
					break;
				}
				
			case 2:
				{
					char ch = 'y';
					while (ch == 'y' || ch == 'Y')
					{	
						char res = Pop (stack, &top);
						if (res == -1)
						{
							printf ( "\nStack is empty.\n");
							break;
						}
						count -= 1;	
						printf ( "The deleted element is %c.\n", res);
						while((x = getchar()) != '\n' && x != EOF);
						printf ( "\nDo you want to delete more elements?: ");
						scanf ("%c", &ch);
					}
					break;
				}
					
			case 3: Display (); 
					printf ("\n");
					break;
					
			case 4: 
				{
					int ret = isPalindrome ();
					if (ret == 1)
					{
						printf ( "It is a palindrome.");
					}
					if (ret == 0)
						printf ( "It is not a palindrome.");
						
					printf ("\n");
					break;
				}
					
			case 5:;
					char ch;
					fflush(stdin);
					printf ( "Do you want to exit?: ");
					scanf ("%c", &ch);
					if (ch == 'y')
						exit(0);
					break;
					
					
			default: printf ( "Please enter a valid choice.");
					 break; 
		}
		fflush(stdin);
		printf ( "\nDO YOU WANT TO CONTINUE TO THE MAIN MENU?: ");
		scanf ("%c", &c);
		printf ("\n");	
	}
	return 0;
}

void Push (char ele)
{
	if (top == size - 1)
	{
		printf ( "Stack Overflow! Aboring process." );
		exit(0);
	}
	top += 1;
	stack[top] = ele;
}

char Pop (char stack[], int *top_a)
{
	int ret;
	if (*top_a == -1)
	{
		return -1;
	}
 	ret = stack[*top_a];
	*top_a -= 1;
	return ret;
}

void Display ()
{
	int i;
	if (top == -1)
	{
		printf ( "Stack is empty.");
	}
	else
	{
		printf ( "The stack now is:\n\t");
		for (i = top; i >= 0; i--)
		{
			printf ("%c\n\t", stack[i]);
		}
	}
}

int isPalindrome ()
{
	int i;
	if (top == -1)
	{
		printf ( "Stack is empty.");
		return -1;
	}
	else
	{
		int count = 0, top_copy = top;
		char stack_copy[size];
		
		for (i = 0; i <= top; i++)
		{
			stack_copy[i] = stack[i];
		}
		for (i = 0; i <= top; i++) 
		{
			char res = Pop (stack_copy, &top_copy);
    		if (stack[i] == res)
    	  		count++;
  		}
		  		
		if (count == top + 1)
			return 1;
			
		return 0;
	}
}
