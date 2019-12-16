#pragma once

#include <iostream>
using namespace std;

struct Node
{
	int value;
	Node* left;
	Node* right;
};

#pragma region Push
void Init(Node*& node, int new_number)
{
	if (node != nullptr) return;
	node = new Node;

	node->value = new_number;
	node->left = nullptr;
	node->right = nullptr;
}

void Push(Node*& tree, int new_number)
{
	if (tree == nullptr)
	{
		Init(tree, new_number);
		return;
	}
	Node* tmp = tree;
	do
	{
		if (new_number > tmp->value)
		{
			if (tmp->right == nullptr)
			{
				Init(tmp->right, new_number);
				return;
			}
			tmp = tmp->right;
		}
		else
		{
			if (tmp->left == nullptr)
			{
				Init(tmp->left, new_number);
				return;
			}
			tmp = tmp->left;
		}
	} while (true);

}
#pragma endregion

#pragma region Print
void Print(Node* tree, int u)
{
	if (tree == nullptr) return;
	else
	{
		Print(tree->left, ++u);
		for (int i = 0; i < u; ++i) cout << "|";
		cout << tree->value << endl;
		u--;
	}
	Print(tree->right, ++u);
}

void Print(Node* tree)
{
	int u = 0;
	if (tree == nullptr) return;
	else
	{
		Print(tree->left, ++u);
		for (int i = 0; i < u; ++i) cout << "|";
		cout << tree->value << endl;
		u--;
	}
	Print(tree->right, ++u);
}

void PrintMax(Node* tree)
{
	if (tree != nullptr)
	{
		while (tree->right != nullptr)
			tree = tree->right;
		printf_s("Максимальный элемент: %d\n", tree->value);
	}
}
#pragma endregion

#pragma region Delete
void DeleteTree(Node* tree, Node*& root)
{
	if (tree != nullptr)
		if (tree->left == nullptr && tree->right == nullptr)
			return;
		else
		{
			if (tree->left != 0)
			{
				DeleteTree(tree->left, root);
				delete tree->left;
				tree->left = nullptr;
				system("cls");
				Print(root);
			}
			if (tree->right != 0)
			{
				DeleteTree(tree->right, root);
				delete tree->right;
				tree->right = nullptr;
				system("cls");
				Print(root);
			}
		}
	system("pause");
}

void DeleteTree(Node* tree)
{
	Node* root = tree;
	if (tree != nullptr)
		if (tree->left == nullptr && tree->right == nullptr)
			return;
		else
		{
			if (tree->left != 0)
			{
				DeleteTree(tree->left, root);
				delete tree->left;
				tree->left = nullptr;
				system("cls");
				Print(root);
			}
			if (tree->right != 0)
			{
				DeleteTree(tree->right, root);
				delete tree->right;
				tree->right = nullptr;
				system("cls");
				Print(root);
			}
		}
	delete root;
	root = nullptr;
	system("cls");
}

#pragma endregion

int main()
{
	setlocale(LC_ALL, "");

	Node* T = nullptr;

	Push(T, 5);
	Push(T, 6);
	Push(T, 4);
	Push(T, 3);
	Push(T, 5);
	Push(T, 6);
	Push(T, 7);
	Push(T, 8);
	Push(T, 3);
	Push(T, -1);

	Print(T);
	PrintMax(T);
	system("pause");
	DeleteTree(T);
	system("pause");
}