class Solution {
public:
    bool canJump(vector<int>& nums) {
        // return search(static_cast<int>(nums.size()) - 1, nums);
        
        int n = static_cast<int>(nums.size());
        if (n == 1) return true;
        
        int target = n - 1;
        
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] + i >= target) {
                target = i;
            }
        }
        
        return target == 0;
    }

private:
    
    bool search(int rp, const vector<int>& nums) {
        // не работает почему то :(
        if (rp == 0) return true;

        for (int i = rp - 1; i >= 0; i--) {
            if (nums[i] >= rp - i && search(i, nums)) {
                return true;
            }
        }

        return false;
    }
};