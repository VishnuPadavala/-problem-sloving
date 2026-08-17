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
    TreeNode* bstFromPreorder(vector<int>& p) {
        TreeNode *root=NULL;
        for(int i=0;i<p.size();i++){
            constracttree(p[i],root);
        }
        return root;
    }
    void constracttree(int val,TreeNode *&root){
        if(!root){
            root=new TreeNode(val);
            return;
        }
        if(root->val >= val){
            constracttree(val,root->left);
        }else{
            constracttree(val,root->right);
        }
    }
};