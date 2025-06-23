#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int value;
    Node *left;
    Node *right;

    Node(int value) {
        this->value = value;
        left = NULL;
        right = NULL;
    }
};

class BST {
public:
    Node *insert(Node *root, int val) {
        //Base Condition
        if(!root) return new Node(val);

        //Recursive calls
        if(root -> value < val) {
            root->right = insert(root->right, val);
        }
        if(root -> value >= val) {
            root->left = insert(root->left, val);
        }

        return root;
    }

    Node *search(Node *root, int key) {
        if(!root || root -> value == key)
            return root;

        if(root -> value < key) {
            return search(root->right, key);
        }
        else {
            return search(root->left, key);
        }
    }
    
    void preorder(Node *root) {
        if(root) {
            cout << root->value << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    void inorder(Node *root) {
        if(root) {
            inorder(root->left);
            cout << root->value << " ";
            inorder(root->right);
        }
    }

    void postorder(Node *root) {
        if(root) {
            postorder(root->left);
            postorder(root->right);
            cout << root->value << " ";
        }
    }

    void levelOrder(Node *root) {
        if(!root)
            return;

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *temp = q.front();
            cout << temp->value << " ";
            q.pop();

            if(temp -> left)
                q.push(temp->left);

            if(temp -> right)
                q.push(temp->right);
        }    
    }

    Node *min(Node *root) {
        if(!root)
            return root;

        Node *temp = root;
        
        while(temp -> left) {
            temp = temp->left;
        }

        return temp;
    }

    Node *max(Node *root) {
        if(!root)
            return root;

        Node *temp = root;
        
        while(temp -> right) {
            temp = temp->right;
        }

        return temp;
    }

    Node *inorderSucc(Node *root) {
        return min(root->right);
    }

    Node *inorderPred(Node *root) {
        return max(root->left);
    }

    Node *deletion(Node *root, int val) {
        if(!root)
            return root;

        if(root -> value < val)
            root->right = deletion(root->right, val);
        else if(root -> value > val)
            root->left = deletion(root->left, val);
        else {
            //Zero Child
            if(root -> left == NULL && root -> right == NULL) {
                delete root;
                return NULL;
            }

            //One Child
            else if(root -> left == NULL) { //Right Child Exists
                Node *temp = root->right;
                delete root;
                return temp;
            }
            else if(root -> right == NULL) { //Left Child Exists
                Node *temp = root->left;
                delete root;
                return temp;
            }
            
            //Two Child
            else {
                Node *temp = inorderSucc(root);
                root->value = temp->value;
                root->right = deletion(root->right, temp->value);
            }
        }

        return root;
    }
};

int main() {

    BST b;

    Node *root = b.insert(NULL, 10);

    root = b.insert(root, 20);
    root = b.insert(root, 30);
    root = b.insert(root, 15);
    root = b.insert(root, 5);
    root = b.insert(root, 7);
    root = b.insert(root, 12);
    root = b.insert(root, 9);

    cout << "Preorder Traversal" << endl;
    b.preorder(root);
    cout << endl;

    cout << "Inorder Traversal" << endl;
    b.inorder(root);
    cout << endl;

    cout << "Postorder Traversal" << endl;
    b.postorder(root);
    cout << endl;

    cout << "LevelOrder Traversal" << endl;
    b.levelOrder(root);
    cout << endl;

    Node *temp = b.search(root, 15);

    cout << "Key " << temp -> value << " found at address: " << temp << endl;
    
    temp = b.search(root, 8);
    
    cout << "Key found at address: " << temp << endl;

    temp = b.min(root);

    cout << "Minimum value is: " << temp->value << endl;
    
    temp = b.max(root);
    
    cout << "Maximum value is: " << temp->value << endl;

    temp = b.inorderSucc(root);

    cout << "Inorder Successor of " << root->value << " is: " << temp->value << endl;
    
    temp = b.inorderPred(root);
    
    cout << "Inorder Predecessor of " << root->value << " is: " << temp->value << endl;

    root = b.deletion(root, 20);

    cout << "LevelOrder Traversal after deletion of 20 (2 Child)" << endl;
    b.levelOrder(root);
    cout << endl;

    root = b.deletion(root, 9);

    cout << "LevelOrder Traversal after deletion of 9 (0 Child)" << endl;
    b.levelOrder(root);
    cout << endl;

    root = b.deletion(root, 15);

    cout << "LevelOrder Traversal after deletion of 15 (1 Child)" << endl;
    b.levelOrder(root);
    cout << endl;

    return 0;
}