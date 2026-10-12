#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x):data(x),left(NULL),right(NULL){}
};

Node* insertNode(Node* root, int x) {
    if(!root) return new Node(x);
    if(x<root->data) root->left=insertNode(root->left,x);
    else if(x>root->data) root->right=insertNode(root->right,x);
    return root;
}
bool searchNode(Node* root,int x) {
    if(!root) return false;
    if(root->data==x) return true;
    return x<root->data ? searchNode(root->left,x) : searchNode(root->right,x);
}
void inorder(Node* r) { if(r){inorder(r->left);cout<<r->data<<" ";inorder(r->right);} }
void preorder(Node* r) { if(r){cout<<r->data<<" ";preorder(r->left);preorder(r->right);} }
void postorder(Node* r) { if(r){postorder(r->left);postorder(r->right);cout<<r->data<<" ";} }
int height(Node* r) { return r ? 1+max(height(r->left),height(r->right)) : 0; }
int countNodes(Node* r) { return r ? 1+countNodes(r->left)+countNodes(r->right) : 0; }
int countLeaves(Node* r) { return !r ? 0 : (!r->left&&!r->right ? 1 : countLeaves(r->left)+countLeaves(r->right)); }
Node* minimumNode(Node* r) { while(r&&r->left) r=r->left; return r; }
Node* deleteNode(Node* r,int x) {
    if(!r) return NULL;
    if(x<r->data) r->left=deleteNode(r->left,x);
    else if(x>r->data) r->right=deleteNode(r->right,x);
    else {
        if(!r->left) { Node* t=r->right; delete r; return t; }
        if(!r->right) { Node* t=r->left; delete r; return t; }
        Node* s=minimumNode(r->right);
        r->data=s->data;
        r->right=deleteNode(r->right,s->data);
    }
    return r;
}
void clearTree(Node* r) { if(r){clearTree(r->left);clearTree(r->right);delete r;} }

int main() {
    Node* root=NULL;
    int choice,x,n;
    do {
        cout << "\n--- BINARY SEARCH TREE ---\n1.Insert one 2.Insert n values 3.Search\n"
             << "4.Inorder 5.Preorder 6.Postorder 7.Delete\n8.Height 9.Count nodes 10.Count leaf nodes 0.Exit\nChoice: ";
        if(!(cin>>choice)) { clearTree(root); return 0; }
        switch(choice) {
            case 1: cout<<"Value: ";cin>>x;root=insertNode(root,x);break;
            case 2: cout<<"How many values? ";cin>>n;for(int i=0;i<n;i++){cin>>x;root=insertNode(root,x);}break;
            case 3: cout<<"Search value: ";cin>>x;cout<<(searchNode(root,x)?"Found\n":"Not found\n");break;
            case 4: inorder(root);cout<<"\n";break;
            case 5: preorder(root);cout<<"\n";break;
            case 6: postorder(root);cout<<"\n";break;
            case 7: cout<<"Value to delete: ";cin>>x;if(!searchNode(root,x))cout<<"Value not found.\n";else {root=deleteNode(root,x);cout<<"Deleted.\n";}break;
            case 8: cout<<"Height (number of nodes on longest root-leaf path) = "<<height(root)<<"\n";break;
            case 9: cout<<"Total nodes = "<<countNodes(root)<<"\n";break;
            case 10: cout<<"Leaf nodes = "<<countLeaves(root)<<"\n";break;
            case 0: cout<<"Exit.\n";break;
            default: cout<<"Invalid choice.\n";
        }
    } while(choice!=0);
    clearTree(root);
    return 0;
}
