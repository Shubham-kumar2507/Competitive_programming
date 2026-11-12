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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int is, int ie,int ps, int pe){
        if (is > ie || ps > pe) return nullptr;
        TreeNode* root =new TreeNode(postorder[pe]);
        int i=is;
        for(;i<=ie;i++){
            if(inorder[i]==root->val)
                break;
        }
        int ls=i-is;
        int rs=ie-i;
        root->left = solve(inorder, postorder,is,i-1,ps,ps+ls-1);
        root->right = solve(inorder, postorder,i+1,ie,pe-rs,pe-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        int is=0;
        int ie=n-1;
        int ps=0;
        int pe=n-1;
        return solve(inorder,postorder,is,ie,ps,pe);
    }
};