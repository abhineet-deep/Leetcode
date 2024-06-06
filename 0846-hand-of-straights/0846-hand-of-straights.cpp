class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        sort(hand.begin(),hand.end());

        if(hand.size() % groupSize != 0) return false;

        for(int i = 0;i<hand.size();i++) {
            if(hand[i] >= 0) {
                int j = i;
                int next = hand[j] + 1;
                hand[j] = -1;
                int n = groupSize-1;
                j++;
                while(n > 0 && j<hand.size()) {
                    if(hand[j] == next) {
                        next = hand[j] + 1;
                        hand[j] = -1;
                        n--;
                    }
                    j++;
                }
                if(n!=0) return false;
            }
        }
        return true;

    }
};