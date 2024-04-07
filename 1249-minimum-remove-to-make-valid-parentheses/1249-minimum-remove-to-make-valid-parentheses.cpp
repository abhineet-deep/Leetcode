class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string str;
        stack<pair<char, int>> st;

        for(int i=0;i<s.size();i++) {
            if(s[i] == '(') st.push({'(',i});
            else if(s[i] == ')' && st.size()) st.pop();
            else if(s[i] == ')' && !st.size()) s[i] = '#';
        }

        while(!st.empty()) {
            s[st.top().second] = '#';
            st.pop();
        }

        for(int i=0;i<s.size();i++) {
            if(s[i]!= '#') str.push_back(s[i]);
        }

        return str;
    }
};