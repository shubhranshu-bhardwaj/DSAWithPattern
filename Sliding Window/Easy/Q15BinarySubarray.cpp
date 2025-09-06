/*
Q15. Binary Subarray with Sum
Given an array of integers arr and an integer target, return the number of subarrays whose
sum equals the target.
arr=[1,0,1,0,1], target=2
Subarrays: [1,0,1], [1,0,1,0], [0,1,0,1] → count=4
Output = 4
*/

#include <bits/stdc++.h>
using namespace std;

// Brute -> Two nested loops, outer loop picks a starting index i.
// Inner loop picks an ending index j, and calculates the sum of the subarray arr[i..j].
// If the sum equals the target, increment the count, return the total count

int brute(vector<int> &arr, int target)
{
    int n = arr.size(), count = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == target)
            {
                count++;
            }
        }
    }
    return count;
}
// TC -> O(n^2)

// Better == Optimal -> with HashMap
int optimal(vector<int> &arr, int target)
{
    unordered_map<int, int> mp;
    mp[0] = 1;
    int sum = 0, count = 0;
    for (int x : arr)
    {
        sum += x;
        if (mp.count(sum - target))
            count += mp[sum - target];
        mp[sum]++;
    }
    return count;
}
// TC -> O(n)

// main function
int main()
{
    vector<int> arr = {1, 0, 1, 0, 1};
    int target = 2;
    cout << "Count using brute: " << brute(arr, target) << endl;
    cout << "Count using optimal: " << optimal(arr, target) << endl;
    return 0;
}