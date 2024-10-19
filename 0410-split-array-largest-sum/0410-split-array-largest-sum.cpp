class Solution {
public:
    int calculateCount(vector<int>& nums, int k, int mid) {
        int cnt = 0,val = 0;
        for(int i = 0;i<nums.size();i++) {
            if(val + nums[i] > mid) {
                cnt++;
                val = nums[i];
            } else val += nums[i];
        }
        if(val != 0) cnt++;
        return cnt;
    }

    int splitArray(vector<int>& nums, int k) {
        int sum = 0,maxi = INT_MIN;
        for(int i=0;i<nums.size();i++) {
            sum+=nums[i];
            maxi = max(maxi,nums[i]);
        }

        int l = maxi , h = sum, ans = -1;
        while(l<=h) {
            int mid = l + (h-l)/2;

            int count = calculateCount(nums,k,mid);
            if(count > k) l = mid+1;
            else if(count <= k) {
                ans = mid;
                h = mid - 1;
            }
        }
        return ans;
    }
};