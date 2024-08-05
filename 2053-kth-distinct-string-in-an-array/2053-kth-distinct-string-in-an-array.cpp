class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string,int> mpp;

        for(int i=0;i<arr.size();i++) {
            mpp[arr[i]]++;
        }
        int cnt = 0;
        string str = "";
        for(auto it : arr) {
            if(mpp[it] == 1) cnt++;
            if(cnt == k) {
                str = it;
                break;
            }
        }
        return str;
    }
};