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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr)return 0;

        int h1= height(root->left);
        int h2= height(root->right);
        int dia=h1+h2;
        int dia2=diameterOfBinaryTree(root->left);
        int dia3=diameterOfBinaryTree(root->right);
        return max(dia,max(dia3,dia2));

    }
    int height(TreeNode* root)
    {
        if(root==nullptr)return 0;
        return 1+max(height(root->left),height(root->right));

    }
};
