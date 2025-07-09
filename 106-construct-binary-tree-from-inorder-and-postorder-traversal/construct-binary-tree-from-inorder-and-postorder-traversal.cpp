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
    TreeNode* constructTree(vector<int>& postorder, int pstart, int pend,
                            vector<int>& inorder, int istart, int iend,
                            map<int, int>& mp) {
        if (istart > iend || pstart < pend) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(postorder[pstart]);
        int ele = mp[root->val];
        int nele = iend - ele;  // Number of nodes in right subtree

        // Build right subtree first
        root->right = constructTree(postorder, pstart - 1, pstart - nele,
                                    inorder, ele + 1, iend, mp);

        // Then build left subtree
        root->left = constructTree(postorder, pstart - nele - 1, pend,
                                   inorder, istart, ele - 1, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int istart = 0, iend = inorder.size() - 1;
        int pstart = postorder.size() - 1, pend = 0;

        map<int, int> mp;
        for (int i = 0; i <= iend; i++) {
            mp[inorder[i]] = i;
        }

        return constructTree(postorder, pstart, pend, inorder, istart, iend, mp);
    }
};