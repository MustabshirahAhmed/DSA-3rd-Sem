#include<iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

// Create new node
TreeNode* createNode(int data) {
    TreeNode* node = new TreeNode;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// BST Insert
TreeNode* insert(TreeNode* root, int data) {
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

// Check if two trees are equal
bool isEqual(TreeNode* t1, TreeNode* t2) {
    if (t1 == NULL && t2 == NULL)
        return true;
    if (t1 != NULL && t2 != NULL)
        return (t1->data == t2->data) &&
               isEqual(t1->left, t2->left) &&
               isEqual(t1->right, t2->right);
    return false;
}

// Store elements in array (in-order)
void storeInOrder(TreeNode* root, int arr[], int& index) {
    if (root == NULL)
        return;
    storeInOrder(root->left, arr, index);
    arr[index++] = root->data;
    storeInOrder(root->right, arr, index);
}

// Bubble Sort Descending
void sortDescending(int arr[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-1-i; j++)
            if (arr[j] < arr[j+1])
                swap(arr[j], arr[j+1]);
}

// Print Array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// In-order Traversal Display
void inOrder(TreeNode* root) {
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main() {
    TreeNode* root1 = NULL;
    TreeNode* root2 = NULL;
    int choice, data, treeChoice;

    do {
        cout << "\n=== Binary Tree Menu ===\n";
        cout << "1. Insert into Tree 1\n";
        cout << "2. Insert into Tree 2\n";
        cout << "3. Display Tree 1 (In-order)\n";
        cout << "4. Display Tree 2 (In-order)\n";
        cout << "5. Check if both Trees are Equal\n";
        cout << "6. Sort Tree 1 elements in Descending Order\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value to insert into Tree 1: ";
                cin >> data;
                root1 = insert(root1, data);
                break;

            case 2:
                cout << "Enter value to insert into Tree 2: ";
                cin >> data;
                root2 = insert(root2, data);
                break;

            case 3:
                cout << "Tree 1 In-order: ";
                inOrder(root1);
                cout << endl;
                break;

            case 4:
                cout << "Tree 2 In-order: ";
                inOrder(root2);
                cout << endl;
                break;

            case 5:
                if (isEqual(root1, root2))
                    cout << "Trees are Equal and have the Same Structure.\n";
                else
                    cout << "Trees are NOT Equal.\n";
                break;

            case 6: {
                int arr[100], index = 0;
                storeInOrder(root1, arr, index);
                sortDescending(arr, index);
                cout << "Tree 1 elements in Descending Order: ";
                printArray(arr, index);
                break;
            }

            case 0:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while(choice != 0);

    return 0;
}
