/*
Q9. Permutation in String
Given s1 and s2, return true if s2 contains any permutation of s1 as a substring.
s1="ab", s2="eidbaooo"
window at i=3 => "ba" sorted "ab" -> match -> true.
Output: true
*/

#include <bits/stdc++.h>
using namespace std;

// Brute -> For each start, sort substring of s2 and compare with sorted s1.
bool brute(string s, string p)
{
    int n = s.length(), m = p.length();
    if (n > m)
    {
        return false;
    }
    string sorted_S = s;
    sort(sorted_S.begin(), sorted_S.end());
    for (int i = 0; i <= m - n; i++)
    {
        string sub = p.substr(i, n);
        sort(sub.begin(), sub.end());
        if (sub == sorted_S)
        {
            return true;
        }
    }
    return false;
}
// TC -> O((n-m+1) * (m log m))

// Better -> Use count arrays and compare for each start (rebuild window counts each time).
bool better(string s1, string s2)
{
    int s1len = s1.length(), s2len = s2.length();
    if (s1len > s2len)
    {
        return false;
    }
    vector<int> target(26, 0);
    for (char ch : s1)
    {
        target[ch - 'a']++;
    }
    for (int i = 0; i <= s2len - s1len; i++)
    {
        vector<int> match(26, 0);
        for (int j = 0; j < s1len; j++)
        {
            match[s2[i + j] - 'a']++;
        }
        if (target == match)
        {
            return true;
        }
    }
    return false;
}
// TC -> O(n*m)

// Optimal -> Sliding window counts (incrementally update counts). Compare arrays in O(26)
bool optimal(string s1, string s2)
{
    int s1len = s1.length(), s2len = s2.length();
    if (s1len > s2len)
    {
        return false;
    }
    vector<int> target(26, 0);
    vector<int> match(26, 0);
    for (char ch : s1)
    {
        target[ch - 'a']++;
    }
    for (int i = 0; i < s2len; i++)
    {
        match[s2[i] - 'a']++;
        if (i >= s1len)
        {
            match[s2[i - s1len] - 'a']--;
        }
        if (i >= s1len - 1 && target == match)
        {
            return true;
        }
    }
    return false;
}
// TC -> O(n)

// main function
int main()
{
    string s1 = "ab";
    string s2 = "eidbaooo";

    cout << "Testing Brute Force: " << (brute(s1, s2) ? "true" : "false") << endl;
    cout << "Testing Better Approach: " << (better(s1, s2) ? "true" : "false") << endl;
    cout << "Testing Optimal Approach: " << (optimal(s1, s2) ? "true" : "false") << endl;
    return 0;
}