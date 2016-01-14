/*
 * =====================================================================================
 *
 *       Filename:  array_to_BST.cc
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  07/07/2015 23:12:46
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
using namespace std;

/*
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
    public:
        TreeNode* sortedArrayToBST(vector<int>& nums)
        {
            if (nums.size() == 0)
                return NULL;

            TreeNode* t = new TreeNode(-1);
            makeTreeNode(t, nums, 0, nums.size() - 1);
            return t;
        }

    private:
        void makeTreeNode(TreeNode* node, vector<int>& nums, int begin, int end)
        {
            if (begin == end)
            {
                node->val = nums[begin];
                return;
            }

            int pivot = (begin + end) / 2;
            node->val = nums[pivot];

            if (pivot != begin)
            {
                node->left = new TreeNode(-1);
                makeTreeNode(node->left, nums, begin, pivot - 1);
            }

            if (pivot != end)
            {
                node->right = new TreeNode(-1);
                makeTreeNode(node->right, nums, pivot + 1, end);
            }
        }

    public:
        void deleteTree(TreeNode* t)
        {
            if (!t)
                return;

            if (t->left)
                deleteTree(t->left);

            if (t->right)
                deleteTree(t->right);

            cout << "val to be deleted: " << t->val << endl;
            delete t;
        }
};


/*
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:
 * =====================================================================================
 */
int
main(int argc, char* argv[])
{
    Solution s;
    vector<int> v;
    //v.push_back(1);
    //v.push_back(2);
    //v.push_back(3);
    //v.push_back(4);
    //v.push_back(5);
    TreeNode* tree = s.sortedArrayToBST(v);
    s.deleteTree(tree);
    return 0;
}				/* ----------  end of function main  ---------- */
