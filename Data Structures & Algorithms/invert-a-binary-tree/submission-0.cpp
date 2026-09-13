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
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr)return nullptr;
        stack<TreeNode* >st;
        st.push(root);
        while(!st.empty())
        {
            auto it = st.top();
            st.pop();
            TreeNode* temp=it->right;
            it->right= it->left;
            it->left= temp;
            if(it->right)st.push(it->right);
            if(it->left)st.push(it->left);
        }
        return root;
    }
};
