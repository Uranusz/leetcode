// =====================================================================================
//
//       Filename:  98_validate_bst.cc
//
//    Description:
//
//        Version:  1.0
//        Created:  02/09/2016 10:27:17 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Jiahao Zhu (JZ), uranus.superz@outlook.com
//   Organization:
//
// =====================================================================================

#include <vector>
#include <iostream>

/*
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// =====================================================================================
//        Class:  Solution
//  Description:
// =====================================================================================
class Solution {
    public:
        bool isValidBST(TreeNode* root) {
            if (root == nullptr)
                return true;

            if (root->left == nullptr)
                ;
            else if (root->right == nullptr)
                if (root->left != nullptr && root->val < root->left->val)
                    return false;

            if (root->right != nullptr && root->val > root->left->val)
                return false;

            return isValidBST(root->left) && isValidBST(root->right);
        }
}; // -----  end of class Solution  -----

