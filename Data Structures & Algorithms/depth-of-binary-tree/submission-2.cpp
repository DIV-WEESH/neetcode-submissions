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
    int maxDepth(TreeNode* root) {
        if(root==nullptr)return 0;
        stack<pair<TreeNode*,int>> st;
        st.push({root,1});
        int height=0;
        while(!st.empty())
        {
            auto [node, ht] = st.top();
            st.pop();
            height=max(ht,height);
            if(node->left!=nullptr)st.push({node->left,ht+1});
            if(node->right!=nullptr)st.push({node->right,ht+1});
           
        }
        return height;
    }
};
