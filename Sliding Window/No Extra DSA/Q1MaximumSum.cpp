/*
Q1. Maximum Sum Subarray of Size K (LC 643)
Given an array of integers and an integer k, find the maximum sum of a contiguous subarray of size k.
Example 1:
Input: arr = [2,1,5,1,3,2], k = 3
Output: 9
*/

#include <bits/stdc++.h>
using namespace std;

// Brute -> Check all subarrays of size k and find the maximum sum
int brute(vector<int> &arr, int k)
{
    int n = arr.size(), maxSum = 0;
    for (int i = 0; i <= n-k; i++)
    {
        int sum = 0;
        for (int j = i; j < i + k; j++)
        {
            sum += arr[j];
        }
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}
// TC -> O(N * K), SC -> O(1)

// Optimal -> Sliding Window, add next element and remove previous element
int optimal(vector<int> &arr, int k)
{
    int n = arr.size(), maxSum = 0, sum = 0;
    // Calculate sum of first k elements
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    maxSum = sum;
    // Slide the window from k to n
    for (int i = k; i < n; i++)
    {
        sum += arr[i] - arr[i - k];
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}
// TC -> O(N), SC -> O(1)

// main function
int main()
{
    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 3;
    cout << "Brute Force: " << brute(arr, k) << endl;
    cout << "Optimal: " << optimal(arr, k) << endl;
    return 0;
}