/*
Q1. Maximum Sum Subarray of Size K
Given an array of integers and an integer k, find the maximum sum of any contiguous subarray of size k.
arr=[2,1,5,1,3,2], k=3
Subarray [2,1,5]=8 → max=8
Subarray [1,5,1]=7 → max=8
Subarray [5,1,3]=9 → max=9
Subarray [1,3,2]=6 → max=9
Output: 9
*/

#include <bits/stdc++.h>
using namespace std;

// Brute -> Run loop till (n-k) and calculate sum for each subarry of size k
int maxSumBrute(vector<int> &arr, int k)
{
    int n = arr.size();   // size of arr
    int maxSum = INT_MIN; // as of now maxSum is 0

    // outer loop till i <= n-k
    for (int i = 0; i <= n - k; i++)
    {
        int sum = 0; // sum for each subarray
        // inner loop from i till size of k
        for (int j = i; j < i + k; j++)
        {
            sum += arr[j];
        }
        // update the maxSum
        maxSum = max(maxSum, sum);
    }

    return maxSum;
}

// TC -> O(n*k)

// Better -> For each new start, reuse the previous sum instead of recalculating fully
int maxSumBetter(vector<int> &arr, int k)
{
    int n = arr.size();               // size of arr
    vector<int> windowSum(n - k + 1); // vector of size k for keeping previous sum
    // calculate first subarray sum of size k
    for (int i = 0; i < k; i++)
    {
        windowSum[0] += arr[i];
    }
    int maxSum = windowSum[0]; // as of now max sum
    // run a loop from 1 to n-k for the next subarry
    for (int i = 1; i <= n - k; i++)
    {
        // update the window sum
        windowSum[i] = windowSum[i - 1] - arr[i - 1] + arr[i + k - 1];
        // compare the sum
        maxSum = max(windowSum[i], maxSum);
    }
    return maxSum;
}
// TC -> O(n*k)

// Optimal -> Using sliding window
int maxSumOptimal(vector<int> &arr, int k)
{
    int n = arr.size(); // size of array
    int windowSum = 0;
    // first calculate the firts window sum (1st subarray of size k)
    for (int i = 0; i < k; i++)
    {
        windowSum += arr[i];
    }
    int maxSum = windowSum; // as of now
    // subtract from left and compare sum
    for (int i = k; i < n; i++)
    {
        // subtract from left
        windowSum += arr[i] - arr[i - k];
        // compare sum
        maxSum = max(windowSum, maxSum);
    }
    return maxSum;
}
// TC -> O(n)

// main function
int main()
{
    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 3;

    // Call the function and print the result
    int res1 = maxSumBrute(arr, k);
    cout << "Max sum using brute: " << res1 << endl;
    int res2 = maxSumBetter(arr, k);
    cout << "Max sum using better: " << res2 << endl;
    int res3 = maxSumOptimal(arr, k);
    cout << "Max sum using optimal: " << res3 << endl;

    return 0;
}