// =====================================================================================
//
//       Filename:  324_wiggle_sort.cc
//
//    Description:
//
//        Version:  1.0
//        Created:  01/02/2016 12:34:21 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Jiahao Zhu (JZ), uranus.superz@outlook.com
//   Organization:
//
// =====================================================================================

#include <vector>
#include <iostream>
#include <utility>
#include <stack>
#include <algorithm>

using namespace std;

// =====================================================================================
//        Class:  Solution
//  Description:
// =====================================================================================
class Solution {

#define A(i) (nums[(2*i + 1) % (nums.size() | 1)])

public:
    void wiggleSort(vector<int>& nums) {

        int n = nums.size();

        // find the median
        auto midptr = nums.begin() + n / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;

        // three-way-partition in O(n) time with O(1) space.
        int i = 0, j = 0, k = n - 1;

        while(j <= k) {
            if(A(j) > mid)
                swap(A(i++), A(j++));
            else if(A(j) < mid)
                swap(A(j), A(k--));
            else
                j++;
        }
    }

private:


    //-----------------------------------------------------------------------------
    //  quick-sort way is not fast enough to find the median...
    //-----------------------------------------------------------------------------
#if 0
    // 1. recursive version
    void findMedian(vector<int>& nums, int p, int q) {
        int i = p, j = p, mid = nums.size() / 2;

        while(j < q) {
            if(A(j) >= A(q))
                swap(A(j++), A(i++));
            else
                j++;
        }

        swap(A(i), A(q));

        if(i == mid)
            return;
        else if(i < mid)
            findMedian(nums, i + 1, q);
        else
            findMedian(nums, p, i - 1);
    }

    // 2. non-recursive version
    void partition(vector<int>& nums) {
        int mid = nums.size() / 2;
        stack<int> s;
        s.push(0);
        s.push(nums.size() - 1);

        while(!s.empty()) {
            int q = s.top();
            s.pop();
            int p = s.top();
            s.pop();
            int i = p, j = p;

            while(j < q) {
                if(A(j) > A(q))
                    swap(A(j++), A(i++));
                else
                    j++;
            }

            swap(A(i), A(q));

            if(i == mid)
                return;
            else if(i < mid) {
                s.push(i+1);
                s.push(q);
            } else {
                s.push(p);
                s.push(i-1);
            }
        }
    }

#endif

#undef A
#define A(i) (nums[i])
    // 3. quick sort
    void quickSort(vector<int>& nums) {
        stack<int> s;
        s.push(0);
        s.push(nums.size() - 1);

        while(!s.empty()) {
            int q = s.top();
            s.pop();
            int p = s.top();
            s.pop();
            int i = p, j = p;

            while(j < q) {
                if(A(j) < A(q))
                    swap(A(j++), A(i++));
                else
                    j++;
            }

            swap(A(i), A(q));

            if(i < q) {
                s.push(i+1);
                s.push(q);
            }

            if (i > p) {
                s.push(p);
                s.push(i-1);
            }
        }
    }


}; // -----  end of class Solution  -----

// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:
// =====================================================================================
int
main ( int argc, char *argv[] ) {
    vector<int> v;
    v.push_back(1);
    v.push_back(5);
    v.push_back(1);
    v.push_back(1);
    v.push_back(6);
    v.push_back(4);

    Solution s;

    s.wiggleSort(v);

    for(vector<int>::iterator it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";

    cout << endl;
    return 0;
}				// ----------  end of function main  ----------
