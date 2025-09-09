/*
Q5. Count Subarrays With Product < K (positive integers)
Given nums of positive ints and k > 1, count contiguous subarrays whose product < k.
a=[10,5,2,6], k=100
l=0: prod=10✔, 50✔, 100✖ → +2
l=1: 5✔, 10✔, 60✔ → +3
l=2: 2✔, 12✔ → +2
l=3: 6✔ → +1
✅ Output: 8
*/

#include <bits/stdc++.h>
using namespace std;

// Brute -> Run a nested loop, each l, expand r and multiply; stop when product ≥ k.
long long brute(vector<int> &arr, int K)
{
    int n = arr.size();
    long long count = 0;
    for (int l = 0; l < n; l++)
    {
        long long prod = 1;
        for (int r = l; r < n; r++)
        {
            prod *= arr[r];
            // if prod < k, count++
            if (prod < K)
            {
                count++;
            }
            else
            {
                break;
            }
        }
    }
    return count;
}
// TC -> O(n²)

// Optimal -> Using Sliding window, maintain product when > k shrink from left
long long optimal(vector<int> &arr, int K)
{
    int n = arr.size(), left = 0;
    long long prod = 1, count = 0;
    for (int i = 0; i < n; i++)
    {
        prod *= arr[i];
        // shrink from left if >k
        while (prod >= K)
        {
            prod /= arr[left];
            left++;
        }
        count += i - left + 1;
    }
    return count;
}
// TC -> O(n)

// main function
int main()
{
    vector<int> arr = {10, 5, 2, 6};
    int K = 100;

    cout << "Brute Force Output: " << brute(arr, K) << endl;
    cout << "Optimal Output: " << optimal(arr, K) << endl;

    return 0;
}