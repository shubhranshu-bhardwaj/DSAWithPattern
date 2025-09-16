/*
Q4. Longest Substring with Same Letters after K Replacements
Find length of longest substring where you can replace at most K chars to make all chars same.
Input: s = "AABABBA", k = 1
Output: 4
Explanation:
"ABAB" or "BABA" can be turned into "AAAA" or "BBBB" with 1 replacement.
*/

#include <bits/stdc++.h>
using namespace std;

// Brute -> Try every possible substring. For each, count frequency of characters.
// Check if the number of characters to change (length - maxFreq) is ≤ K.
int brute(string s, int k)
{
    int n = s.size(), maxLen = 0;
    for (int i = 0; i < n; ++i)
    {
        vector<int> count(26, 0);
        for (int j = i; j < n; ++j)
        {
            count[s[j] - 'A']++;
            int maxFreq = *max_element(count.begin(), count.end());
            int len = j - i + 1;
            if (len - maxFreq <= k)
                maxLen = max(maxLen, len);
        }
    }
    return maxLen;
}

// TC -> O(n³)

// Better -> For each starting point, expand the window to the right.
// Keep updating the count and max frequency.
int better(string s, int k)
{
    int n = s.size(), maxLen = 0;
    for (int start = 0; start < n; ++start)
    {
        vector<int> count(26, 0);
        int maxFreq = 0;
        for (int end = start; end < n; ++end)
        {
            count[s[end] - 'A']++;
            maxFreq = max(maxFreq, count[s[end] - 'A']);
            int len = end - start + 1;
            if (len - maxFreq <= k)
                maxLen = max(maxLen, len);
        }
    }
    return maxLen;
}
// TC -> O(n²)

// Optimal -> Use sliding window. Keep track of max frequency in the current window.
// If changes needed (window size - maxFreq) > k, shrink the window.
int optimal(string s, int k)
{
    vector<int> count(26, 0);
    int left = 0, maxFreq = 0, maxLen = 0;

    for (int right = 0; right < s.size(); ++right)
    {
        count[s[right] - 'A']++;
        maxFreq = max(maxFreq, count[s[right] - 'A']);

        // Check if we need to shrink the window
        while ((right - left + 1) - maxFreq > k)
        {
            count[s[left] - 'A']--;
            left++;
        }

        // Update maximum length
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}
// TC -> O(n)

// main function
int main()
{
    string s = "AABABBA";
    int k = 1;

    cout << "Input string: " << s << ", k = " << k << endl;

    int res1 = brute(s, k);
    int res2 = better(s, k);
    int res3 = optimal(s, k);

    cout << "Brute force result: " << res1 << endl;
    cout << "Better approach result: " << res2 << endl;
    cout << "Optimal approach result: " << res3 << endl;

    return 0;
}
// n