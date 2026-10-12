#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 1000;
class Stack {
    int a[MAX], topIndex;
public:
    Stack() : topIndex(-1) {}
    bool empty() const { return topIndex == -1; }
    bool full() const { return topIndex == MAX - 1; }
    void push(int x) {
        if (full()) { cout << "Stack Overflow\n"; return; }
        a[++topIndex] = x;
        cout << x << " pushed.\n";
    }
    void pop() {
        if (empty()) { cout << "Stack Underflow\n"; return; }
        cout << a[topIndex--] << " popped.\n";
    }
    void peek() const {
        if (empty()) cout << "Stack is empty.\n";
        else cout << "Top = " << a[topIndex] << "\n";
    }
    void display() const {
        if (empty()) { cout << "Stack is empty.\n"; return; }
        cout << "Top -> ";
        for (int i = topIndex; i >= 0; --i) cout << a[i] << " ";
        cout << "\n";
    }
};

bool balanced(const string& s) {
    char st[MAX]; int top = -1;
    for (char c : s) {
        if (c=='(' || c=='[' || c=='{') st[++top] = c;
        else if (c==')' || c==']' || c=='}') {
            if (top < 0) return false;
            char o = st[top--];
            if (!((o=='('&&c==')') || (o=='['&&c==']') || (o=='{'&&c=='}'))) return false;
        }
    }
    return top == -1;
}
string reverseString(string s) {
    string out;
    for (int i=(int)s.size()-1; i>=0; --i) out += s[i];
    return out;
}
int precedence(char c) {
    if (c=='^') return 3;
    if (c=='*'||c=='/'||c=='%') return 2;
    if (c=='+'||c=='-') return 1;
    return 0;
}
string infixToPostfix(const string& s) {
    string out; char st[MAX]; int top=-1;
    for (char c : s) {
        if (c==' ') continue;
        if (isalnum((unsigned char)c)) out += c;
        else if (c=='(') st[++top]=c;
        else if (c==')') {
            while(top>=0 && st[top]!='(') out += st[top--];
            if(top>=0) top--;
        } else {
            while(top>=0 && st[top]!='(' &&
                  (precedence(st[top])>precedence(c) ||
                  (precedence(st[top])==precedence(c) && c!='^')))
                out += st[top--];
            st[++top]=c;
        }
    }
    while(top>=0) { if(st[top]!='(') out+=st[top]; top--; }
    return out;
}
string infixToPrefix(string s) {
    reverse(s.begin(),s.end());
    for (char &c : s) {
        if(c=='(') c=')'; else if(c==')') c='(';
    }
    string p = infixToPostfix(s);
    reverse(p.begin(),p.end());
    return p;
}

int main() {
    Stack st;
    int choice, value;
    string line;
    do {
        cout << "\n--- STACK ---\n1.Push 2.Pop 3.Peek 4.Display\n"
             << "5.Reverse string 6.Check balanced brackets\n"
             << "7.Infix to Postfix 8.Infix to Prefix 9.Demonstrate overflow\n0.Exit\nChoice: ";
        if (!(cin >> choice)) return 0;
        switch(choice) {
            case 1: cout << "Value: "; cin >> value; st.push(value); break;
            case 2: st.pop(); break;
            case 3: st.peek(); break;
            case 4: st.display(); break;
            case 5: cout << "String (one word): "; cin >> line; cout << reverseString(line) << "\n"; break;
            case 6: cout << "Expression: "; cin >> line; cout << (balanced(line) ? "Balanced\n" : "Not balanced\n"); break;
            case 7: cout << "Infix (single-character operands, no spaces): "; cin >> line; cout << "Postfix: " << infixToPostfix(line) << "\n"; break;
            case 8: cout << "Infix (single-character operands, no spaces): "; cin >> line; cout << "Prefix: " << infixToPrefix(line) << "\n"; break;
            case 9: for(int i=0;i<MAX+1;i++) st.push(i); break;
            case 0: cout << "Exit.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while(choice!=0);
    return 0;
}
