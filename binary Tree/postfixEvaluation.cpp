#include<iostream>
using namespace std;

struct Dstack{
	
	int data;
	Dstack* next;
};
	
	Dstack* top = NULL;
	

void dpush(Dstack* temp){
	temp->next = top;
	top	= temp;
}
	
int dpop(){
	if(top == NULL){
		cout<<"Stack is empty.\n";
		return 0;
	}
	else{
		int data = top->data;
		Dstack* crnt = top;
		top = top->next; 
	    delete(crnt);
		return data;
	}
	
}

void print(){
	//checking just if working
	Dstack* crnt = top;
	while(crnt != NULL){
		cout<<crnt->data<<" ";
		crnt = crnt->next;
	}
}

int evaluation(string postfix) {
    for (int i = 0; i < postfix.length(); i++) {
        char ch = postfix[i];

        // Check if operator
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%') {
            int var2 = dpop();
            int var1 = dpop();
            Dstack* temp = new Dstack;

            switch (ch) {
                case '+': temp->data = var1 + var2; break;
                case '-': temp->data = var1 - var2; break;
                case '*': temp->data = var1 * var2; break;
                case '/': temp->data = var1 / var2; break;
                case '%': temp->data = var1 % var2; break;
            }
            dpush(temp);
        } else {
            // Assume operand is a digit (0–9)
            Dstack* temp = new Dstack;
            temp->data = ch - '0';  // Convert char to int
            dpush(temp);
        }
    }

    return dpop();  // Final result
}

int main(){
	string postfix;
    cin>>postfix;
    cout<<evaluation(postfix);
}