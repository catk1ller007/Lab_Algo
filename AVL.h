﻿#ifndef AVL_H
#define AVL_H


#include <iostream>
#include <string>
#include <vector>

struct Node
{
	int key;
	Node* right;
	Node* left;
	size_t height;
	size_t count;


	Node(int keyVal = 0, int heightTr = 0, int countElem = 0) {
		key = keyVal;
		height = heightTr;
		count = countElem;
		left = nullptr;
		right = nullptr;
	}

	~Node() {
		delete right;
		delete left;
	}
};



class AVLtree
{
private:
	size_t mSize;
	size_t mCount;
	Node* root;

public:
	AVLtree(const std::vector<int64_t>& elems);

	AVLtree();

	~AVLtree() {
		delete root;
	}

	bool empty() const noexcept {
		return root == nullptr;
	}

	AVLtree(const AVLtree& tmp);

	void insert(int k);

	void remove(int k);

	void print();

	std::vector<int64_t> getElems();

private:

	int height(Node* node);

	int balanceFactor(Node* node);

	Node* rotateRight(Node* node);

	Node* rotateLeft(Node* node);

	Node* insertNode(Node* node, int key);

	Node* getMinValueNode(Node* p);

	Node* removeNode(Node* node, int key);

	void printTree(Node* node);

	void fillVector(Node* node, std::vector<int64_t>& elems, size_t& position);

};

#endif // AVL_H