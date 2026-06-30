#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int Value){
        data = Value;
        left=right=NULL;
    }
};
vector<int> LevelOrder(Node *root){
    queue<Node*> q;
    vector<int> ans;
    if(root==NULL) return ans;
    q.push(root);
    Node *temp;
    while(!q.empty()){
        temp=q.front();
        q.pop();
        ans.push_back(temp->data);
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
    return ans;
}

int main(){
    int x,left,right;
    queue<Node*> q;
    cout<<"Enter the value for root node: ";
    cin>>x;
    Node *root=new Node(x);
    q.push(root);
    while(!q.empty()){
        Node *temp=q.front();
        q.pop();
        cout<<"Enter the left node"<<temp->data<<": ";
        cin>>left;
        if(left!=-1){
            temp->left=new Node(left);
            q.push(temp->left);
        }
        cout<<"Enter the right Node"<<temp->data<<": " ;
        cin>>right;
        if(right!=-1){
            temp->right=new Node(right);
            q.push(temp->right);
        }
    }
    cout<< "Level Order Traversal: ";
    vector<int> result = LevelOrder(root);
    for(int val : result){
        cout<< val <<" ";
    }
    return 0;
}