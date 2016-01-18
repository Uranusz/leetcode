/*
 * =====================================================================================
 *
 *       Filename:  46_permutations.cc
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  01/02/2016 09:42:36 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jiahao Zhu
 *   Organization:
 *
 * =====================================================================================
 */
#include <iostream>
#include <vector>

using namespace std;
/*
 * =====================================================================================
 *        Class:  Solution
 *  Description:
 * =====================================================================================
 */
class Solution {
    public:
        vector<vector<int> > permute(vector<int>& nums) {
            vector<vector<int> > res;
            vector<bool> used(nums.size(), false);
            vector<int> v;
            _permute(nums, used, res, v);
            return res;
        }

    private:
        void _permute(const vector<int>& nums, vector<bool>& used,
                      vector<vector<int> >& res, vector<int>& v) {
            if (v.size() == nums.size()) {
                res.push_back(v);
                return;
            }

            for (unsigned int i = 0; i < nums.size(); ++i)
                if (!used[i]) {
                    int candidate = nums[i];
                    used[i] = true;
                    v.push_back(candidate);
                    _permute(nums, used, res, v);
                    used[i] = false;
                    v.pop_back();
                }
        }

}; /* -----  end of class Solution  ----- */



/*
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:
 * =====================================================================================
 */
int
main(int argc, char* argv[]) {
    vector<int> v;

    for (int i = 0; i < 12; ++i)
        v.push_back(i);

    Solution s;
    vector<vector<int> > res = s.permute(v);

    for (vector<vector<int> >::const_iterator outer = res.cbegin();
            outer != res.cend(); ++outer) {
        for (vector<int>::const_iterator inner = (*outer).cbegin();
                inner != (*outer).cend(); ++inner)
            cout << *inner << " ";

        cout << endl;
    }

    return 0;
}				/* ----------  end of function main  ---------- */

