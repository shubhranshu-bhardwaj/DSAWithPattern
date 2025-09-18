/*
Q4. Two Sum II (Sorted Array)
Given sorted nums, return 1-based indices of two numbers adding to target.
Example 1:
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
*/

#include <bits/stdc++.h>
using namespace std;

// Brute -> Check all pairs nested loop.
vector<int> brute(vector<int> &nums, int target)
{
    int n = nums.size();
    for (int i = 0; i < n - 1; i++)
    {
        int sum = 0;
        for (int j = i + 1; j < n; j++)
        {
            sum = nums[i] + nums[j];
            if (sum == target)
            {
                return {i + 1, j + 1};
            }
        }
    }
    return {-1, -1};
}
// TC -> O(N^2), SC -> O(1)

// Optimal -> Two pointers from both ends.
vector<int> optimal(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;
    while (left < right)
    {
        int sum = nums[left] + nums[right];
        if (sum == target)
        {
            return {left + 1, right + 1};
        }
        else if (sum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return {-1, -1};
}
// TC -> O(N), SC -> O(1)

// main function
int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> res1 = brute(nums, target);
    for (int i : res1)
    {
        cout << i << " ";
    }
    cout << endl;
    vector<int> res2 = optimal(nums, target);
    for (int i : res2)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}