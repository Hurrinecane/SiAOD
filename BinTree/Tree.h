#pragma once
#include<iostream>
#include <conio.h>

class BinTree
{
public:
	BinTree(int);
	~BinTree();

	void Push(int);
	void Print() const;

private:

	struct Node
	{
		int value;
		Node* left;
		Node* right;
	};

	Node* node = nullptr;
};
