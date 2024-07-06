class Solution {
public:
    int passThePillow(int n, int time) {
        int val1 = time / (n-1);
        int val2 = time % (n-1);

        if(val1 % 2 != 0) return n - val2;
        else return val2 + 1;
    }
};