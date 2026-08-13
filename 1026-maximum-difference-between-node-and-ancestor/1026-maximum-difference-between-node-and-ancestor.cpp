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
    int maxi=-1;
    void findMaxi(TreeNode* root, TreeNode* child){
        if(root == NULL) return;
        if(child == NULL) return;
        
        maxi=max(maxi,abs(root->val - child->val));
        findMaxi(root,child->left);
        findMaxi(root,child->right);
    }

    void finddif(TreeNode* root){
        if(root==NULL) return;
        findMaxi(root, root->left);
        findMaxi(root, root->right);
        finddif(root->left);
        finddif(root->right);
    }



    int maxAncestorDiff(TreeNode* root) {
        finddif(root);
        return maxi;
    }
};