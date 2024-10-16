class Solution {
public:

    int checkCapacity(int mid, vector<int>& weights, int days) {
        int cnt = 0,ans = 0;
        for(int i=0;i<weights.size();i++) {
            if(cnt + weights[i] > mid) {
                ans++;
                cnt = weights[i];
            } else {
                cnt += weights[i];
                if(cnt == mid) {
                    ans++;
                    cnt = 0;
                }
            }
        }
        if(cnt < mid && cnt!=0) ans++;
        return ans;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0,maxi = INT_MIN;
        for(int i=0;i<weights.size();i++) {
            sum+=weights[i];
            maxi = max(weights[i],maxi);
        }

        int l = maxi, h = sum , ans = 0;
        while(l<=h) {
            int mid = (l+h)/2;
            int val = checkCapacity(mid,weights,days);
            if(val <= days) {
                ans = mid;
                cout<<ans<<" ";
                h = mid-1;
            }
            else if(val > days) {
                l = mid + 1;
            }
        }
        return ans;
    }
};