#include<iostream>
using namespace std;

struct tree {
    tree* left;
    tree* right;
    tree* next;
    char data;
};

tree* top = NULL;

void dpush(tree* temp) {
    cout << "push : " << temp->data << endl;
    temp->next = top;
    top = temp;
}

tree* dpop() {
    if (top == NULL) {
        cout << "Stack is empty.\n";
        return NULL;
    } else {
        tree* crnt = top;
        top = top->next;
        crnt->next = NULL;  
        return crnt;
    }
}

tree* tree2(string exp) {
    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] != '+' && exp[i] != '-' && exp[i] != '*' && exp[i] != '/' && exp[i] != '%') {
            tree* temp = new tree();
            temp->data = exp[i];
            temp->left = temp->right = NULL;
            dpush(temp);
        } else {
            tree* temp = new tree();
            temp->data = exp[i];
            temp->right = dpop();
            temp->left = dpop();
            dpush(temp);
        }
    }
    
    return dpop();
}

void postOrder(tree* node) {
    if (node == NULL) return;
    postOrder(node->left);
    postOrder(node->right);
    cout << node->data << " ";
}

void inOrder(tree* node) {
    if (node == NULL) return;
    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);
}

int main() {
    string exp;
    cout << "Exp : ";
    cin >> exp;

    tree* root = tree2(exp);
    cout << "Post-order traversal: ";
    postOrder(root);
    cout << endl;
    cout << "in-order traversal: ";
    inOrder(root);
    cout << endl;
 return 0;
}