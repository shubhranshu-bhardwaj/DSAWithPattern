/*
Q2. Longest Substring with All Unique Characters of Size K
Given s and K, find the longest substring of size exactly K with all distinct characters.
s="aababcabc", K=3
Output = "abc"
*/

#include <bits/stdc++.h>
using namespace std;

// Brute -> Check all substrings of size K.
string brute(string s, int k)
{
    int slen = s.length();
    string ans = "";
    for (int i = 0; i + k <= slen; i++)
    {
        unordered_set<char> st;
        bool ok = true;
        for (int j = i; j < i + k; j++)
        {
            if (st.count(s[j]))
            {
                ok = false;
                break;
            }
            st.insert(s[j]);
        }
        if (ok)
        {
            ans = s.substr(i, k);
        }
    }
    return ans;
}
// TC -> O(n*k)

// Better == Optimal -> Sliding window with map
string optimal(string s, int k)
{
    unordered_map<char, int> mp;
    int left = 0, slen = s.length();
    string ans = "";
    for (int right = 0; right < slen; right++)
    {
        mp[s[right]]++;
        while (mp[s[right]] > 1)
        {
            mp[s[left]]--;
            if (mp[s[left]] == 0)
            {
                mp.erase(s[left]);
            }
            left++;
        }
        if (right - left + 1 == k)
        {
            ans = s.substr(left, k);
            mp[s[left]]--;
            if (mp[s[left]] == 0)
            {
                mp.erase(s[left]);
            }
            left++;
        }
    }
    return ans;
}
// TC -> O(n)

// main function
int main()
{
    string s = "aababcabc";
    int k = 3;

    string resBrute = brute(s, k);
    string resOptimal = optimal(s, k);

    cout << "Brute Force Result: " << resBrute << endl;
    cout << "Optimal Result: " << resOptimal << endl;

    return 0;
}