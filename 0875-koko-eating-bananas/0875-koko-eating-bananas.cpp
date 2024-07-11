class Solution {
public:
    
    int check(vector<int>& piles,int h, int mid) {
        long long sum = 0;
        for(int i=0;i<piles.size();i++) {
            sum+= piles[i]/mid;
            if(piles[i] % mid !=0) sum++;
        }
        if(sum <= h) return 1;
        return 0;
    }


    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = INT_MIN;
        for(int i=0;i<piles.size();i++) maxi = max(piles[i],maxi);

        int low = 1, high = maxi,res = maxi;
        while(low<=high) {
            int mid = low + (high-low)/2;
            if(check(piles,h,mid) == 1) {
                res = mid;
                cout<<mid<<" ";
                high = mid-1;
            }
            else low = mid+1;
        }
        return res;
    }
};