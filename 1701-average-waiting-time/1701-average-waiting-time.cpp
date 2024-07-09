class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double res = 0;
        int timeTaken = 0;
        for(auto it : customers) {
            timeTaken = it[0] > timeTaken ? it[0] + it[1] : timeTaken + it[1];
            res+= (timeTaken - it[0]);
        } 
        return res/customers.size();
    }
};