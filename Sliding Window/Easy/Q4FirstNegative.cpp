/*
Q4. First Negative Number in Every Window of Size K
Given an array of integers, find the first negative number in the every window of size k
arr=[12,-1,-7,8,-15,30,16,28], k=3
[12,-1,-7] → -1
[-1,-7,8] → -1
[-7,8,-15] → -7
…
Output: [-1, -1, -7, -15, -15, 0]
*/

#include <bits/stdc++.h>
using namespace std;

// Brute -> for each i start finding first -ve in each window
vector<int> findNeg(vector<int> &arr, int k)
{
    int n = arr.size(); // size of array
    vector<int> ans;    // for storing first negative of each window
    // run loop from i-n-k
    for (int i = 0; i <= n - k; i++)
    {
        int find = 0;
        // run loop from i to i+k
        for (int j = i; j < i + k; j++)
        {
            if (arr[i] < 0)
            {
                find = arr[i];
                break;
            }
        }
        ans.push_back(find);
    }
    return ans;
}
// TC -> O(n*k)
// Better -> Use deque but only push while iterating each new window
vector<int> better(vector<int> &arr, int k)
{
    int n = arr.size(); // size of array
    deque<int> dq;
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        if (!dq.empty() && dq.front() <= i - k)
        {
            dq.pop_front();
        }

        // add element if it's negative
        if (arr[i] < 0)
        {
            dq.push_back(i);
        }
        // store ans only after window filled
        if (i >= k - 1)
        {
            ans.push_back(dq.empty() ? 0 : arr[dq.front()]);
        }
    }
    return ans;
}

// Optimal ->
vector<int> optimal(vector<int> &arr, int k)
{
    int n = arr.size();
    deque<int> dq;
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            dq.push_back(i);
        }
        if (i >= k - 1)
        {
            while (!dq.empty() && dq.front() <= i - k)
            {
                dq.pop_front();
            }
        }
        ans.push_back(dq.empty() ? 0 : arr[dq.front()]);
    }

    return ans;
}