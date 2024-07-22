class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int, string> mpp;
        vector<string>v;
        for(int i=0; i < size(names); i++)
            mpp[heights[i]] = names[i];
        for (auto i = mpp.rbegin(); i != mpp.rend(); ++i) v.push_back(i->second);
        return v;
    }
};