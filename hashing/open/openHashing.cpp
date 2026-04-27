#include<iostream>
#include<vector>
using namespace std;

// Hash function
int hashFunction(int key, int size) {
    return key % size;
}

// Insert function
void insert(int key, int size, vector<vector<int> >& table) {
    int index = hashFunction(key, size);
    table[index].push_back(key);
    cout << "Value inserted.\n";
}

// Search function (manual traversal)
void search(int key, int size, vector<vector<int> >& table) {
    int index = hashFunction(key, size);
    bool found = false;
    for (int i = 0; i < table[index].size(); i++) {
        if (table[index][i] == key) {
            found = true;
            break;
        }
    }
    if (found)
        cout << "Value found.\n";
    else
        cout << "Value not found.\n";
}

// Delete function (manual traversal)
void deleteKey(int key, int size, vector<vector<int> >& table) {
    int index = hashFunction(key, size);
    bool found = false;
    for (int i = 0; i < table[index].size(); i++) {
        if (table[index][i] == key) {
            // erase by index
            table[index].erase(table[index].begin() + i);
            found = true;
            cout << "Value deleted.\n";
            break;
        }
    }
    if (!found)
        cout << "Value not found to delete.\n";
}

// Display entire hash table
void display(int size, vector<vector<int> >& table) {
    for (int i = 0; i < size; i++) {
        cout << "Index " << i << ": ";
        for (int j = 0; j < table[i].size(); j++) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int size;
    cout << "Enter the size of the hash table: ";
    cin >> size;

    vector<vector<int> > table(size);  // hash table

    int choice, key;

    do {
        cout << "\n==== Menu ====\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Delete\n";
        cout << "4. Display\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> key;
                insert(key, size, table);
                break;

            case 2:
                cout << "Enter value to search: ";
                cin >> key;
                search(key, size, table);
                break;

            case 3:
                cout << "Enter value to delete: ";
                cin >> key;
                deleteKey(key, size, table);
                break;

            case 4:
                display(size, table);
                break;

            case 0:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}
