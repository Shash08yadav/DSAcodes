#include <iostream>
#include <queue>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

// In-order traversal: Left, Root, Right
void inorder(TreeNode* root) {
    if (root == nullptr)
        return;
    inorder(root->left);       // Traverse left subtree
    cout << root->data << " ";  // Visit root
    inorder(root->right);      // Traverse right subtree
}

// Pre-order traversal: Root, Left, Right
void preorder(TreeNode* root) {
    if (root == nullptr)
        return;
    cout << root->data << " ";  // Visit root
    preorder(root->left);       // Traverse left subtree
    preorder(root->right);      // Traverse right subtree
}

// Post-order traversal: Left, Right, Root
void postorder(TreeNode* root) {
    if (root == nullptr)
        return;
    postorder(root->left);      // Traverse left subtree
    postorder(root->right);     // Traverse right subtree
    cout << root->data << " ";  // Visit root
}

// Level-order traversal (Breadth-first)
void levelOrder(TreeNode* root) {
    if (root == nullptr)
        return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        cout << node->data << " ";
        q.pop();

        if (node->left != nullptr)
            q.push(node->left);
        if (node->right != nullptr)
            q.push(node->right);
    }
}

int main() {
    // Creating a simple tree for demonstration
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "In-order Traversal: ";
    inorder(root);  // Output: 4 2 5 1 6 3 7
    cout << endl;

    cout << "Pre-order Traversal: ";
    preorder(root);  // Output: 1 2 4 5 3 6 7
    cout << endl;

    cout << "Post-order Traversal: ";
    postorder(root);  // Output: 4 5 2 6 7 3 1
    cout << endl;

    cout << "Level-order Traversal: ";
    levelOrder(root);  // Output: 1 2 3 4 5 6 7
    cout << endl;

    return 0;
}
