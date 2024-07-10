class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<int> st;
        for(int i=0;i<logs.size();i++) {
            if(logs[i][0] == '.' && logs[i][1] == '/') continue; 
            else if(logs[i][0] == '.' && logs[i][1] == '.' && st.size() != 0) st.pop();
            else if(logs[i][0] == '.' && logs[i][1] == '.' && st.size() == 0) continue;
            else st.push(0);
        }
        return st.size();
    }
};