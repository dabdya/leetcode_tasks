class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        for (const auto& row : matrix) { 
            if (BinarySearch(row, target)) {
                return true;
            }
        }
        
        return false;
        // time: O(m * logn), space: O(1)
    }

private:
    bool BinarySearch(const vector<int> row, int target) {
        
        int lp = 0;
        int rp = row.size() - 1;
        
        while (lp != rp) {
            int m = (lp + rp) / 2;
            if (row[m] == target) { 
                return true;
            }
            
            if (row[m] < target) {
                lp = m + 1;
            }
            else {
                rp = m;
            }
        }
        
        return row[lp] == target;
    }
};