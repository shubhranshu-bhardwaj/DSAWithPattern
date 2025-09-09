/*
Q6. Count Number of Nice Subarrays
Given an array of integers arr and an integer k.
A continuous subarray is called nice if there are k odd numbers on it.
Return the number of nice sub-arrays.
arr = [1,1,2,1,1], k = 3
Output: 2
The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
*/

#include <bits/stdc++.h>
using namespace std;

// Brute -> Count odds in each subarray, using nested loop
int brute(vector<int> &arr, int k)
{
    int n = arr.size(), count = 0;
    for (int i = 0; i < n; i++)
    {
        int odd = 0;
        for (int j = i; j < n; j++)
        {
            odd += (arr[j] & 1);
            if (odd == k)
            {
                count++;
            }
        }
    }
    return count;
}
// TC -> O(n²)

// Better -> Prefix Sum + HashMap (frequency map) technique to, convert the problem into a sum of
// prefix counts, and count subarrays with a specific number of odd numbers.
int better(vector<int> &arr, int k)
{
    unordered_map<int, int> freq;
    freq[0] = 1;
    int count = 0;
    int sum = 0;
    for (int x : arr)
    {
        sum += (x & 1);
        if (freq.count(sum - k))
        {
            count += freq[sum - k];
        }
        freq[sum]++;
    }
    return count;
}
// TC -> O(n)

// Helper function to count subarrays with at most k odd numbers
int helper(vector<int> &arr, int k)
{
    int n = arr.size(), count = 0, odd = 0, left = 0;
    for (int i = 0; i < n; i++)
    {
        odd += (arr[i] & 1);
        // shrink if > k
        while (odd > k)
        {
            odd -= (arr[left] & 1);
            left++;
        }
        count += i - left + 1;
    }
    return count;
}

// Optimal -> Using sliding window, count odd if > k shrink from left
int optimal(vector<int> &arr, int k)
{
    return helper(arr, k) - helper(arr, k - 1);
}
// TC -> O(n)

// main function
int main()
{
    vector<int> arr = {1, 1, 2, 1, 1};
    int k = 3;

    cout << "Brute force result: " << brute(arr, k) << endl;
    cout << "Better result: " << better(arr, k) << endl;
    cout << "Optimal result: " << optimal(arr, k) << endl;

    return 0;
}