/*
Q3. Sort Colors (Dutch National Flag) (LeetCode 75)
Given nums with values 0,1,2, sort them in-place in one pass.
Example:
Input: nums = [2,0,2,1,1,0]
Output: nums = [0,0,1,1,2,2]
*/

#include <bits/stdc++.h>
using namespace std;

// Brute -> Sort array using sort
void brute(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
}
// TC -> O(NlogN), SC -> O(1)

// Better -> Count 0, 1, 2 and then overwrite
void better(vector<int> &nums)
{
    int count0 = 0, count1 = 0, count2 = 0;
    for (int i : nums)
    {
        if (i == 0)
        {
            count0++;
        }
        else if (i == 1)
        {
            count1++;
        }
        else
        {
            count2++;
        }
    }
    int i = 0;
    while (count0--)
    {
        nums[i++] = 0;
    }
    while (count1--)
    {
        nums[i++] = 1;
    }
    while (count2--)
    {
        nums[i++] = 2;
    }
}
// TC -> O(N), SC -> O(1)

// Optimal -> Three-pointer single pass (low, mid, high) swapping.
void optimal(vector<int> &nums)
{
    int low = 0, mid = 0, high = nums.size() - 1;
    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[mid], nums[low]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

// TC -> O(N), SC -> O(1)

// main function
int main()
{
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    brute(nums);
    for (int i : nums)
    {
        cout << i << " ";
    }
    cout << endl;
    nums = {2, 0, 2, 1, 1, 0};
    better(nums);
    for (int i : nums)
    {
        cout << i << " ";
    }
    cout << endl;
    nums = {2, 0, 2, 1, 1, 0};
    optimal(nums);
    for (int i : nums)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}