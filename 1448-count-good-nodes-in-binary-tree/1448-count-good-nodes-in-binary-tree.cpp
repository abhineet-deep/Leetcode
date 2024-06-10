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

    void findGoodNodes(TreeNode* root,int maxi, int& count) {
        if(!root) return;
        if(root->val >= maxi) {
            maxi = root->val;
            count++;
        }

        findGoodNodes(root->left,maxi,count);
        findGoodNodes(root->right,maxi,count);
    }

    int goodNodes(TreeNode* root) {
        int maxi = INT_MIN,count = 0;
        findGoodNodes(root,maxi,count);
        return count;

    }
};