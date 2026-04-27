#include<iostream>
#include<cstring>
using namespace std;

struct Stack {
    int top;
    string arr[100];
};

void push(Stack &s, string str) {
    s.arr[++s.top] = str;
}

string pop(Stack &s) {
    if(s.top == -1)
        return "";
    return s.arr[s.top--];
}

int precedence(char op) {
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    return 0;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Postfix to Infix
string postfixToInfix(string exp) {
    Stack s;
    s.top = -1;
    for(int i=0; i<exp.length(); i++) {
        char c = exp[i];
        if(!isOperator(c)) {
            string op(1, c);
            push(s, op);
        } else {
            string op2 = pop(s);
            string op1 = pop(s);
            string res = "(" + op1 + c + op2 + ")";
            push(s, res);
        }
    }
    return pop(s);
}

// Postfix to Prefix
string postfixToPrefix(string exp) {
    Stack s;
    s.top = -1;
    for(int i=0; i<exp.length(); i++) {
        char c = exp[i];
        if(!isOperator(c)) {
            string op(1, c);
            push(s, op);
        } else {
            string op2 = pop(s);
            string op1 = pop(s);
            string res = c + op1 + op2;
            push(s, res);
        }
    }
    return pop(s);
}

// Infix to Postfix
string infixToPostfix(string exp) {
    Stack s;
    s.top = -1;
    string result = "";
    for(int i=0; i<exp.length(); i++) {
        char c = exp[i];
        if(!isOperator(c) && c != '(' && c != ')') {
            result += c;
        } else if(c == '(') {
            string str(1, c);
            push(s, str);
        } else if(c == ')') {
            while(s.top != -1 && s.arr[s.top] != "(") {
                result += pop(s);
            }
            pop(s);
        } else {
            while(s.top != -1 && precedence(s.arr[s.top][0]) >= precedence(c)) {
                result += pop(s);
            }
            string str(1, c);
            push(s, str);
        }
    }
    while(s.top != -1) {
        result += pop(s);
    }
    return result;
}

// Infix to Prefix
string infixToPrefix(string exp) {
    int n = exp.size();
    for(int i = 0; i < n/2; i++)
        swap(exp[i], exp[n-1-i]);

    for(int i = 0; i < n; i++) {
        if(exp[i] == '(') exp[i] = ')';
        else if(exp[i] == ')') exp[i] = '(';
    }

    string postfix = infixToPostfix(exp);
    string prefix = "";
    for(int i=postfix.length()-1; i>=0; i--) {
        prefix += postfix[i];
    }
    return prefix;
}

int main() {
    int choice;
    string exp;

    do {
        cout << "\n=== Expression Conversion Menu ===\n";
        cout << "1. Postfix to Infix\n";
        cout << "2. Postfix to Prefix\n";
        cout << "3. Infix to Postfix\n";
        cout << "4. Infix to Prefix\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter Postfix Expression: ";
                cin >> exp;
                cout << "Infix: " << postfixToInfix(exp) << endl;
                break;

            case 2:
                cout << "Enter Postfix Expression: ";
                cin >> exp;
                cout << "Prefix: " << postfixToPrefix(exp) << endl;
                break;

            case 3:
                cout << "Enter Infix Expression: ";
                cin >> exp;
                cout << "Postfix: " << infixToPostfix(exp) << endl;
                break;

            case 4:
                cout << "Enter Infix Expression: ";
                cin >> exp;
                cout << "Prefix: " << infixToPrefix(exp) << endl;
                break;

            case 0:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while(choice != 0);

    return 0;
}
