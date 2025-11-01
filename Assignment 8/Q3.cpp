#include <iostream>
#include <algorithm>
using namespace std;
struct Node {
 int data;
 Node* leŌ;
 Node* right;
 Node(int val) {
 data = val;
 leŌ = right = nullptr;
 }
};
class BST {
public:
 Node* root;
 BST() {
 root = nullptr;
 }
 // (a) Insert element (no duplicates)
 Node* insert(Node* node, int val) {
 if (node == nullptr)
 return new Node(val);
 if (val < node->data)
 node->leŌ = insert(node->leŌ, val);
 else if (val > node->data)
 node->right = insert(node->right, val);
 else
 cout << "Duplicate value " << val << " not allowed.\n";
 return node;
 }
 void insert(int val) {
 root = insert(root, val);
 }
 // (b) Delete element
 Node* findMin(Node* node) {
 while (node && node->leŌ != nullptr)
 node = node->leŌ;
 return node;
 }
 Node* deleteNode(Node* node, int val) {
 if (node == nullptr)
 return node;
 if (val < node->data)
 node->leŌ = deleteNode(node->leŌ, val);
 else if (val > node->data)
 node->right = deleteNode(node->right, val);
 else {
 // Node found
 if (node->leŌ == nullptr) {
 Node* temp = node->right;
 delete node;
 return temp;
 } else if (node->right == nullptr) {
 Node* temp = node->leŌ;
 delete node;
 return temp;
 }
 // Node with two children
 Node* temp = findMin(node->right);
 node->data = temp->data;
 node->right = deleteNode(node->right, temp->data);
 }
 return node;
 }
 void deleteValue(int val) {
 root = deleteNode(root, val);
 }
 // (c) Maximum depth of BST
 int maxDepth(Node* node) {
 if (node == nullptr)
 return 0;
 return 1 + max(maxDepth(node->leŌ), maxDepth(node->right));
 }
 // (d) Minimum depth of BST
 int minDepth(Node* node) {
 if (node == nullptr)
 return 0;
 if (!node->leŌ && !node->right)
 return 1;
 if (!node->leŌ)
 return 1 + minDepth(node->right);
 if (!node->right)
 return 1 + minDepth(node->leŌ);
 return 1 + min(minDepth(node->leŌ), minDepth(node->right));
 }
 void inorder(Node* node) {
 if (node == nullptr)
 return;
 inorder(node->leŌ);
 cout << node->data << " ";
 inorder(node->right);
 }
 void display() {
 inorder(root);
 cout << endl;
 }
};
int main() {
 BST tree;
 tree.insert(50);
 tree.insert(30);
 tree.insert(70);
 tree.insert(20);
 tree.insert(40);
 tree.insert(60);
 tree.insert(80);
 cout << "Inorder traversal of BST: ";
 tree.display();
 cout << "DeleƟng 20\n";
 tree.deleteValue(20);
 cout << "AŌer deleƟon: ";
 tree.display();
 cout << "Maximum depth: " << tree.maxDepth(tree.root) << endl;
 cout << "Minimum depth: " << tree.minDepth(tree.root) << endl;
 return 0;
}