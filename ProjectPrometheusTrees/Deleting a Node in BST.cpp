#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

// Create a new node
TreeNode* createNode(int value) {
    return new TreeNode{ value, nullptr, nullptr };
}

// Insert into BST
TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) return createNode(value);

    if (value < root->val)
        root->left = insert(root->left, value);
    else if (value > root->val)
        root->right = insert(root->right, value);

    return root;
}

// Find minimum value (for delete case)
TreeNode* findMin(TreeNode* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Delete from BST
TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) return root;

    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    }
    else {
        // Case 1: No child
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        // Case 2: One child
        else if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Two children
        else {
            TreeNode* temp = findMin(root->right); // find successor
            root->val = temp->val; // copy value
            root->right = deleteNode(root->right, temp->val); // delete duplicate
        }
    }
    return root;
}

// In-order Traversal (for checking result)
void inorder(TreeNode* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}

int main() {
    TreeNode* root = nullptr;
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value for node " << i << ": ";
        cin >> value;
        root = insert(root, value);
    }

    cout << "\nIn-order before deletion: ";
    inorder(root);
    cout << endl;

    int key;
    cout << "Enter value to delete: ";
    cin >> key;

    root = deleteNode(root, key);

    cout << "\nIn-order after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}


//HAVE FUN AND GOOD LUCK