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
    long maxP=0;
    long sum=0;
    int trees(TreeNode* root){
        if(root==NULL) return 0;
        //sum +=root->val;
       int lefts= trees(root->left);
       int rights  = trees(root->right);
        long subts=root->val+lefts+rights;

         long s2= sum-subts;

         maxP=max(maxP,(subts*s2));
         return subts;
    }
    // int find(TreeNode* root){
    //     if(root ==NULL) return 0;

    //     int lefts=find(root->left);
    //     int rights=find(root->right);
    //     long subts=root->val+lefts+rights;

    //     long s2= sum-subts;

    //     maxP=max(maxP,(subts*s2));
    //     return subts;
    //}
    int maxProduct(TreeNode* root) {
        if(root==NULL) return 0;

        maxP=0;
       sum= trees(root);
        trees(root);
        //find(root);
        return maxP%(1000000007);
    }
};