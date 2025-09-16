/*
Q1. Longest Substring with At Most K Distinct Characters (LC 340)
Find max substring length that contains at most K distinct chars.
s = "eceba", k = 2
Output: 3
*/

#include <bits/stdc++.h>
using namespace std;

// Better -> Expand from each start, maintain frequency map.
int better(string s, int k)
{
    int len = s.length(), maxLen = 0;
    // Expand from each start
    for (int i = 0; i < len; i++)
    {
        // Maintain frequency map
        unordered_map<char, int> mp;
        // Expand till we have at most k distinct chars
        for (int j = i; j < len; j++)
        {
            mp[s[j]]++;
            if (mp.size() > k)
            {
                break;
            }
            maxLen = max(maxLen, j - i + 1);
        }
    }
    return maxLen;
}
// TC -> O(N^2), SC -> O(K)

// Optimal -> Sliding Window + HashMap, Expand right, shrink left until distinct count ≤ K.
int optimal(string s, int k)
{
    int len = s.length(), maxLen = 0, left = 0;
    unordered_map<char, int> mp;
    for (int right = 0; right < len; right++)
    {
        mp[s[right]]++;
        while (mp.size() > k)
        {
            mp[s[left]]--;
            if (mp[s[left]] == 0)
            {
                mp.erase(s[left]);
            }
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}
// TC -> O(N), SC -> O(K)

// main function
int main()
{
    string s = "eceba";
    int k = 2;
    cout << "Better: " << better(s, k) << endl;
    cout << "Optimal: " << optimal(s, k) << endl;
    return 0;
}