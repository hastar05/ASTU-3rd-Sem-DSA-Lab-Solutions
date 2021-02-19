#include <stdio.h>
#include <malloc.h>

typedef struct BSTnode BSTnode;
struct BSTnode
{
	int info;
	struct BSTnode *left;
	struct BSTnode *right;
};

BSTnode* GetNewNode (int data);
BSTnode* Insert (BSTnode* root, int data);
int Search (BSTnode* root,int data);
BSTnode* FindMin(BSTnode* root);
BSTnode* Delete(struct BSTnode *root, int data);

int main ()
{
	BSTnode* root = NULL;	//creating an empty tree
	char c = 'y';
	int  choice, num, x;
	
	while (1)
	{
		printf( "\t\tMAIN MENU\n\t1. Insert\n\t2. Search\n\t3. Delete\n\t4. Post Order Traversal\n\t5. Exit\n");
		printf ("\nEnter your choice (1-5): ");
		scanf ("%d", &choice);
		printf ("\n");
		
		switch (choice)
		{
			case 1:
				{
					while (c == 'y' || c == 'Y')
					{
						printf ("Enter the number for insertion: ");
						scanf ("%d", &num);
						root = Insert (root, num);
						while((x = getchar()) != '\n' && x != EOF);
						printf ("\nDo you want to insert more numbers? (y/n): ");
						scanf ("%c", &c);
						printf ("\n");
					}
					break;	
				}
			
			case 2:
				{
					printf ("Enter the number to search for: ");
					scanf ("%d", &num);
					if (Search (root, num) == 0)
					{
						printf ("\nFound!\n\n");
					}
					else 
						printf ("\nNot found!\n\n");
					break;
				}
				
			case 3:
				{
					while (c == 'y' || c == 'Y')
					{
						printf ("Enter the number for deletion: ");
						scanf ("%d", &num);
						root = Delete (root, num);
						while((x = getchar()) != '\n' && x != EOF);
						printf ("\nDo you want to delete more numbers? (y/n): ");
						scanf ("%c", &c);
						printf ("\n");
					}
					break;
				}
				
			case 4:break;
				
			case 5:break;
				
			default: 
					printf ("INVALID CHOCIE!\n\n");
					break;
		}
	}
	
	return 0;
}

BSTnode* GetNewNode (int data)
{
	BSTnode* newNode = (BSTnode*) malloc (sizeof (BSTnode));
	newNode -> info = data;
	newNode -> left = NULL;
	newNode -> right = NULL;
	return newNode;
}

BSTnode* Insert (BSTnode* root, int data)
{
	if (root == NULL)	//empty tree
	{
		root = GetNewNode (data);
	}
	
	else if (data <= root -> info)
	{
		root -> left = Insert (root -> left, data);
	}
	
	else
	{
		root -> right = Insert (root -> right, data);
	}
	return root;
}

int Search (BSTnode* root,int data) 
{
	if (root == NULL) 
	{
		return -1;
	}
	
	else if (root -> info == data) 
	{
		return 0;
	}
	
	else if (data <= root -> info) 
	{
		return Search (root->left, data);
	}
	
	else 
	{
		return Search (root -> right, data);
	}
}

BSTnode* FindMin(BSTnode* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}

// Function to search a delete a value from tree.
BSTnode* Delete(struct BSTnode *root, int data) {
	if(root == NULL) return root; 
	else if(data < root->info) root->left = Delete(root->left,data);
	else if (data > root->info) root->right = Delete(root->right,data);
	// Wohoo... I found you, Get ready to be deleted	
	else {
		// Case 1:  No child
		if(root->left == NULL && root->right == NULL) { 
			free (root);
			root = NULL;
		}
		//Case 2: One child 
		else if(root->left == NULL) {
			struct BSTnode *temp = root;
			root = root->right;
			free (temp);
		}
		else if(root->right == NULL) {
			struct BSTnode *temp = root;
			root = root->left;
			free (temp);
		}
		// case 3: 2 children
		else { 
			struct BSTnode *temp = FindMin(root->right);
			root->info = temp->info;
			root->right = Delete(root->right,temp->info);
		}
	}
	return root;
}
