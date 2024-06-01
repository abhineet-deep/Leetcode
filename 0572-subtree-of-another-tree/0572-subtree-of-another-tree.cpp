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
    
    bool checkSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot) return true;
        if(!root || !subRoot) return false;
        
        if(root->val != subRoot->val) return false;
        
        bool l = checkSubtree(root->left,subRoot->left);
        bool r = checkSubtree(root->right,subRoot->right);
        
        if(l && r) return true;
        else return false;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if(!root || !subRoot) return false;
    
        if(root->val == subRoot->val) {
            cout<<checkSubtree(root,subRoot)<<" "<<root->val<<" "<<subRoot->val<<endl;
            if(checkSubtree(root,subRoot)) return checkSubtree(root,subRoot);
        }
        
        bool l = isSubtree(root->left,subRoot);
        bool r = isSubtree(root->right,subRoot);
        
        if(l || r) return true;
        else return false;
    }
};