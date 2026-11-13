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
int maxval= 0;

int solve(TreeNode* root){
    if(root==NULL) return 0;
    queue<pair<TreeNode*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        int n= q.size();
        int l=q.front().second;
        int r=q.back().second;
        maxval= max(maxval,r-l+1);
        while(n--){
            auto[node,idx] = q.front();
            q.pop();
            long long nidx= idx -l;
            if(node->left!=NULL){
                q.push({node->left,2*nidx+1});
            }if(node->right!=NULL){
                q.push({node->right,2*nidx+2});
            }
        }

    }
    return maxval;
}

    int widthOfBinaryTree(TreeNode* root) {
        return solve(root);
        
    }
};