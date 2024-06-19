class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(((long long) m * k) > bloomDay.size()) return -1;

        int maxi = INT_MIN;
        for(int i=0;i<bloomDay.size();i++) maxi = max(maxi,bloomDay[i]);

        int l = 1, r = maxi;
        while(l<=r) {
            int mid = (l+r)/2;
            int flower = 0,cnt=0;
            for(int i=0;i<bloomDay.size();i++) {
                
                if(mid >= bloomDay[i]) cnt++;
                else {
                    flower += cnt/k;
                    cnt=0;
                }
                
            }
            flower += cnt/k;
            // if( flower == m) return mid;
            if(flower < m) l = mid+1;
            else r = mid-1;


        }
        return l;
    }
};