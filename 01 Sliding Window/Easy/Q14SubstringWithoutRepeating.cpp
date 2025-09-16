/*
Q14. Longest Substring Without Repeating Characters
Given a string, find the longest substring length with unique characters
s="abcabcbb" → longest unique is "abc" length=3
*/

#include <bits/stdc++.h>
using namespace std;

// Brute -> Try all possible substrings from i to j,Use a set to check if characters are unique
// If unique, update the maximum length

int brute(string s)
{
    int n = s.length(), maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            unordered_set<char> st;
            bool unique = true;
            for (int k = i; k <= j; k++)
            {
                if (st.count(s[k]))
                {
                    unique = false;
                    break;
                }
                st.insert(s[k]);
            }
            if (unique)
            {
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }
    return maxLen;
}
// TC -> O(n^3)

// Better -> Fix the left index i, expand right index j until a duplicate is found
// Use a set to track seen characters

int better(string s)
{
    int n = s.length(), maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        unordered_set<char> st;
        for (int j = i; j < n; j++)
        {
            if (st.count(s[j]))
            {
                break;
            }
            st.insert(s[j]);
            maxLen = max(maxLen, j - i + 1);
        }
    }
    return maxLen;
}
// TC -> O(n^2)

// Optimal -> Use sliding window with left and right, stores the most recent index of each character
// If duplicate found within the window, move left after the duplicate
int optimal(string s)
{
    int n = s.length(), maxLen = 0, left = 0;
    unordered_map<char, int> mp;
    for (int right = 0; right < n; right++)
    {
        if (mp.count(s[right]) && mp[s[right]] >= left)
        {
            left = mp[s[right]] + 1;
        }
        mp[s[right]] = right;
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}
// TC -> O(n)

// main function
int main()
{
    string str = "abcabcbb";
    cout << "Max Length using brute: " << brute(str) << endl;
    cout << "Max Length using better: " << better(str) << endl;
    cout << "Max Length using optimal: " << optimal(str);
    return 0;
}