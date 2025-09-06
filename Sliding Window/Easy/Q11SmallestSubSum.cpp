/*
Q11. Smallest Subarray With Sum ≥ S
Given an array of positive integers and a number S, find the length of the smallest contiguous subarray
whose sum ≥ S. If none exists, return 0.
arr=[2,1,5,2,3,2], S=7
i=0: [2]=2 <7, [2,1]=3, [2,1,5]=8 ≥7 → len=3
i=1: [1]=1, [1,5]=6, [1,5,2]=8 ≥7 → len=3
i=2: [5]=5, [5,2]=7 ≥7 → len=2 (smaller)
i=3: [2]=2, [2,3]=5, [2,3,2]=7 ≥7 → len=3
i=4: [3]=3, [3,2]=5 <7
i=5: [2]=2 <7
Output = 2
*/

#include <bits/stdc++.h>
using namespace std;

// Brute -> Check all subarrays, track minimal length with sum ≥ S.
int brute(vector<int> &arr, int S)
{
    int n = arr.size(), minLen = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum >= S)
            {
                minLen = min(minLen, j - i + 1);
                break;
            }
        }
    }
    return (minLen == INT_MAX ? 0 : minLen);
}
// TC -> O(n^2)

// Better -> Precompute prefix sums
int better(vector<int> &arr, int S)
{
    int n = arr.size();
    vector<int> prefixSum(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        prefixSum[i + 1] = prefixSum[i] + arr[i];
    }
    int minLen = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = prefixSum[j + 1] - prefixSum[i];
            if (sum >= S)
            {
                minLen = min(minLen, j - i + 1);
                break;
            }
        }
    }
    return (minLen == INT_MAX ? 0 : minLen);
}
// TC -> O(n^2)

// Optimal -> Expand window while sum < S, shrink from left once ≥ S.
int optimal(vector<int> &arr, int S)
{
    int n = arr.size(), minLen = INT_MAX, sum = 0, left = 0;
    for (int right = 0; right < n; right++)
    {
        sum += arr[right];
        while (sum >= S)
        {
            minLen = min(minLen, right - left + 1);
            sum -= arr[left++];
        }
    }
    return (minLen == INT_MAX ? 0 : minLen);
}
// TC -> O(n)

// main function
int main()
{
    vector<int> arr = {2, 1, 5, 2, 3, 2};
    int S = 7;
    int res1 = brute(arr, S);
    int res2 = better(arr, S);
    int res3 = optimal(arr, S);

    cout << "Minimum Length with brute: " << res1 << endl;
    cout << "Minimum Length with better: " << res2 << endl;
    cout << "Minimum Length with optimal: " << res3 << endl;
    return 0;
}