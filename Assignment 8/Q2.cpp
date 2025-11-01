#include <iostream>
using namespace std;
// Node definiƟon
struct Node {
 int data;
 Node* leŌ;
 Node* right;
 Node(int value) {
 data = value;
 leŌ = right = nullptr;
 }
};
// Insert funcƟon
Node* insert(Node* root, int value) {
 if (root == nullptr)
 return new Node(value);
 if (value < root->data)
 root->leŌ = insert(root->leŌ, value);
 else if (value > root->data)
 root->right = insert(root->right, value);
 return root;
}
// (a) Search recursive
Node* searchRecursive(Node* root, int key) {
 if (root == nullptr || root->data == key)
 return root;
 if (key < root->data)
 return searchRecursive(root->leŌ, key);
 return searchRecursive(root->right, key);
}
// (a) Search non-recursive
Node* searchNonRecursive(Node* root, int key) {
 while (root != nullptr) {
 if (key == root->data)
 return root;
 else if (key < root->data)
 root = root->leŌ;
 else
 root = root->right;
 }
 return nullptr;
}
// (b) Maximum element
Node* findMax(Node* root) {
 if (root == nullptr)
 return nullptr;
 while (root->right != nullptr)
 root = root->right;
 return root;
}
// (c) Minimum element
Node* findMin(Node* root) {
 if (root == nullptr)
 return nullptr;
 while (root->leŌ != nullptr)
 root = root->leŌ;
 return root;
}
// (d) In-order successor
Node* inorderSuccessor(Node* root, Node* node) {
 if (node->right != nullptr)
 return findMin(node->right);
 Node* successor = nullptr;
 while (root != nullptr) {
 if (node->data < root->data) {
 successor = root;
 root = root->leŌ;
 } else if (node->data > root->data) {
 root = root->right;
 } else {
 break;
 }
 }
 return successor;
}
// (e) In-order predecessor
Node* inorderPredecessor(Node* root, Node* node) {
 if (node->leŌ != nullptr)
 return findMax(node->leŌ);
 Node* predecessor = nullptr;
 while (root != nullptr) {
 if (node->data > root->data) {
 predecessor = root;
 root = root->right;
 } else if (node->data < root->data) {
 root = root->leŌ;
 } else {
 break;
 }
 }
 return predecessor;
}
// In-order traversal (for reference)
void inorder(Node* root) {
 if (root == nullptr)
 return;
 inorder(root->leŌ);
 cout << root->data << " ";
 inorder(root->right);
}
int main() {
 Node* root = nullptr;
 int n, value;
 cout << "Enter number of nodes: ";
 cin >> n;
 cout << "Enter values: ";
 for (int i = 0; i < n; i++) {
 cin >> value;
 root = insert(root, value);
 }
 cout << "\nIn-order Traversal: ";
 inorder(root);
 cout << endl;
 cout << "\nEnter value to search: ";
 int key;
 cin >> key;
 Node* foundR = searchRecursive(root, key);
 Node* foundNR = searchNonRecursive(root, key);
 cout << "Search Recursive: " << (foundR ? "Found" : "Not Found") << endl;
 cout << "Search Non-Recursive: " << (foundNR ? "Found" : "Not Found") << endl;
 Node* maxNode = findMax(root);
 Node* minNode = findMin(root);
 cout << "\nMaximum Element: " << (maxNode ? maxNode->data : -1) << endl;
 cout << "Minimum Element: " << (minNode ? minNode->data : -1) << endl;
 if (foundR) {
 Node* successor = inorderSuccessor(root, foundR);
 Node* predecessor = inorderPredecessor(root, foundR);
 cout << "\nIn-order Successor of " << key << ": "
 << (successor ? to_string(successor->data) : "None") << endl;
 cout << "In-order Predecessor of " << key << ": "
 << (predecessor ? to_string(predecessor->data) : "None") << endl;
 }
 return 0;
}