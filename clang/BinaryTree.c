/*
 * =====================================================================================
 *
 *       Filename:  bt.c
 *
 *    Description:  二叉树
 *
 *        Version:  1.0
 *        Created:  2014/03/13 12时32分44秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ipaomian (ipm), xpaomian@gmail.com
 *   Organization:  sdutlinux
 *
 * =====================================================================================
 */

#include<stdio.h>
#include<stdlib.h>

typedef struct n {
	int key;
	struct n* lchild;
	struct n* rchild;
} Node;

void create(Node** root)
{
	int key;
	scanf("%i", &key);
	if(0 == key)
		*root = NULL;
	else
	{
		if((*root = (Node*)malloc(sizeof(Node))) == NULL)
		{
			printf("Create malloc faild.\n");
			exit(1);
		}
		(*root) -> key = key;
		printf("Create succed with key:%d.\n", key);
		create(&((*root) -> lchild));
		create(&((*root) -> rchild));
	}
}

void preOrder(Node *root)
{
	if(root != NULL)
	{
		printf("visited by pre order: %d.\n", root -> key);
		preOrder(root -> lchild);
		preOrder(root -> rchild);
	}
}

void inOrder(Node *root)
{
	if(root != NULL)
	{
		inOrder(root -> lchild);
		printf("visited by in order: %d.\n", root -> key);
		inOrder(root -> rchild);
	}
}

void postOreder(Node *root)
{
	if(root != NULL)
	{
		postOreder(root -> lchild);
		postOreder(root -> rchild);
		printf("visited by post order: %d.\n", root -> key);
	}
}

int main()
{
	Node *root;
	create(&root);
	preOrder(root);
	inOrder(root);
	postOreder(root);
	return 0;
}
