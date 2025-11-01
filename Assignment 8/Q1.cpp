#include <iostream>
using namespace std;
// DefiniƟon of a node in the binary tree
struct Node {
 int data;
 Node* leŌ;
 Node* right;
 Node(int value) {
 data = value;
 leŌ = right = nullptr;
 }
};
// FuncƟon to insert a node into the BST
Node* insert(Node* root, int value) {
 if (root == nullptr)
 return new Node(value);
 if (value < root->data)
 root->leŌ = insert(root->leŌ, value);
 else
 root->right = insert(root->right, value);
 return root;
}
// Pre-order traversal (Root -> LeŌ -> Right)
void preorder(Node* root) {
 if (root == nullptr)
 return;
 cout << root->data << " ";
 preorder(root->leŌ);
 preorder(root->right);
}
// In-order traversal (LeŌ -> Root -> Right)
void inorder(Node* root) {
 if (root == nullptr)
 return;
 inorder(root->leŌ);
 cout << root->data << " ";
 inorder(root->right);
}
// Post-order traversal (LeŌ -> Right -> Root)
void postorder(Node* root) {
 if (root == nullptr)
 return;
 postorder(root->leŌ);
 postorder(root->right);
 cout << root->data << " ";
}
int main() {
 Node* root = nullptr;
 int n, value;
 cout << "Enter number of nodes: ";
 cin >> n;
 cout << "Enter values: ";
 for (int i = 0; i < n; ++i) {
 cin >> value;
 root = insert(root, value);
 }
 cout << "\nPre-order Traversal: ";
 preorder(root);
 cout << "\nIn-order Traversal: ";
 inorder(root);
 cout << "\nPost-order Traversal: ";
 postorder(root);
 cout << endl;
 return 0;
}