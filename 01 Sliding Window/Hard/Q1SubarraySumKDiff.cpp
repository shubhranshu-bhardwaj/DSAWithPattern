/*
Q1. Subarrays with K Different Integers (LeetCode 992)
Given nums and integer K, count number of subarrays with exactly K distinct integers.
a=[1,2,1,2,3], K=2
Valid: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2]
Output = 7
*/

#include <bits/stdc++.h>
using namespace std;

// Brute -> Enumerate all subarrays, count distinct, using set.
int brute(vector<int> &a, int K)
{
    int n = a.size(), count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            unordered_set<int> st;
            for (int k = i; k <= j; k++)
            {
                st.insert(a[k]);
            }
            if (st.size() == K)
            {
                count++;
            }
        }
    }
    return count;
}
// TC -> O(n³)

// Better -> Fix left, expand right with freq map until distinct > K.
int better(vector<int> &a, int K)
{
    int n = a.size(), count = 0;
    for (int left = 0; left < n; left++)
    {
        unordered_map<int, int> freq;
        for (int right = left; right < n; right++)
        {
            freq[a[right]]++;
            if (freq.size() == K)
            {
                count++;
            }
            if (freq.size() > K)
            {
                break;
            }
        }
    }
    return count;
}
// TC -> O(n²)

// helper function for finding at most subarray
int atMostK(vector<int> &a, int K)
{
    int n = a.size(), count = 0, left = 0;
    unordered_map<int, int> freq;
    for (int right = 0; right < n; right++)
    {
        freq[a[right]]++;
        while (freq.size() > K)
        {
            freq[a[left]]--;
            if (freq[a[left]] == 0)
            {
                freq.erase(a[left]);
            }
            left++;
        }
        count += right - left + 1;
    }
    return count;
}

// Optimal -> Use helper function
int optimal(vector<int> &a, int K)
{
    return atMostK(a, K) - atMostK(a, K - 1);
}
// Tc -> O(n)

// main function
int main()
{
    vector<int> a = {1, 2, 1, 2, 3};
    int K = 2;

    cout << "Brute: " << brute(a, K) << endl;
    cout << "Better: " << better(a, K) << endl;
    cout << "Optimal: " << optimal(a, K) << endl;

    return 0;
}