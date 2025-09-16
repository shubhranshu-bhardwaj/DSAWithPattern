/*
Q2. Average of subarray of size k
Given an array of integer and an integer k, print the average of all the subarray of size k.
arr=[1,3,2,6,-1,4,1,8,2], k=5

[1,3,2,6,-1]=11 → 2.2
[3,2,6,-1,4]=14 → 2.8
[2,6,-1,4,1]=12 → 2.4
[6,-1,4,1,8]=18 → 3.6
[-1,4,1,8,2]=14 → 2.8
Output: [2.2, 2.8, 2.4, 3.6, 2.8]
*/

#include <bits/stdc++.h>
using namespace std;

// Brute -> Start calculating sum and average for each subarray
vector<double> avg(vector<int> &arr, int k)
{
    int n = arr.size(); // size of arr
    vector<double> ans; // for storing averages
    // run outer loop from 0-n-k
    for (int i = 0; i <= n - k; i++)
    {
        int sum = 0; // intialize sum for each start of i
        // run inner loop from i-i+k
        for (int j = i; j < i + k; j++)
        {
            sum += arr[j];
        }
        // push the average in ans
        ans.push_back((double)sum / k);
    }
    return ans;
}
// TC -> O(n*k)

// Better & Optimal -> Using sliding window, calculate sum of 1st subarry then start subtracting from left
vector<double> avgOptimal(vector<int> &arr, int k)
{
    int n = arr.size(); // size of array
    vector<double> ans; // for storing the average
    int sum = 0;

    // calculate the average of 1st subarray
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    ans.push_back((double)sum / k);
    // calculate for next subarrays by subtracting sum from left
    for (int i = k; i < n; i++)
    {
        sum += arr[i] - arr[i - k];
        ans.push_back((double)sum / k);
    }
    return ans;
}
// TC -> O(n)

// main function
int main()
{
    vector<int> arr = {1, 3, 2, 6, -1, 4, 1, 8, 2};
    int k = 5;
    // Brute-force approach
    vector<double> res = avg(arr, k);
    cout << "Using brute: " << endl;
    for (double val : res)
    {
        cout << val << " ";
    }
    cout << endl;

    // Optimal approach
    vector<double> res2 = avgOptimal(arr, k);
    cout << "Using optimal: " << endl;
    for (double val : res2)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}