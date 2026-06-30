#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node * left,*right;
    Node(int value){
        data=value;
        left=right=NULL;
    }
};
Node *BinaryTree(){
    int x;
    cin>>x;
    if(x==-1){
        return NULL;
    }
    Node *temp=new Node(x);
    cout<<"enter the left node of "<<temp->data<<" : ";
    temp->left=BinaryTree();
    cout<<"Enter the right node of  "<<temp->data<<" : ";
    temp->right=BinaryTree();
    return temp;
}
void Preorder(Node *root){
    if(root==NULL) return;

    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}
void postorder(Node* root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main(){
     cout<<"Enter the value for root node: ";
    Node *root=BinaryTree();
    cout<<"PreOrder Traversal"<<endl;
    Preorder(root);
    cout<<endl;
    cout<<"PostOrder Traversal"<<endl;
    postorder(root);
return 0;
}