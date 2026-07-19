#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string smallestSubsequence(string s) {

        int freq[26] = {0};

        for (int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;
        }

        bool visited[26] = {false};
        stack<char> st;

        for (int i = 0; i < s.length(); i++) {

            char current = s[i];

            freq[current - 'a']--;

            if (visited[current - 'a'])
                continue;

            while (!st.empty() &&
                   current < st.top() &&
                   freq[st.top() - 'a'] > 0) {

                visited[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(current);
            visited[current - 'a'] = true;
        }

        string ans = "";

        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};