#ifndef AVL_H
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
	AVLtree(const std::vector<int64_t>& elems) {
		for (const auto& elem : elems) {
			this->insert(elem);
		}
	}

	AVLtree() {
		root = nullptr;
		mSize = 0;
		mCount = 0;
	}

	~AVLtree() {
		delete root;
	}

	bool empty() const noexcept {
		return root == nullptr;
	}

	AVLtree(const AVLtree& tmp) {
		if (tmp.empty()) {
			mCount = tmp.mCount;
			mSize = tmp.mSize;
			root = tmp.root;
		}
	}

	void insert(int k) {
		root = insertNode(root, k);
	}

	void remove(int k) {
		root = removeNode(root, k);
	}

	void print() {
		printTree(root);
		std::cout << std::endl;
	}

	std::vector<int64_t> getElems() {
		if (mSize == 0) {
			return std::vector<int64_t>();
		}
		std::vector<int64_t> elems(mCount);
		size_t position = 0;
		fillVector(root, elems, position);

		return elems;
	}

private:

	int height(Node* node) {
		if (node == nullptr) {
			return 0;
		}
		return node->height;
	}

	int balanceFactor(Node* node) {
		if (node == nullptr) {
			return 0;
		}
		return height(node->left) - height(node->right);
	}

	Node* rotateRight(Node* node) {
		Node* newRoot = node->left;
		Node* temp = newRoot->right;

		newRoot->right = node;
		node->left = temp;

		node->height = std::max(height(node->left), height(node->right)) + 1;
		newRoot->height = std::max(height(newRoot->left), height(newRoot->right)) + 1;

		return newRoot;
	}

	Node* rotateLeft(Node* node) {
		Node* newRoot = node->right;
		Node* temp = newRoot->left;

		newRoot->left = node;
		node->right = temp;

		node->height = std::max(height(node->left), height(node->right)) + 1;
		newRoot->height = std::max(height(newRoot->left), height(newRoot->right)) + 1;

		return newRoot;
	}

	Node* insertNode(Node* node,int key) {
		if (node == nullptr) {
			Node* newNode = new Node();
			newNode->key = key;
			newNode->left = nullptr;
			newNode->right = nullptr;
			newNode->height = 1;
			newNode->count = 1;
			mCount++;
			mSize++;
			return newNode;
		}

		if (key < node->key) {
			node->left = insertNode(node->left, key);
		}
		else if (key > node->key) {
			node->right = insertNode(node->right, key);
		}
		else {
			node->count += 1;
			mCount++;
			return node;
		}

		node->height = 1 + std::max(height(node->left), height(node->right));

		int balance = balanceFactor(node);

		// Left Left Case
		if (balance > 1 && key < node->left->key) {
			return rotateRight(node);
		}

		// Right Right Case
		if (balance < -1 && key > node->right->key) {
			return rotateLeft(node);
		}

		// Left Right Case
		if (balance > 1 && key > node->left->key) {
			node->left = rotateLeft(node->left);
			return rotateRight(node);
		}

		// Right Left Case
		if (balance < -1 && key < node->right->key) {
			node->right = rotateRight(node->right);
			return rotateLeft(node);
		}

		return node;
	}

	Node* getMinValueNode(Node* p) {
		Node* current = p;
		while (current->left != nullptr) {
			current = current->left;
		}
		return current;
	}

	Node* removeNode(Node* node, int key) {
		if (node == nullptr) {
			return node;
		}

		if (key < node->key) {
			node->left = removeNode(node->left, key);
		}
		else if (key > node->key) {
			node->right = removeNode(node->right, key);
		}
		else {
			if (node->left == nullptr || node->right == nullptr) {
				Node* temp = node->left ? node->left : node->right;

				if (temp == nullptr) {
					temp = node;
					node = nullptr;
				}
				else {
					*node = *temp;
				}

				delete temp;
			}
			else {
				Node* temp = getMinValueNode(node->right);
				node->key = temp->key;
				node->right = removeNode(node->right, temp->key);
			}
		}

		if (node == nullptr) {
			return node;
		}

		node->height = 1 + std::max(height(node->left), height(node->right));

		int balance = balanceFactor(node);

		// Left Left Case
		if (balance > 1 && balanceFactor(node->left) >= 0) {
			return rotateRight(node);
		}

		// Left Right Case
		if (balance > 1 && balanceFactor(node->left) < 0) {
			node->left = rotateLeft(node->left);
			return rotateRight(node);
		}

		// Right Right Case
		if (balance < -1 && balanceFactor(node->right) <= 0) {
			return rotateLeft(node);
		}

		// Right Left Case
		if (balance < -1 && balanceFactor(node->right) > 0) {
			node->right = rotateRight(node->right);
			return rotateLeft(node);
		}

		return node;
	}

	void printTree(Node* node) {
		if (node != nullptr) {
			printTree(node->left);
			std::cout << node->key << " ";
			printTree(node->right);
		}
	}

	void fillVector(Node* node, std::vector<int64_t>& elems, size_t& position) {
		if (node ==nullptr) {
			return;
		}
		fillVector(node->left, elems, position);
		for (size_t i = 0; i < node->count; i++) {
			elems[position++] = node->key;
		}
		
		fillVector(node->right, elems, position);

	}
};

#endif // AVL_H