#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(NULL) {}
};

class LinkedList {
    Node* head;
public:
    LinkedList() : head(NULL) {}
    ~LinkedList() { clear(); }

    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void insertBeginning(int x) {
        Node* n = new Node(x);
        n->next = head;
        head = n;
        cout << "Inserted at beginning.\n";
    }
    void insertEnd(int x) {
        Node* n = new Node(x);
        if (!head) { head = n; return; }
        Node* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = n;
        cout << "Inserted at end.\n";
    }
    void insertPosition(int x, int pos) {
        if (pos < 1) { cout << "Invalid position.\n"; return; }
        if (pos == 1) { insertBeginning(x); return; }
        Node* cur = head;
        for (int i = 1; cur && i < pos - 1; i++) cur = cur->next;
        if (!cur) { cout << "Position out of range.\n"; return; }
        Node* n = new Node(x);
        n->next = cur->next;
        cur->next = n;
        cout << "Inserted.\n";
    }
    void deleteBeginning() {
        if (!head) { cout << "List is empty.\n"; return; }
        Node* t = head; head = head->next; delete t;
        cout << "First node deleted.\n";
    }
    void deleteEnd() {
        if (!head) { cout << "List is empty.\n"; return; }
        if (!head->next) { delete head; head = NULL; }
        else {
            Node* cur = head;
            while (cur->next->next) cur = cur->next;
            delete cur->next; cur->next = NULL;
        }
        cout << "Last node deleted.\n";
    }
    void deletePosition(int pos) {
        if (pos < 1 || !head) { cout << "Invalid position or empty list.\n"; return; }
        if (pos == 1) { deleteBeginning(); return; }
        Node* cur = head;
        for (int i = 1; cur->next && i < pos - 1; i++) cur = cur->next;
        if (!cur->next) { cout << "Position out of range.\n"; return; }
        Node* t = cur->next; cur->next = t->next; delete t;
        cout << "Node deleted.\n";
    }
    void display() const {
        if (!head) { cout << "List is empty.\n"; return; }
        for (Node* cur = head; cur; cur = cur->next)
            cout << cur->data << (cur->next ? " -> " : " -> NULL\n");
    }
    void search(int x) const {
        int pos = 1;
        for (Node* cur = head; cur; cur = cur->next, pos++)
            if (cur->data == x) { cout << "Found at position " << pos << ".\n"; return; }
        cout << "Not found.\n";
    }
    int count() const {
        int n = 0; for (Node* cur = head; cur; cur = cur->next) n++;
        return n;
    }
    void minMax() const {
        if (!head) { cout << "List is empty.\n"; return; }
        int mn = head->data, mx = head->data;
        for (Node* cur = head->next; cur; cur = cur->next) {
            if (cur->data < mn) mn = cur->data;
            if (cur->data > mx) mx = cur->data;
        }
        cout << "Minimum = " << mn << ", Maximum = " << mx << "\n";
    }
    void reverse() {
        Node *prev = NULL, *cur = head, *next = NULL;
        while (cur) { next = cur->next; cur->next = prev; prev = cur; cur = next; }
        head = prev;
        cout << "List reversed.\n";
    }
    void sortList() {
        for (Node* i = head; i; i = i->next)
            for (Node* j = i->next; j; j = j->next)
                if (i->data > j->data) { int t=i->data; i->data=j->data; j->data=t; }
        cout << "List sorted in ascending order.\n";
    }
};

int main() {
    LinkedList list;
    int choice, value, pos;
    do {
        cout << "\n--- SINGLY LINKED LIST ---\n"
             << "1.Insert beginning  2.Insert end  3.Insert position\n"
             << "4.Delete beginning   5.Delete end  6.Delete position\n"
             << "7.Display  8.Search  9.Count nodes  10.Min/Max\n"
             << "11.Reverse  12.Sort  0.Exit\nChoice: ";
        if (!(cin >> choice)) return 0;
        switch (choice) {
            case 1: cout << "Value: "; cin >> value; list.insertBeginning(value); break;
            case 2: cout << "Value: "; cin >> value; list.insertEnd(value); break;
            case 3: cout << "Value and 1-based position: "; cin >> value >> pos; list.insertPosition(value,pos); break;
            case 4: list.deleteBeginning(); break;
            case 5: list.deleteEnd(); break;
            case 6: cout << "Position: "; cin >> pos; list.deletePosition(pos); break;
            case 7: list.display(); break;
            case 8: cout << "Value to search: "; cin >> value; list.search(value); break;
            case 9: cout << "Total nodes = " << list.count() << "\n"; break;
            case 10: list.minMax(); break;
            case 11: list.reverse(); break;
            case 12: list.sortList(); break;
            case 0: cout << "Exit.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);
    return 0;
}
