class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int n = nums.size();
        int i = BinarySearch(nums, 0, n - 1, target, 0);
        // Если ничего не нашлось, то и продолжать нет смысла
        if (i == -1) {
            return {-1, -1};
        }
        
        // Иначе нужно запустить бинарный поиск в разные стороны
        int start = BinarySearch(nums, 0, i - 1, target, -1);
        if (start == -1) start = i;
        
        int end = BinarySearch(nums, i + 1, n - 1, target, 1);
        if (end == -1) end = i;
        
        return {start, end};
        
    }

private:
    int BinarySearch(const vector<int>& nums, int lp, int rp, int target, int dir) {
        
        if (rp < 0 || lp >= nums.size()) {
            return -1;
        }
        
        while (lp != rp) {
            int m = (lp + rp) / 2;
            if (nums[m] == target) {
                if (dir > 0) {
                    return max(m, BinarySearch(nums, m + 1, rp, target, dir));
                }
                else if (dir < 0) {
                    return min(m, BinarySearch(nums, lp, m, target, dir));
                }
                else {
                    return m;
                }
            }
            else if (nums[m] < target) {
                lp = m + 1;
            }
            else {
                rp = m;
            }
        }
        
        return nums[lp] == target ? lp : -1;
        
    }
};