/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
// void cnt(TreeNode* root, int &n){
//     if(root==NULL) return;
//     cnt(root->left,n);
//     n++;
//     cnt(root->right,n);

//}
    int getlh(TreeNode*root){
        TreeNode* temp= root;
        int lh =0;
        while(temp){
            temp = temp->left;
            lh++;
        }
        return lh;
    }
    int getrh(TreeNode*root){
        TreeNode* temp= root;
        int rh =0;
        while(temp){
            temp = temp->right;
            rh++;
        }
        return rh;
    }
    int countNodes(TreeNode* root) {
        // int n=0;
        // cnt(root, n);
        // return n;
        if(root==NULL) return 0;
        int lh=getlh(root);
        int rh=getrh(root);
        

        if(lh==rh) return (pow(2,lh)-1);

        return countNodes(root->left) + countNodes(root->right)+1;
    }
};