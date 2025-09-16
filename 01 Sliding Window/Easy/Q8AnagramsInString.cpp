/*
Q8. Find All Anagrams in a String
Given s and p, return all start indices of p's anagrams in s. Strings lowercase letters.
s="cbaebabacd", p="abc"
i=0: "cba" → sorted "abc" == "abc" → push 0
i=1: "bae" → "abe" ≠ "abc"
... i=6: "bac" sorted "abc" → push 6
Output: [0, 6]
*/

#include <bits/stdc++.h>
using namespace std;

// Brute -> For every start i (0..n-m), take substring s.substr(i,m), sort it and compare to sorted p.
vector<int> brute(string s, string p)
{
    int n = s.length(), m = p.length();
    vector<int> ans;
    string sortedP = p;
    sort(sortedP.begin(), sortedP.end());

    for (int i = 0; i <= n - m; i++)
    {
        string sub = s.substr(i, m);
        sort(sub.begin(), sub.end());
        if (sub == sortedP)
        {
            ans.push_back(i);
        }
    }
    return ans;
}
// TC -> O((n-m+1) * (m log m))

// Better -> For each window compute frequency array of 26 letters from scratch and compare arrays (comparison is O(26))
vector<int> better(string s, string p)
{
    int n = s.length(), m = p.length();
    vector<int> ans;
    vector<int> target(26, 0);
    // Count frequency of characters in p
    for (char ch : p)
    {
        target[ch - 'a']++;
    }

    // comapre
    for (int i = 0; i <= n - m; i++)
    {
        vector<int> match(26, 0);
        for (int j = 0; j < m; j++)
        {
            match[s[i + j] - 'a']++;
        }
        if (target == match)
        {
            ans.push_back(i);
        }
    }
    return ans;
}
// TC -> O(n)

// Optimal -> Sliding-window with incremental counts: maintain windowCount that we update (add new char, remove outgoing char) and compare counts.
vector<int> optimal(string s, string p)
{
    int n = s.length(), m = p.length();
    vector<int> ans;
    vector<int> target(26, 0);
    vector<int> match(26, 0);
    // Count frequency of characters in p
    for (char ch : p)
    {
        target[ch - 'a']++;
    }

    // check
    for (int i = 0; i < n; i++)
    {
        match[s[i] - 'a']++;
        if (i >= m)
        {
            match[s[i - m] - 'a']--;
        }

        if (i >= m - 1 && target == match)
        {
            ans.push_back(i - m + 1);
        }
    }
    return ans;
}
// TC -> O(n)
// Using map
vector<int> usingMap(string s, string p)
{
    int n = s.size(), m = p.size();
    vector<int> ans;
    map<char, int> target, match;

    // Count frequency of characters in p
    for (char c : p)
    {
        target[c]++;
    }

    for (int i = 0; i < n; i++)
    {
        match[s[i]]++;

        // Remove the character that is no longer in the window
        if (i >= m)
        {
            match[s[i - m]]--;
            if (match[s[i - m]] == 0)
            {
                match.erase(s[i - m]); // Clean up to keep maps comparable
            }
        }

        // If maps are equal, it means an anagram is found
        if (i >= m - 1 && match == target)
        {
            ans.push_back(i - m + 1);
        }
    }
    return ans;
}
// TC -> O(n)

// main function
int main()
{
    string s = "cbaebabacd", p = "abc";
    cout << "Brute: ";
    vector<int> res1 = brute(s, p);
    for (auto it : res1)
        cout << it << " ";
    cout << endl;

    cout << "Better: ";
    vector<int> res2 = better(s, p);
    for (auto it : res2)
        cout << it << " ";
    cout << endl;

    cout << "Optimal: ";
    vector<int> res3 = optimal(s, p);
    for (auto it : res3)
        cout << it << " ";
    cout << endl;

    cout << "Using Map: ";
    vector<int> res4 = usingMap(s, p);
    for (auto it : res4)
        cout << it << " ";
    cout << endl;

    return 0;
}