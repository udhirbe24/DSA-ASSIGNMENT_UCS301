#include <iostream>
#include <climits>
using namespace std;
// Structure for a binary tree node
struct Node {
 int data;
 Node* leŌ;
 Node* right;
 Node(int val) {
 data = val;
 leŌ = right = nullptr;
 }
};
// Helper funcƟon to check BST property
bool isBSTUƟl(Node* node, int minVal, int maxVal) {
 if (node == nullptr)
 return true;
 if (node->data <= minVal || node->data >= maxVal)
 return false;
 // Recursively check leŌ and right subtrees
 return isBSTUƟl(node->leŌ, minVal, node->data) &&
 isBSTUƟl(node->right, node->data, maxVal);
}
// Main funcƟon to check if binary tree is BST
bool isBST(Node* root) {
 return isBSTUƟl(root, INT_MIN, INT_MAX);
}
// Helper funcƟon to create a simple binary tree for tesƟng
Node* createSampleTree() {
 Node* root = new Node(10);
 root->leŌ = new Node(5);
 root->right = new Node(15);
 root->leŌ->leŌ = new Node(2);
 root->leŌ->right = new Node(7);
 root->right->leŌ = new Node(12);
 root->right->right = new Node(20);
 return root;
}
int main() {
 Node* root = createSampleTree();
 if (isBST(root))
 cout << "The given binary tree is a BST." << endl;
 else
 cout << "The given binary tree is NOT a BST." << endl;
 return 0;
}