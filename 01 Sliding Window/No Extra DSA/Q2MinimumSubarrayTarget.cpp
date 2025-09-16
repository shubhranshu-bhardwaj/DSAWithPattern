/*
Q2. Smallest Subarray with Sum ≥ Target (LC 209)
// Given an array of positive integers nums and a positive integer target,
return the minimal length of a contiguous subarray of which the sum is greater than or equal to target.
If there is no such subarray, return 0 instead.
Example 1:
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
*/

#include <bits/stdc++.h>
using namespace std;

// Brute -> Check all subarrays and find the minimum length with sum >= target
int brute(vector<int> &arr, int target)
{
    int n = arr.size(), minLen = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum >= target)
            {
                minLen = min(minLen, j - i + 1);
                break;
            }
        }
    }
    return minLen == INT_MAX ? 0 : minLen;
}
// TC -> O(N^2), SC -> O(1)

// Optimal -> Sliding Window, expand the window by adding next element until sum >= target,
// then contract the window by removing previous element until sum < target
int optimal(vector<int> &arr, int target)
{
    int n = arr.size(), minLen = INT_MAX, sum = 0, left = 0;
    for (int right = 0; right < n; right++)
    {
        // Expand the window
        sum += arr[right];
        // Contract the window
        while (sum >= target)
        {
            minLen = min(minLen, right - left + 1);
            sum -= arr[left];
            left++;
        }
    }
    return minLen == INT_MAX ? 0 : minLen;
}
// TC -> O(N), SC -> O(1)

// main function
int main()
{
    vector<int> arr = {2, 3, 1, 2, 4, 3};
    int target = 7;
    cout << "Brute Force: " << brute(arr, target) << endl;
    cout << "Optimal: " << optimal(arr, target) << endl;
    return 0;
}