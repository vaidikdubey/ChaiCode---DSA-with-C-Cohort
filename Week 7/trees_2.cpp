#include <iostream>
#include <queue>
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
    void leverOrder(Node *root) {
        if(root == NULL)
            return;

        queue<Node *> q;
        q.push(root);

        while(!q.empty()) {
            Node *temp = q.front();
            cout << temp->value << " -> ";
            q.pop();

            if(temp -> left != NULL)
                q.push(temp->left);

            if(temp -> right != NULL)
                q.push(temp->right);
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

    t.leverOrder(root);

    return 0;
}