class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<bool> visited;
        visited.assign(candidates.size(), false);
        
        sort(begin(candidates), end(candidates));
        search(0, 0, candidates, visited, target);
        return combinations;
    }
    
private:
    vector<vector<int>> combinations;
    vector<int> combination;
    
    void search(int i, int sum_, const vector<int>& nums, vector<bool>& visited, const int& target) {
        
        int n = nums.size();
        
        if (sum_ > target) {
            return;
        }
        
        if (sum_ == target) {
            combinations.push_back(combination);      
        }
        else {
            
            for (int k = i; k < n; k++) {
                if (visited[k] || k > 0 && nums[k] == nums[k - 1] && !visited[k - 1]) {
                    continue;
                }
                combination.push_back(nums[k]);
                visited[k] = true;
                search(k + 1, sum_ + nums[k], nums, visited, target);
                combination.pop_back();
                visited[k] = false;
            }
        }
    }
};