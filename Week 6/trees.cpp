#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node *left;
    Node *right;

    Node(int value) {
        this -> value = value;
        left = NULL;
        right = NULL;
    }
};

class Tree {
public:
    void preorder(Node *root) {
        if(root != NULL) {
            cout << root->value << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    void inorder(Node *root) {
        if(root != NULL) {
            inorder(root->left);
            cout << root->value << " ";
            inorder(root->right);
        }
    }

    void postorder(Node *root) {
        if(root != NULL) {
            postorder(root->left);
            postorder(root->right);
            cout << root->value << " ";
        }
    }
};

int main() {

    Node *root = new Node(10);
    
    root->left = new Node(20);
    root->right = new Node(30);

    root->right->left = new Node(40);

    root->right->left->left = new Node(50);
    root->right->left->right = new Node(60);

    Tree t;

    cout << "Preorder Traversal:" << endl;
    t.preorder(root);
    cout << endl;

    cout << "Inorder Traversal:" << endl;
    t.inorder(root);
    cout << endl;

    cout << "Postorder Traversal:" << endl;
    t.postorder(root);
    cout << endl;

    return 0;
}