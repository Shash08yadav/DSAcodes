#include <iostream>
using namespace std;

// Definition of a TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Function to search for a value in the BST
bool searchInBST(TreeNode* root, int target) {
    // Base cases: root is null or target is found
    if (root == nullptr) {
        return false; // Value not found
    }
    if (root->val == target) {
        return true; // Value found
    }

    // Recur in the left or right subtree based on comparison
    if (target < root->val) {
        return searchInBST(root->left, target); // Search in the left subtree
    } else {
        return searchInBST(root->right, target); // Search in the right subtree
    }
}

// Function to insert a value into the BST (helper for testing)
TreeNode* insertIntoBST(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }
    if (value < root->val) {
        root->left = insertIntoBST(root->left, value);
    } else if (value > root->val) {
        root->right = insertIntoBST(root->right, value);
    }
    return root;
}

int main() {
    TreeNode* root = nullptr;

    // Create a sample BST
    root = insertIntoBST(root, 10);
    root = insertIntoBST(root, 5);
    root = insertIntoBST(root, 20);
    root = insertIntoBST(root, 3);
    root = insertIntoBST(root, 7);

    // Test the search function
    int target = 7;
    if (searchInBST(root, target)) {
        cout << "Found " << target << " in the BST." << endl;
    } else {
        cout << target << " is not in the BST." << endl;
    }

    target = 15;
    if (searchInBST(root, target)) {
        cout << "Found " << target << " in the BST." << endl;
    } else {
        cout << target << " is not in the BST." << endl;
    }

    return 0;
}
