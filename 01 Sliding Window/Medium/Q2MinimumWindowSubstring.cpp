/*
Minimum Window Substring with All Characters of T
Given strings s and t, return the minimum window substring of s such that every char in t is included.
s="ADOBECODEBANC", t="ABC" → smallest window "BANC".
Output = "BANC"
*/

#include <bits/stdc++.h>
using namespace std;

// Brute -> Try every possible substring of s, for each substring, chek if it
// contains all characters of t using map

string brute(string s, string t)
{
    int slen = s.length(), minLen = INT_MAX;
    string ans = "";
    unordered_map<char, int> target;

    for (char ch : t)
    {
        target[ch]++;
    }

    for (int i = 0; i < slen; i++)
    {
        for (int j = i; j < slen; j++)
        {
            unordered_map<char, int> freq;
            for (int k = i; k <= j; k++)
            {
                freq[s[k]]++;
            }
            bool ok = true;
            for (auto &p : target)
            {
                if (freq[p.first] < p.second)
                {
                    ok = false;
                    break;
                }
            }
            if (ok && (j - i + 1 < minLen))
            {
                minLen = j - i + 1;
                ans = s.substr(i, j - i + 1);
            }
        }
    }
    return ans;
}
// TC -> O(n^3)

// Better -> Fix left and expand right to find a valid window, once valid shrink from left

string better(string s, string t)
{
    int slen = s.length(), minLen = INT_MAX;
    string ans = "";
    unordered_map<char, int> target;
    for (char ch : t)
    {
        target[ch]++;
    }
    for (int left = 0; left < slen; left++)
    {
        unordered_map<char, int> window;
        int req = t.length(), count = 0;
        for (int right = left; right < slen; right++)
        {
            if (target.count(s[right]))
            {
                window[s[right]]++;
                if (window[s[right]] <= target[s[right]])
                {
                    count++;
                }
            }
            if (count == req)
            {
                if (right - left + 1 < minLen)
                {
                    minLen = right - left + 1;
                    ans = s.substr(left, minLen);
                }
                break;
            }
        }
    }
    return ans;
}
// TC -> O(n^2)

/*
Optimal -> Use two pointers: l and r (left, right) as a sliding window.
Track:
need: char frequencies from t
window: current window char frequencies
Maintain formed: how many required chars are satisfied
When valid, try to shrink from l to minimize
*/
string optimal(string s, string t)
{
    unordered_map<char, int> need;
    for (char c : t)
        need[c]++;

    unordered_map<char, int> window;
    int required = need.size(); // distinct chars
    int formed = 0;

    int l = 0, r = 0;
    int minLen = INT_MAX, start = 0;

    while (r < s.size())
    {
        char c = s[r];
        window[c]++;
        if (need.count(c) && window[c] == need[c])
        {
            formed++;
        }

        while (l <= r && formed == required)
        {
            if (r - l + 1 < minLen)
            {
                minLen = r - l + 1;
                start = l;
            }
            // shrink from left
            char leftChar = s[l];
            window[leftChar]--;
            if (need.count(leftChar) && window[leftChar] < need[leftChar])
            {
                formed--;
            }
            l++;
        }
        r++;
    }

    return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
}

// main function
int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";

    cout << "Input string: " << s << endl;
    cout << "Target string: " << t << endl
         << endl;

    string resBrute = brute(s, t);
    cout << "Brute force result: " << resBrute << endl;

    string resBetter = better(s, t);
    cout << "Better approach result: " << resBetter << endl;

    string resOptimal = optimal(s, t);
    cout << "Optimal approach result: " << resOptimal << endl;

    return 0;
}