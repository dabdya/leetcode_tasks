class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        return BinarySearch(nums, 0, nums.size() - 1, target);
    }

private:
    int BinarySearch(const vector<int>& nums, int lp, int rp, int target) {
        
        if (lp == rp) {
            if (nums[lp] == target)
                return lp;
            return -1;
        }
        
        int m = (lp + rp) / 2;
        if (nums[m] == target) {
            return m;
        }
        
        int left = BinarySearch(nums, lp, m, target);
        int right = BinarySearch(nums, m + 1, rp, target);
        if (left >= 0) return left;
        if (right >= 0) return right;
        return -1;
    }
};