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
    void countPath(TreeNode* root, int targetSum, int& count, long sum) {
        if(!root) return;

        sum+=root->val;
        if(sum == targetSum) count++;

        countPath(root->left,targetSum,count,sum);
        countPath(root->right,targetSum,count,sum);
    }

    void traversePath(TreeNode* root,int targetSum,int& count) {
        if(!root) return;
        long sum = 0;
        countPath(root,targetSum,count,sum);

        traversePath(root->left,targetSum,count);
        traversePath(root->right,targetSum,count);
    } 

    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        traversePath(root,targetSum,count);
        return count;
    }
};