#include<stdio.h>

typedef struct {
	struct Avl_node* rchild, * lchild;
	int data;
}Avl_node;

Avl_node* rotation_LL(Avl_node* parent)
{
	Avl_node* child = parent->lchild;
	parent->lchild = child->rchild;
	child->rchild = parent;
	return child;
}

Avl_node* rotation_RR(Avl_node* parent)
{
	Avl_node* child = parent->rchild;
	parent->rchild = child->lchild;
	child->lchild = parent;
	return child;
}

Avl_node* rotation_LR(Avl_node* parent)
{
	Avl_node* child = parent->lchild;
	parent->lchild = rotation_RR(child);
	return rotation_LL(parent);
}

Avl_node* rotation_RL(Avl_node* parent)
{
	Avl_node* child = parent->rchild;
	parent->rchild = rotation_LL(child);
	return rotation_RR(parent);
}

int seq_search(int list[], int key, int n)
{
	for (int i = 0; i < n ; i++)
	{
		if (key == list[i])
		{
			return i;
		}
		else return -1;
	}
}

int search_binaray(int list[], int key, int low, int high)
{
	int mid = (high + low) / 2;
	if (key > list[mid]) search_binaray(list, key, mid + 1, high);
	else if (key < list[mid]) search_binaray(list, key, low, mid - 1);
	else return mid;
}

int search_interpolation(int list[], int key, int n)
{
	int low = 0, high = n - 1, j;

	while (key > list[low] && key <= list[high])
	{
		j = ((float)(key - low) / (float)(high - low)) + low;
		if (key > list[j]) low = j + 1;
		else if (key < list[j]) high = j - 1;
		else return j;
	}
}