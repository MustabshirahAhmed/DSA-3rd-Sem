#include<iostream>
#include<cctype>
using namespace std;

struct Stack {
    int data;
    Stack* next;
};

struct OStack {
    char op;
    OStack* next;
};

Stack* valTop = NULL;
OStack* opTop = NULL;

void pushValue(int value) {
    Stack* temp = new Stack;
    temp->data = value;
    temp->next = valTop;
    valTop = temp;
}

int popValue() {
    int value = valTop->data;
    Stack* temp = valTop;
    valTop = valTop->next;
    delete temp;
    return value;
}

void pushOp(char op) {
    OStack* temp = new OStack;
    temp->op = op;
    temp->next = opTop;
    opTop = temp;
}

char popOp() {
    char op = opTop->op;
    OStack* temp = opTop;
    opTop = opTop->next;
    delete temp;
    return op;
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/' || op == '%') return 2;
    return 0;
}

int applyOp(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '%': return a % b;
    }
    return 0;
}

int evaluateInfix(string exp) {
    for (int i = 0; i < exp.length(); i++) {
        char ch = exp[i];

        if (isdigit(ch)) {
            pushValue(ch - '0');
        } else if (ch == '(') {
            pushOp(ch);
        } else if (ch == ')') {
            while (opTop != NULL && opTop->op != '(') {
                int val2 = popValue();
                int val1 = popValue();
                char op = popOp();
                pushValue(applyOp(val1, val2, op));
            }
            popOp();
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%') {
            while (opTop != NULL && precedence(opTop->op) >= precedence(ch)) {
                int val2 = popValue();
                int val1 = popValue();
                char op = popOp();
                pushValue(applyOp(val1, val2, op));
            }
            pushOp(ch);
        }
    }

    while (opTop != NULL) {
        int val2 = popValue();
        int val1 = popValue();
        char op = popOp();
        pushValue(applyOp(val1, val2, op));
    }

    return popValue();
}

int main() {
    string infix;
    cout << "Enter Infix Expression (single-digit numbers only, no spaces): ";
    cin >> infix;
    cout << "Result: " << evaluateInfix(infix) << endl;
    return 0;
}
