#include<iostream>
using namespace std;

struct tree{
    int data;
    tree *leftchild;
    tree *rightchild;
    int height; // added height to support AVL balancing
};

int getHeight(tree* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

int getBalance(tree* node) {
    if (node == NULL)
        return 0;
    return getHeight(node->leftchild) - getHeight(node->rightchild);
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

// Right Rotate
tree* rightRotate(tree* y) {
    tree* x = y->leftchild;
    tree* T2 = x->rightchild;

    x->rightchild = y;
    y->leftchild = T2;

    y->height = max(getHeight(y->leftchild), getHeight(y->rightchild)) + 1;
    x->height = max(getHeight(x->leftchild), getHeight(x->rightchild)) + 1;

    return x;
}

// Left Rotate
tree* leftRotate(tree* x) {
    tree* y = x->rightchild;
    tree* T2 = y->leftchild;

    y->leftchild = x;
    x->rightchild = T2;

    x->height = max(getHeight(x->leftchild), getHeight(x->rightchild)) + 1;
    y->height = max(getHeight(y->leftchild), getHeight(y->rightchild)) + 1;

    return y;
}

tree* insert(int value, tree* root) {
    if (root == NULL) {
        tree* temp = new tree();
        temp->leftchild = NULL;
        temp->rightchild = NULL;
        temp->data = value;
        temp->height = 1;
        return temp;
    }

    if (value < root->data)
        root->leftchild = insert(value, root->leftchild);
    else if (value > root->data)
        root->rightchild = insert(value, root->rightchild);
    else
        return root; // No duplicate values

    root->height = 1 + max(getHeight(root->leftchild), getHeight(root->rightchild));

    int balance = getBalance(root);

    // LL Case
    if (balance > 1 && value < root->leftchild->data)
        return rightRotate(root);

    // RR Case
    if (balance < -1 && value > root->rightchild->data)
        return leftRotate(root);

    // LR Case
    if (balance > 1 && value > root->leftchild->data) {
        root->leftchild = leftRotate(root->leftchild);
        return rightRotate(root);
    }

    // RL Case
    if (balance < -1 && value < root->rightchild->data) {
        root->rightchild = rightRotate(root->rightchild);
        return leftRotate(root);
    }

    return root;
}

void inorder(tree* root) {
    if (root != NULL) {
        inorder(root->leftchild);
        cout << root->data << " ";
        inorder(root->rightchild);
    }
}
  
int main() {
    tree* root = NULL;
    int choice = 0;
    int value;

    cout << "1. Insert\n2. Print Inorder\n3. Exit\n";

    while (true) {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            root = insert(value, root);
            break;

        case 2:
            cout << "Inorder Traversal: ";
            inorder(root);
            cout << endl;
            break;

        case 3:
            return 0;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
}
