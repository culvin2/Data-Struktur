#include <stdio.h>
#include <stdlib.h>


typedef struct node						// PROGRAM  GGRROOOOTTT
{
	int data;
	struct node *left;
	struct node *right;
}node;

struct node *tree;
void create_tree(struct node *);
struct node *insertElement(struct node *, int val);
void preorderTransversal(struct node *);
void inorderTransversal(struct node *);
void postorderTransversal(struct node *);
void create_tree(struct node *tree)
{
	tree = NULL;
}

struct node *insertElement(struct node *tree, int val)
{
	struct node *ptr, *nodeptr, *parentptr;
	ptr = (struct node *)malloc(sizeof(struct node));
	ptr -> data = val;
	ptr -> left = NULL;
	ptr -> right= NULL;
	if(tree==NULL)
	{
		tree = ptr;
		tree ->left=NULL;
		tree ->right = NULL;
	}else
	{
		parentptr =NULL;
		nodeptr = tree;
		while(nodeptr != NULL){
		parentptr=nodeptr;
		if(val <nodeptr->data)
			nodeptr = nodeptr->left;
		else
			nodeptr = nodeptr->right;
	}
	
		if(val<parentptr->data)
			parentptr->left=ptr;
		else
			parentptr->right=ptr;
}
return tree;
}

void preorderTransversal(struct node *tree)
{
	if(tree!=NULL)
	{
		printf("%d\t",tree->data);
		preorderTransversal(tree->left);	// FUNGSI REKURSIFF
		preorderTransversal(tree->right);
	}
}

void inorderTransversal(struct node *tree)
{
	if(tree!=NULL){
	
	inorderTransversal(tree->left);
	printf("%d\t",tree->data);
	inorderTransversal(tree->right);
	}		// FUNGSI APALAH
}

void postorderTransversal(struct node *tree)
{
	if(tree!=NULL){
	
		postorderTransversal(tree->left);
		postorderTransversal(tree->right);
		printf("%d\t",tree->data);
	}
}

int findMax(struct node *root){
// Base case 
    if (root == NULL) 
      return INT_MIN; 
    int res = root->data; 
    int lres = findMax(root->left); 
    int rres = findMax(root->right); 
    if (lres > res) 
      res = lres; 
    if (rres > res) 
      res = rres; 
    return res; 
}
int findMin(struct node *root){
	    if (root == NULL) 
      return INT_MAX; 
  
    int res = root->data; 
    int lres = findMax(root->left); 
    int rres = findMax(root->right); 
    if (lres < res) 
      res = lres; 
    if (rres < res) 
      res = rres; 
    return res; 
}

int main()
{
	int option, val;
	struct node *ptr;
	create_tree(tree);
	system("cls");
	do
	{
		printf("\n==========MAIN MENU===========");
		printf("\n	1. Masukkan Element :  ");
		printf("\n	2. PreOrder  ^^  ");
		printf("\n	3. InOrder   ^^  ");
		printf("\n	4. PostOrder ^^  ");
		printf("\n	5. Maximal	 ^^  ");
		printf("\n	6. Minimal	 ^^  ");
		printf("\n	7. BYE !  ");
		printf("\n  Masukkan Pilihan (1-7) : ");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				printf("\n Masukkan Nilai Node  : ");
				scanf("%d",&val);
				tree=insertElement(tree,val);
				break;
			case 2:
				printf("\n Element PreOrder ^^  : \n");
				preorderTransversal(tree);
				break;
			case 3:
				printf("\n Element InOrder  ^^  : \n");
				inorderTransversal(tree);
				break;
			case 4:
				printf("\n Element PostOrder ^^ : \n");
				postorderTransversal(tree);
				break;
			case 5:
				printf("Maximum Value : %d", findMax(tree));
				break;
			case 6:
				printf("\nMinimum Value : %d", findMin(tree));
				break;
		}
	}while(option!=7);
	return 0;
}
