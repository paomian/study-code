/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  It is just for test!
 *
 *        Version:  1.0
 *        Created:  2014/03/10 21时04分00秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ipaomian (ipm), xpaomian@gmail.com
 *   Organization:  FH Südwestfalen, Iserlohn
 *       测试数据:  7 8 6 11 -1    
 * =====================================================================================
 */
#include    <stdio.h>
#include	<stdlib.h>

typedef struct Node {
	int key;
	struct Node* lchild;
	struct Node* rchild;
} Node;

//个人觉得无用
void create(Node **root)
{
	int key;
	scanf("%i",&key);
	if (key == 0) {
		*root = NULL;
	} else {
		*root = (Node*)malloc(sizeof(Node));
		(*root) -> key = key;
		create(&((*root) -> lchild));
		create(&((*root) -> rchild));
	}
}

//插入函数
void insert(Node **root, int x)
{
	//	if((*root) -> rchild != NULL) printf("have rchild");
	//	if((*root) -> lchild != NULL) printf("have lchild");
	if((*root) -> key == x) printf("The insert value has existed!\n");
	else if((*root) -> key < x && (*root) -> rchild != NULL) 
	{
		//		printf("into rchild!");
		insert(&((*root) -> rchild), x);
	}
	else if((*root) -> key > x && (*root) -> lchild != NULL) 
	{
		//		printf("into lchild!");
		insert(&((*root) -> lchild), x);
	}
	else {
		Node *node = (Node*)malloc(sizeof(Node));
		node -> key = x;
		node -> lchild = NULL;
		node -> rchild = NULL;
		//		printf("%d is being inserted!\n",x);
		if((*root) -> key < x && (*root) -> rchild == NULL)
			(*root) -> rchild = node;
		else if((*root) -> key > x && (*root) -> lchild == NULL)
			(*root) -> lchild = node;
	}
}

//查找辅助函数
Node* search(Node *root, int x) 
{
	if(root == NULL) return NULL;
	else if(root -> key == x) 
		return root;
	else if(root -> key > x) 
		search(root -> lchild, x);
	else 
		search(root -> rchild, x);
}
//查找函数
void searchValue(Node *root, int x) {
	Node *node = search(root, x);
	if (node == NULL) printf("There is no key %i.\n",x);
	else {
		printf("%i is exist ! ", x);
		if (node -> lchild == NULL) printf("Its Left Chils is NULL.");
		else printf("Left Child is %i.", node -> lchild->key);

		if (node -> rchild == NULL) printf("Its Right Chils is NULL.\n");
		else printf("Right Chils is %i.\n", node -> rchild->key);
	}
}

//删除函数
Node* delete(Node **root, int x) {
	if((*root) == NULL) return NULL;
	else if((*root) -> key > x) (*root) -> lchild = delete(&((*root) -> lchild), x);
	else if((*root) -> key < x) (*root) -> rchild = delete(&((*root) -> rchild), x);
	else if((*root) -> lchild == NULL) 
	{
	    printf("lchild == NULL\n");
		Node *b = (*root) -> rchild;
		free((*root));
		return b;
	}
	else if((*root) -> rchild == NULL) {
	    printf("rchild == NULL\n");
		Node *b = (*root) -> lchild;
//		b -> rchild = (*root) -> rchild;
		free((*root));
		return b;
	}
	else {
	    printf("third\n");
		Node *b;
		for (b = (*root)->lchild ; b->rchild->rchild != NULL ; b = b->rchild);
		Node* r = b -> rchild;
		b -> rchild = r -> lchild;
		r -> lchild = (*root) -> lchild;
		r -> rchild = (*root) -> rchild;
		free((*root));
		return r;
	}
	return (*root);
}
//中序遍历
void inOrder(Node *root) {
	if (root != NULL) {
		inOrder(root -> lchild);
		printf("%i ", root -> key);
		inOrder(root -> rchild);
	}
}

int main()
{
	Node *root,*tree;
	root = (Node*)malloc(sizeof(Node));
	root -> key = 10;
	int key;
	while(scanf("%d",&key)&& key != -1)
	{
		tree = root;
		insert(&tree,key);
	}
	Node *tmp = delete(&root,10);
	printf("The BST is:");
	inOrder(tmp);
	printf("\n");
	searchValue(tmp,3);
}
