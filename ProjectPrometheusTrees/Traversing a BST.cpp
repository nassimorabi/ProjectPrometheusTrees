#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

// ============================
// 1. CREATE a BST
// ============================

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

// ============================
// 2. TRAVERSALS
// ============================


// In-order Traversal (Left, Root, Right)
void inorder(TreeNode* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}

// Pre-order Traversal (Root, Left, Right)
void preorder(TreeNode* root) {
    if (root != nullptr) {
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Post-order Traversal (Left, Right, Root)
void postorder(TreeNode* root) {
    if (root != nullptr) {
        postorder(root->left);
        postorder(root->right);
        cout << root->val << " ";
    }
}


// ============================
// 3. FIND MIN / MAX
// ============================

/*
TreeNode* findMin(TreeNode* root) {
    while (root && root->left != nullptr) {
        root = root->left;
    }
    return root;
}

TreeNode* findMax(TreeNode* root) {
    while (root && root->right != nullptr) {
        root = root->right;
    }
    return root;
}
*/

// ============================
// 4. SEARCH
// ============================

/*
TreeNode* search(TreeNode* root, int key) {
    if (root == nullptr || root->val == key)
        return root;

    if (key < root->val)
        return search(root->left, key);
    else
        return search(root->right, key);
}
*/

// ============================
// 5. DELETE
// ============================

/*
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
            TreeNode* temp = root->right;
            while (temp->left != nullptr) temp = temp->left; // find min in right subtree
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
    }
    return root;
}
*/

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

    // ============================
    // Uncomment features step by step
    // ============================

    // 2. Traversals
    
    cout << "\nIn-order: ";
    inorder(root);

    cout << "\nPre-order: ";
    preorder(root);

    cout << "\nPost-order: ";
    postorder(root);
    cout << endl;
    

    // 3. Find Min/Max
    /*
    TreeNode* minNode = findMin(root);
    TreeNode* maxNode = findMax(root);
    if (minNode) cout << "\nMinimum value: " << minNode->val << endl;
    if (maxNode) cout << "Maximum value: " << maxNode->val << endl;
    */

    // 4. Search
    /*
    int key;
    cout << "\nEnter value to search: ";
    cin >> key;
    TreeNode* found = search(root, key);
    if (found) cout << key << " found in BST.\n";
    else cout << key << " not found in BST.\n";
    */

    // 5. Delete
    /*
    int del;
    cout << "\nEnter value to delete: ";
    cin >> del;
    root = deleteNode(root, del);

    cout << "In-order after deletion: ";
    inorder(root);
    cout << endl;
    */

    return 0;
}
