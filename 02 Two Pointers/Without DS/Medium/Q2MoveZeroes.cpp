/*
Q2. Move Zeroes (LeetCode 283)
Move all 0s to the end of array while maintaining relative order of non-zero elements. Do it in-place.
Example:
Input: nums = [0,1,0,3,12]
Output: nums = [1,3,12,0,0]
*/

#include <bits/stdc++.h>
using namespace std;

// Better -> Build new array of non-zeros then append zeros
void better(vector<int> &nums)
{
    int n = nums.size();
    vector<int> nonZero;
    for (int i : nums)
    {
        if (i != 0)
        {
            nonZero.push_back(i);
        }
    }
    for (int i = 0; i < nonZero.size(); i++)
    {
        nums[i] = nonZero[i];
    }
    for (int i = nonZero.size(); i < n; i++)
    {
        nums[i] = 0;
    }
}
// TC -> O(N), SC -> O(N)

// Optimal -> Two-pointer overwrite or swap in-place
void optimal(vector<int> &nums)
{
    int j = 0, n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 0)
        {
            nums[j++] = nums[i];
        }
    }
    while (j < n)
    {
        nums[j++] = 0;
    }
}
// TC -> O(N), SC -> O(1)

// main function
int main()
{
    vector<int> nums = {0, 1, 0, 3, 12};
    better(nums);
    for (int i : nums)
    {
        cout << i << " ";
    }
    cout << endl;
    nums = {0, 1, 0, 3, 12};
    optimal(nums);
    for (int i : nums)
    {
        cout << i << " ";
    }
    return 0;
}