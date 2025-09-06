/*
Q12. Longest Substring with at Most K Distinct Characters
Given a string return the length of longest substring with K distinct characters
s="araaci", K=2
*/

#include <bits/stdc++.h>
using namespace std;

// Brute -> Generate substring, count distinct using set
int brute(string s, int k)
{
    int n = s.length(), maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        unordered_set<char> st;
        for (int j = i; j < n; j++)
        {
            st.insert(s[j]);
            if (st.size() <= k)
            {
                maxLen = max(maxLen, j - i + 1);
            }
            else
            {
                break;
            }
        }
    }
    return maxLen;
}
// TC -> O(n^2 *n)

// Better == Optimal -> Sliding Window with HashMap, expand right shrink left when distinct > k
int optimal(string s, int k)
{
    int n = s.length(), maxLen = 0, left = 0;
    unordered_map<char, int> mp;
    for (int right = 0; right < n; right++)
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
// TC -> O(n)

// main function
int main()
{
    string str = "araaci";
    int k = 2;
    int res1 = brute(str, k);
    int res2 = optimal(str, k);
    cout << "Max Length using brute: " << res1 << endl;
    cout << "Max length using optimal: " << res2;
    return 0;
}