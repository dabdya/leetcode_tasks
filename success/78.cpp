class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        size_t n = nums.size();
        search(0, nums);
        return subsets_;
    }

private:
    vector<vector<int>> subsets_;
    vector<int> subset;
    
    void search(int i, const vector<int>& nums) {
        if (i == nums.size()) {
            subsets_.push_back(subset);
        }
        else {
            subset.push_back(nums[i]);
            search(i + 1, nums);
            subset.pop_back();
            search(i + 1, nums);
        }
    }
};