/*
Q7. Number of Subarrays of Size K with Average ≥ Threshold
Given arr, k, and integer threshold, return number of contiguous subarrays of size k
whose average is at least threshold. (Equivalent: sum ≥ threshold * k.)
arr=[2,2,2,2,2], k=3, threshold=2
windows: sums = 6,6,6 → all ≥ 6 → count = 3
*/

#include <bits/stdc++.h>
using namespace std;

// Brute -> For each start compute sum of the next k elements.
int brute(vector<int> &arr, int k, int threshold)
{
    int n = arr.size(), count = 0;
    // run outer loop for each window of size k
    for (int i = 0; i <= n - k; i++)
    {
        int sum = 0;
        // run inner loop to calculate sum
        for (int j = i; j < i + k; j++)
        {
            sum += arr[j];
        }
        // compare
        if (sum >= threshold * k)
        {
            count++;
        }
    }
    return count;
}
// TC -> O(n*k)

// Better / Optimal -> Using sliding window calculate the sum for 1st window then compare for other
int optimal(vector<int> &arr, int k, int threshold)
{
    int n = arr.size(), count = 0, sum = 0;
    // calculate for 1st window
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    // check
    if (sum >= threshold * k)
    {
        count++;
    }
    // calculate for other window / subarray
    for (int i = k; i < n; i++)
    {
        sum += arr[i] - arr[i - k];
        // check
        if (sum >= threshold * k)
        {
            count++;
        }
    }
    return count;
}
// TC -> O(n)

// main function
int main()
{
    vector<int> arr = {2, 2, 2, 2, 2};
    int k = 3, threshold = 2;
    int res1 = brute(arr, k, threshold);
    int res2 = optimal(arr, k, threshold);
    cout << "Count with brute: " << res1 << endl;
    cout << "Count with optimal: " << res2;
    return 0;
}