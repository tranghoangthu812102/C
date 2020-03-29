#ifndef TREE_2_SEARCH
#define TREE_2_SEARCH

typedef struct
{
    char name[20];
	char pass[20];
	int diem;
} elType;

typedef struct node
{
	elType data;
	struct node *left;
	struct node *right;
} node;

int isEmpty(node *root);
void deleteTree(node *root);

void insertTree(node **root, elType data);

node *searchTree(node *root, elType data);
node *removeNodeTree(node *root, elType data);


#endif
