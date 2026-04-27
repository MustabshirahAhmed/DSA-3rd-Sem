#include <iostream>
#include <conio.h> // c library
#include <string>
#include <unordered_map> 
#include <vector>
#include <fstream> // i use it for file input/output
#include <algorithm> //no use 
#include <ctime>
using namespace std;

// Trie Node
struct TrieNode {
    bool isEndOfWord;
    unordered_map<char, TrieNode*> children;
    TrieNode() { 
        isEndOfWord = false; 
    }
};

struct DiaryEntry {
    string date;
    string content;
    DiaryEntry* next;
    DiaryEntry(string d, string c) {
        date = d;
        content = c;
        next = nullptr;
    }
};

// Global word list and diary head
vector<string> wordList;
DiaryEntry* diaryHead = nullptr;

// Trie Class
class Trie {
    TrieNode* root;

    void collectWords(TrieNode* node, string prefix, vector<string>& result) {
        if (node->isEndOfWord)
            result.push_back(prefix);
        for (auto it = node->children.begin(); it != node->children.end(); ++it)
            collectWords(it->second, prefix + it->first, result);
    }

public:
    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* current = root;
        for (char c : word) {
            if (current->children.find(c) == current->children.end())
                current->children[c] = new TrieNode();
            current = current->children[c];
        }
        current->isEndOfWord = true;
    }

    vector<string> getSuggestions(string prefix) {
        TrieNode* current = root;
        for (char c : prefix) {
            if (current->children.find(c) == current->children.end())
                return {};
            current = current->children[c];
        }

        vector<string> suggestions;
        collectWords(current, prefix, suggestions);
        return suggestions;
    }
};

// Load words from file
void loadWordsFromFile(string filename, Trie& trie) {
    ifstream file(filename);
    string word;
    while (getline(file, word)) {
        if (!word.empty()) {
            wordList.push_back(word);
            trie.insert(word);
        }
    }
    file.close();
}

// Add diary entry
void addDiaryEntry(string date, string content) {
    DiaryEntry* newEntry = new DiaryEntry(date, content);
    if (diaryHead == nullptr)
        diaryHead = newEntry;
    else {
        DiaryEntry* temp = diaryHead;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newEntry;
    }
}

// View all diary entries
void viewDiaryEntries() {
    if (diaryHead == nullptr) {
        cout << "No diary entries found.\n";
        return;
    }
    DiaryEntry* temp = diaryHead;
    while (temp != nullptr) {
        cout << "\nDate: " << temp->date << "\nEntry:\n" << temp->content << "\n";
        temp = temp->next;
    }
}

// Find entry by date
void findEntryByDate(string date) {
    DiaryEntry* temp = diaryHead;
    bool found = false;
    while (temp != nullptr) {
        if (temp->date == date) {
            cout << "\nDate: " << temp->date << "\nEntry:\n" << temp->content << "\n";
            found = true;
        }
        temp = temp->next;
    }
    if (!found) cout << "No entry found for this date.\n";
}

// Get current date string
string getCurrentDate() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    char buf[20];
    strftime(buf, sizeof(buf), "%Y-%m-%d", ltm);
    return string(buf);
}

int main() {
    Trie trie;
    string filename = "dictionary.txt";
    loadWordsFromFile(filename, trie);

    string currentDate = getCurrentDate();
    string fullSentence = "";
    string currentWord = "";
    char ch;
    int enterCount = 0;

    cout << "Start typing your diary entry (ESC = end typing, Double Enter = save and exit):\n";
    cout << "Date: " << currentDate << endl;

    while (true) {
        ch = getch();

        if (ch == 27) 
            break;  // ESC to exit typing loop

        if (ch == 8) { // Backspace
            if (!currentWord.empty())
                currentWord.pop_back();
            else if (!fullSentence.empty())
                fullSentence.pop_back();
        }
        else if (ch == ' ' || ch == 13) {
            // Get suggestions
            vector<string> suggestions = trie.getSuggestions(currentWord);

            // If Enter is pressed and suggestions exist, autocomplete with top suggestion
            if (ch == 13 && !suggestions.empty()) {
                fullSentence += suggestions[0];
            } else {
                fullSentence += currentWord;
            }

            if (ch == ' ') fullSentence += ' ';
            if (ch == 13) {
                enterCount++;
                // fullSentence += '\n';
                if (enterCount == 2) {
                    addDiaryEntry(currentDate, fullSentence);
                    cout << "\nDiary entry saved!\n";
                    return 0;
                }
            } else enterCount = 0;

            currentWord.clear();
        }
        else {
            currentWord += ch;
            enterCount = 0;
        }

        // Refresh screen
        system("cls");
        cout << "Diary initialized for: " << currentDate << endl;
        cout << "Start typing your diary entry (ESC = end typing, Double Enter = save and exit):\n";
        cout << "Sentence so far:\n" << fullSentence << currentWord << endl;

        // Display suggestions for current word
        vector<string> suggestions = trie.getSuggestions(currentWord);
        if (!currentWord.empty() && !suggestions.empty()) {
            cout << "\nSuggestions:\n";
            for (string s : suggestions)
                cout << s << endl;
        }
    }

    // After ESC — save entry
    addDiaryEntry(currentDate, fullSentence);

    int choice;
    do {
        cout << "\n\nDiary Menu\n1. View All Entries\n2. Find Entry by Date\n3. Exit\nEnter choice: ";
        cin >> choice;
        cin.ignore();
        if (choice == 1)
            viewDiaryEntries();
        else if (choice == 2) {
            string searchDate;
            cout << "Enter date (YYYY-MM-DD): ";
            getline(cin, searchDate);
            findEntryByDate(searchDate);
        }
    } while (choice != 3);

    cout << "\nProgram ended.\n";
    return 0;
}
