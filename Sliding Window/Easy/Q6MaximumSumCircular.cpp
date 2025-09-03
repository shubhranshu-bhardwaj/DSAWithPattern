/*
Q6. Maximum Sum of Circular Subarray of Size K
Given an array a of length n and integer k (assume 1 <= k <= n),
find the maximum sum of any contiguous subarray of length k in the circular array (wraps around).
a = [5, -3, 5], k = 2
start 0 ⇒ 5 + (-3) = 2
start 1 ⇒ -3 + 5 = 2
start 2 ⇒ 5 + 5 = 10 → best = 10
Output: 10
*/

#include <bits/stdc++.h>
using namespace std;

// Brute -> For each start i from 0..n-1, sum the next k elements using modulo wrap.
long long brute(vector<int> &arr, int k)
{
    int n = arr.size();
    long long maxSum = LLONG_MIN;
    // outer loop
    for (int i = 0; i < n; i++)
    {
        long long sum = 0;
        // inner loop for calculating sum
        for (int j = 0; j < k; j++)
        {
            sum += arr[(i + j) % n];
        }
        // comapre sum
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}
// TC -> O(n*k)

// Better -> Duplicate the array into length 2n and run a standard fixed-size
// sliding window across the duplicated array, but only consider windows whose start index < n
long long better(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> ans(2 * n);
    for (int i = 0; i < 2 * n; i++)
    {
        ans[i] = arr[i % n];
    }
    long long sum = 0, maxSum = 0;
    int left = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        sum += ans[i];
        // if not in window
        if (i - left + 1 > k)
        {
            sum -= ans[left];
            left++;
        }
        // if in window
        if (i - left + 1 == k && left < n)
        {
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}
// TC -> O(n)

// Optimal -> Do sliding window directly over indexes with modulo arithmetic (no extra array).
long long optimal(vector<int> &arr, int k)
{
    int n = arr.size();
    long long sum = 0, maxSum = 0;
    // calculate for first window
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    maxSum = sum;
    // compare from other
    for (int i = 1; i < n; i++)
    {
        sum = sum - arr[i - 1] + arr[(i + k - 1) % n];
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}
// TC -> O(n)

// main function
int main()
{
    vector<int> arr = {5, -3, 5};
    int k = 2;
    long long res1 = brute(arr, k);
    long long res2 = better(arr, k);
    long long res3 = optimal(arr, k);

    cout << "Count using brute: " << res1 << endl;
    cout << "Count using better: " << res2 << endl;
    cout << "Count using optimal: " << res3 << endl;
    return 0;
}