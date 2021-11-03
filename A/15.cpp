class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(begin(nums), end(nums));
        vector<vector<int>> result;
        
        for (int i = 0; i < nums.size(); i++) {
            
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            
            int lp = i + 1;
            int rp = nums.size() - 1;
            
            while (lp < rp) {
                
                if (rp < nums.size() - 1 && nums[rp] == nums[rp + 1]) {
                    rp--;
                    continue;
                }
                
                int sum_ = nums[i] + nums[lp] + nums[rp];
                if (sum_ < 0) {
                    lp++;
                }
                else if (sum_ > 0) {
                    rp--;
                }
                else {
                    result.push_back({nums[i], nums[lp], nums[rp]});
                    lp++;
                    rp--;
                }
            }
        }
        
        return result;
    }
};