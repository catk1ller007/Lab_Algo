#include "AVL.h"

#include <iostream>

AVLtree::AVLtree() {
  root = nullptr;
  mSize = 0;
  mCount = 0;
}

AVLtree::AVLtree(const std::vector<int64_t>& elems) : AVLtree() {
  for (const auto& elem : elems) {
    this->insert(elem);
  }
}

AVLtree::AVLtree(const AVLtree& tmp) {
  if (tmp.empty()) {
    mCount = tmp.mCount;
    mSize = tmp.mSize;
    root = tmp.root;
  }
}

void AVLtree::insert(int64_t k) {
  root = insertNode(root, k);
}

void AVLtree::remove(int64_t k) {
   root = removeNode(root, k); 
}

void AVLtree::print() {
  printTree(root);
  std::cout << std::endl;
}

std::vector<int64_t> AVLtree::getElems() {
  if (mSize == 0) {
    return std::vector<int64_t>();
  }
  std::vector<int64_t> elems(mCount);
  size_t position = 0;
  fillVector(root, elems, position);

  return elems;
}

int AVLtree::height(Node* node) {
  if (node == nullptr) {
    return 0;
  }
  return node->height;
}

int AVLtree::balanceFactor(Node* node) {
  if (node == nullptr) {
    return 0;
  }
  return height(node->left) - height(node->right);
}

Node* AVLtree::rotateRight(Node* node) {
  Node* newRoot = node->left;
  Node* temp = newRoot->right;

  newRoot->right = node;
  node->left = temp;

  node->height = std::max(height(node->left), height(node->right)) + 1;
  newRoot->height = std::max(height(newRoot->left), height(newRoot->right)) + 1;

  return newRoot;
}

Node* AVLtree::rotateLeft(Node* node) {
  Node* newRoot = node->right;
  Node* temp = newRoot->left;

  newRoot->left = node;
  node->right = temp;

  node->height = std::max(height(node->left), height(node->right)) + 1;
  newRoot->height = std::max(height(newRoot->left), height(newRoot->right)) + 1;

  return newRoot;
}

Node* AVLtree::insertNode(Node*& node, int64_t key) {
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

Node* AVLtree::getMinValueNode(Node* p) {
  Node* current = p;
  while (current->left != nullptr) {
    current = current->left;
  }
  return current;
}

Node* AVLtree::removeNode(Node*& node, int64_t key) {
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
      } else {
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

void AVLtree::printTree(Node* node) {
  if (node != nullptr) {
    printTree(node->left);
    std::cout << node->key << " ";
    printTree(node->right);
  }
}

void AVLtree::fillVector(Node* node, std::vector<int64_t>& elems, size_t& position) {
  if (node == nullptr) {
    return;
  }
  fillVector(node->left, elems, position);
  for (size_t i = 0; i < node->count; i++) {
    elems[position++] = node->key;
  }

  fillVector(node->right, elems, position);
}
