/*
 * =====================================================================================
 *
 *       Filename:  queue_using_stacks.cc
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  07/07/2015 22:15:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */

#include <stack>
#include <iostream>

using namespace std;

class Queue
{
    public:
        //Push element x to the back of queue.
        void push(int x)
        {
            if (_b.size())
                swap(_b, _a);

            _a.push(x);
        }

        // Removes the element from in front of queue.
        void pop(void)
        {
            if (!empty() && !_b.size())
                swap(_a, _b);

            _b.pop();
        }

        // Get the front element.
        int peek(void)
        {
            if (!empty() && !_b.size())
                swap(_a, _b);

            return _b.top();
        }

        // Return whether the queue is empty.
        bool empty(void)
        {
            return (!_a.size() && !_b.size());
        }

    private:
        void swap(stack<int>& s1, stack<int>& s2)
        {
            while (s1.size())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

    private:
        stack<int> _a;
        stack<int> _b;
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
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    for (int i = 0; i < 5; ++i)
    {
        cout << q.peek() << endl;
        q.pop();
    }

    return 0;
}				/* ----------  end of function main  ---------- */
