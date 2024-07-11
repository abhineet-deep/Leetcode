class Solution {
public:

    int findRow(vector<vector<int>>& matrix, int target) {
        int l = 0 , h = matrix.size()-1;
        int col = matrix[0].size()-1;

        while(l<=h) {
            int mid = l + (h-l)/2;
            cout<<mid<<" ";
            if(matrix[mid][0] <= target && matrix[mid][col] >= target ) return mid;
            else if(matrix[mid][0] > target) h = mid-1;
            else l = mid + 1;
        }
        return -1;
    }

    bool findElement(vector<vector<int>>& matrix, int target, int row) {

        int l = 0 , h = matrix[0].size()-1;
        while(l<=h) {
            int mid = l + (h-l)/2;
            if(matrix[row][mid] == target) return true;
            else if(matrix[row][mid] > target) h = mid-1;
            else l = mid + 1;
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int row = findRow(matrix,target);
        if(row == -1) return false;
        return findElement(matrix,target,row);
    }
};