/*
Q3. Longest Substring Without Repeating Characters (LC 3)
Given a string s, find the length of the longest substring without repeating characters.
Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
*/

#include <bits/stdc++.h>
using namespace std;

// Brute -> Check all substrings and find the maximum length without repeating characters
int brute(string s)
{
    int len = s.length(), maxLen = 0;
    for (int i = 0; i < len; i++)
    {
        for (int j = i; j < len; j++)
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
// TC -> O(N^3), SC -> O(min(N, M)) where M is the size of character set

// Better -> Expand window, but reset when duplicate found.
int better(string s)
{
    int len = s.length(), maxLen = 0;
    for (int i = 0; i < len; i++)
    {
        unordered_set<char> st;
        for (int j = i; j < len; j++)
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
// TC -> O(N^2), SC -> O(min(N, M)) where M is the size of character set

// Optimal -> Sliding Window, expand the window by adding next character until duplicate found,
// then contract the window by removing previous character until no duplicate found.
int optimal(string s)
{
    int len = s.length(), maxLen = 0, left = 0;
    // Map to store the last seen index of each character
    unordered_map<char, int> lastSeen;

    // Expand the window
    for (int right = 0; right < s.size(); right++)
    {
        char currentChar = s[right];

        // If character was seen and is within the current window
        if (lastSeen.count(currentChar))
        {
            left = max(left, lastSeen[currentChar] + 1);
        }

        // Update the last seen position of the character
        lastSeen[currentChar] = right;

        // Update the maximum length
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}
// TC -> O(N), SC -> O(min(N, M)) where M is the size of character set

// main function
int main()
{
    string s = "abcabcbb";
    cout << "Brute Force: " << brute(s) << endl;
    cout << "Better: " << better(s) << endl;
    cout << "Optimal: " << optimal(s) << endl;
    return 0;
}