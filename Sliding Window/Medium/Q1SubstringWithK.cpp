/*
Q1. Longest Substring with Exactly K Distinct Characters
Given string s and integer K, find the length of the longest substring with exactly K distinct characters.
s="aabacbebebe", K=3
substr "aabac" has {a,b,c} size=3, len=5
longest valid → "cbebebe" len=7
Output = 7
*/

#include <bits/stdc++.h>
using namespace std;

// Brute -> Generate all substrings, count distinct.
int brute(string s, int K)
{
    int n = s.length(), maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            unordered_set<char> st;
            for (int k = i; k <= j; k++)
            {
                st.insert(s[k]);
            }
            if (st.size() == K)
            {
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }
    return maxLen;
}
// TC -> O(n^3)

// Better -> Fix left, expand right, track frequencies.
int better(string s, int k)
{
    int n = s.length(), maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        unordered_map<char, int> mp;
        for (int j = i; j < n; j++)
        {
            mp[s[j]]++;
            if (mp.size() == k)
            {
                maxLen = max(maxLen, j - i + 1);
            }
            if (mp.size() > k)
            {
                break;
            }
        }
    }
    return maxLen;
}
// TC -> O(n^2)

// Optimal -> Maintain sliding window
int optimal(string s, int k)
{
    int n = s.length(), maxLen = 0, left = 0;
    unordered_map<char, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[s[i]]++;
        while (mp.size() > k)
        {
            mp[s[left]]--;
            if (mp[s[left]] == 0)
            {
                mp.erase(s[left]);
            }
            left++;
        }
        if (mp.size() == k)
        {
            maxLen = max(maxLen, i - left + 1);
        }
    }
    return maxLen;
}
// TC -> O(n)

// main function
int main()
{
    string str = "aabacbebebe";
    int k = 3;
    int res1 = brute(str, k);
    int res2 = better(str, k);
    int res3 = optimal(str, k);
    cout << "Max Length using brute: " << res1 << endl;
    cout << "Max length using better: " << res2 << endl;
    cout << "Max length using optimal: " << res3 << endl;
    return 0;
}