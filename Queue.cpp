#include <iostream>
using namespace std;
const int MAX = 100;

class Queue {
    int a[MAX], frontIndex, rearIndex;
public:
    Queue() : frontIndex(-1), rearIndex(-1) {}
    bool empty() const { return frontIndex == -1; }
    bool full() const { return rearIndex == MAX-1; }
    void enqueue(int x) {
        if(full()) { cout << "Queue Overflow\n"; return; }
        if(empty()) frontIndex=0;
        a[++rearIndex]=x;
        cout << x << " inserted.\n";
    }
    void dequeue() {
        if(empty()) { cout << "Queue Underflow\n"; return; }
        cout << a[frontIndex] << " removed.\n";
        if(frontIndex==rearIndex) frontIndex=rearIndex=-1;
        else frontIndex++;
    }
    void peek() const {
        if(empty()) cout << "Queue is empty.\n";
        else cout << "Front = " << a[frontIndex] << "\n";
    }
    void display() const {
        if(empty()) { cout << "Queue is empty.\n"; return; }
        for(int i=frontIndex;i<=rearIndex;i++) cout << a[i] << " ";
        cout << "\n";
    }
    int count() const { return empty() ? 0 : rearIndex-frontIndex+1; }
    void search(int x) const {
        if(empty()) { cout << "Queue is empty.\n"; return; }
        for(int i=frontIndex;i<=rearIndex;i++)
            if(a[i]==x) { cout << "Found at queue position " << i-frontIndex+1 << "\n"; return; }
        cout << "Not found.\n";
    }
    void minMax() const {
        if(empty()) { cout << "Queue is empty.\n"; return; }
        int mn=a[frontIndex], mx=mn;
        for(int i=frontIndex+1;i<=rearIndex;i++) {
            if(a[i]<mn) mn=a[i]; if(a[i]>mx) mx=a[i];
        }
        cout << "Minimum = " << mn << ", Maximum = " << mx << "\n";
    }
    void reverseQueue() {
        if(empty()) { cout << "Queue is empty.\n"; return; }
        for(int i=frontIndex,j=rearIndex;i<j;i++,j--) {
            int t=a[i]; a[i]=a[j]; a[j]=t;
        }
        cout << "Queue reversed (display order).\n";
    }
};

class CircularQueue {
    int a[MAX], f, r, n;
public:
    CircularQueue():f(-1),r(-1),n(0){}
    void enqueue(int x) {
        if(n==MAX) { cout << "Circular Queue Overflow\n"; return; }
        if(n==0) f=0;
        r=(r+1)%MAX; a[r]=x; n++;
    }
    void dequeue() {
        if(n==0) { cout << "Circular Queue Underflow\n"; return; }
        cout << a[f] << " removed.\n"; f=(f+1)%MAX; n--;
        if(n==0) f=r=-1;
    }
    void display() const {
        if(n==0) { cout << "Circular Queue is empty.\n"; return; }
        for(int i=0;i<n;i++) cout << a[(f+i)%MAX] << " ";
        cout << "\n";
    }
};

int main() {
    Queue q; CircularQueue cq;
    int choice,x;
    do {
        cout << "\n--- QUEUE ---\n1.Enqueue 2.Dequeue 3.Peek 4.Display\n"
             << "5.Count 6.Search 7.Min/Max 8.Reverse display order\n"
             << "9.Circular queue enqueue 10.Circular queue dequeue 11.Circular queue display\n0.Exit\nChoice: ";
        if(!(cin>>choice)) return 0;
        switch(choice) {
            case 1: cout<<"Value: ";cin>>x;q.enqueue(x);break;
            case 2:q.dequeue();break;
            case 3:q.peek();break;
            case 4:q.display();break;
            case 5:cout<<"Count = "<<q.count()<<"\n";break;
            case 6:cout<<"Search value: ";cin>>x;q.search(x);break;
            case 7:q.minMax();break;
            case 8:q.reverseQueue();break;
            case 9:cout<<"Value: ";cin>>x;cq.enqueue(x);break;
            case 10:cq.dequeue();break;
            case 11:cq.display();break;
            case 0:cout<<"Exit.\n";break;
            default:cout<<"Invalid choice.\n";
        }
    } while(choice!=0);
    return 0;
}
