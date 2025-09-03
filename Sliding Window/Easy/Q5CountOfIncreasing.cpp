/*
Q5. Count of Increasing Window Sums
Given an array of integers, count the increasing window sum of size k
arr=[1,2,3,4,5], k=2
[1,2]=3 vs [2,3]=5 → inc
[2,3]=5 vs [3,4]=7 → inc
[3,4]=7 vs [4,5]=9 → inc
Output: 3
*/

#include <bits/stdc++.h>
using namespace std;

// Brute -> for each i calculate previous and current sum using two inner loop
int countSum(vector<int> &arr, int k)
{
    int n = arr.size(), count = 0;
    // inner loop for each window
    for (int i = 1; i <= n - k; i++)
    {
        int prev = 0, curr = 0;
        // calculate prev sum
        for (int j = i - 1; j < i - 1 + k; j++)
        {
            prev += arr[j];
        }
        // calculate curr sum
        for (int m = i; m < i + k; m++)
        {
            curr += arr[m];
        }

        // compare
        if (curr > prev)
        {
            count++;
        }
    }
    return count;
}
// TC -> O(n*k)

// Better -> store sum of all window then compare
int countBetter(vector<int> &arr, int k)
{
    int n = arr.size(), count = 0;
    vector<int> ans; // for storing sum of each window
    for (int i = 0; i <= n - k; i++)
    {
        int sum = 0;
        for (int j = i; j < i + k; j++)
        {
            sum += arr[j];
        }
        ans.push_back(sum);
    }

    // compare sum
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i + 1] > ans[i])
        {
            count++;
        }
    }
    return count;
}
// TC -> O(n*k)

// Optimal -> Calculate sum for first window then start comparing
int countOptimal(vector<int> &arr, int k)
{
    int n = arr.size(), sum = 0, prev = 0, count = 0;
    // calculate sum of first window
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    prev = sum;

    // compare
    for (int i = k; i < n; i++)
    {
        sum += arr[i] - arr[i - k];
        if (sum > prev)
        {
            count++;
        }
        prev = sum;
    }
    return count;
}
// TC -> O(n)

// main function
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 2;
    int res1 = countSum(arr, k);
    int res2 = countBetter(arr, k);
    int res3 = countOptimal(arr, k);

    cout << "Count using brute: " << res1 << endl;
    cout << "Count using better: " << res2 << endl;
    cout << "Count using optimal: " << res3 << endl;
    return 0;
}