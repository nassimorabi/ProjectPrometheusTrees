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

// Insert into BST
TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) return createNode(value);

    if (value < root->val)
        root->left = insert(root->left, value);
    else if (value > root->val)
        root->right = insert(root->right, value);

    return root;
}

// Find minimum value
TreeNode* findMin(TreeNode* root) {
    while (root && root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Find maximum value
TreeNode* findMax(TreeNode* root) {
    while (root && root->right != nullptr) {
        root = root->right;
    }
    return root;
}

// Search for a specific value
TreeNode* search(TreeNode* root, int key) {
    if (root == nullptr || root->val == key)
        return root;

    if (key < root->val)
        return search(root->left, key);
    else
        return search(root->right, key);
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

    // Find Min
    TreeNode* minNode = findMin(root);
    if (minNode != nullptr)
        cout << "\nMinimum value: " << minNode->val << endl;
    else
        cout << "\nTree is empty, no minimum value." << endl;

    // Find Max
    TreeNode* maxNode = findMax(root);
    if (maxNode != nullptr)
        cout << "Maximum value: " << maxNode->val << endl;
    else
        cout << "Tree is empty, no maximum value." << endl;

    // Search for a value
    int key;
    cout << "\nEnter value to search: ";
    cin >> key;

    TreeNode* found = search(root, key);
    if (found != nullptr)
        cout << key << " found in the tree!" << endl;
    else
        cout << key << " not found in the tree!" << endl;

    return 0;
}
