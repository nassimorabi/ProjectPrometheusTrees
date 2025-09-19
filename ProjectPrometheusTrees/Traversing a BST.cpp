#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

// Function to create a new node
TreeNode* createNode(int value) {
    return new TreeNode{ value, nullptr, nullptr };
}

// Insert function for BST
TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }

    if (value < root->val) {
        root->left = insert(root->left, value);
    }
    else if (value > root->val) {
        root->right = insert(root->right, value);
    }

    return root;
}

// In-order Traversal (Left ? Root ? Right)
void inorder(TreeNode* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Pre-order Traversal (Root ? Left ? Right)
void preorder(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

// Post-order Traversal (Left ? Right ? Root)
void postorder(TreeNode* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    TreeNode* root = nullptr;

    for (int i = 0; i < n; i++) {
        int value;
        cout << "Enter value for node " << i << ": ";
        cin >> value;
        root = insert(root, value);
    }

    cout << "\nTree Traversals:\n";

    cout << "In-order   : ";
    inorder(root);    // Comment/uncomment to showcase
    cout << endl;

    cout << "Pre-order  : ";
    preorder(root);   // Comment/uncomment to showcase
    cout << endl;

    cout << "Post-order : ";
    postorder(root);  // Comment/uncomment to showcase
    cout << endl;

    return 0;
}
