#pragma once
#include "Tree.h"
/*
void Push(int x, Node** tree)
{

	if ((*tree) == nullptr)
	{
		(*tree) = new Node;
		(*tree)->data = x;
		(*tree)->left = (*tree)->right = nullptr;
		return;
	}
	if (x > (*tree)->data) Push(x,&(*tree)->right);
	else Push(x,&(*tree)->left);
}

*/


inline BinTree::BinTree(int new_number)
{
	node = new Node;
	node->value = new_number;
	node->left = nullptr;
	node->right = nullptr;
}

inline BinTree::~BinTree()
{

}

void BinTree::Push(int new_number)
{
	Node* tmp = node;
	do
	{
		if (tmp == nullptr)
		{
			tmp = new Node;

			tmp->value = new_number;
			tmp->left = nullptr;
			tmp->right = nullptr;
			return;
		}
		if (new_number > tmp->value)
		{
			if (tmp->right == nullptr)
			{
				tmp = tmp->right = new Node;

				tmp->value = new_number;
				tmp->left = nullptr;
				tmp->right = nullptr;
				return;
			}
			tmp = tmp->right;
		}
		else
		{
			if (tmp->left == nullptr)
			{
				tmp = tmp->left = new Node;

				tmp->value = new_number;
				tmp->left = nullptr;
				tmp->right = nullptr;
				return;
			}
			tmp = tmp->left;
		}

	} while (true);
}

//void print(node* t, int u)
//{
//	if (t == NULL) return;                  //Если дерево пустое, то отображать нечего, выходим
//	else //Иначе
//	{
//		print(t->l, ++u);                   //С помощью рекурсивного посещаем левое поддерево
//		for (int i = 0; i < u; ++i) cout << "|";
//		cout << t->info << endl;            //И показываем элемент
//		u--;
//	}
//	print(t->r, ++u);                       //С помощью рекурсии посещаем правое поддерево
//}