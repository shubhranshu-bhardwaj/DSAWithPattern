/*
Q2. Remove Duplicates
Given a sorted array nums, remove the duplicates in-place such that each element appears
only once and returns the new length.
Example 1:
Input: nums = [1,1,2]
Output: 2, nums = [1,2]
*/

#include <bits/stdc++.h>
using namespace std;

// Better -> Create a new array of unique elements.
int better(vector<int> &a)
{
    int n = a.size();
    vector<int> temp;
    for (int i : a)
    {
        if (temp.empty() || temp.back() != i)
        {
            temp.push_back(i);
        }
    }
    return temp.size();
}
// TC -> O(N), SC -> O(N) for new array

// Optimal -> Two pointers: i → last unique index, j → scans array
int optimal(vector<int> &a)
{
    int n = a.size(), i = 0;
    for (int j = 1; j < n; j++)
    {
        if (a[j] != a[i])
        {
            a[++i] = a[j];
        }
    }
    return i + 1;
}
// TC -> O(N), SC -> O(1)

// main function
int main()
{
    vector<int> a = {1, 1, 2};
    cout << better(a) << endl;
    cout << optimal(a) << endl;
    return 0;
}