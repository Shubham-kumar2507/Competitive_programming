/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
vector<int> res;
unordered_map<TreeNode*,TreeNode*> par;
void bfs(TreeNode* target, int k){
    unordered_set<int> vis;
    queue<TreeNode*> q;
    q.push(target);

    vis.insert(target->val);
    while(!q.empty()){
        int n= q.size();
        if(k==0)
            break;
        while(n--){
            TreeNode* temp= q.front();
            q.pop();
            if(temp->left!=NULL && !vis.count(temp->left->val)){
                q.push(temp->left);
                vis.insert(temp->left->val);
            }
            if(temp->right!=NULL && !vis.count(temp->right->val)){
                q.push(temp->right);
                vis.insert(temp->right->val);
            }
            if(par.count(temp)&& !vis.count(par[temp]->val)){
                q.push(par[temp]);
                vis.insert(par[temp]->val);
            }

        }
        k--;
    }
    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();
        res.push_back(temp->val);
    }
}
    void solve(TreeNode* root){
        if(root==NULL) return;
        
        if(root->left!=NULL){
            par[root->left] = root;
        }
        solve(root->left);
        if(root->right!=NULL){
                par[root->right]=root;
            }
        solve(root->right);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        solve(root);
        bfs(target,k);
        return res;
    }
};