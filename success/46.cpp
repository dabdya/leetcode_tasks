class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> visited;
        visited.assign(nums.size(), false);
        RecursiveApproach(nums, visited);
        return permutations;
    }
    
private:
    vector<vector<int>> permutations;
    vector<int> permutation;
    
    void RecursiveApproach(vector<int>& nums, vector<bool>& visited) {
        
        if (permutation.size() == nums.size()) {
            permutations.push_back(permutation);
            return;
        }
        
        for (auto i = 0u; i < nums.size(); i++) {
            if (!visited[i]) {
                
                permutation.push_back(nums[i]);
                visited[i] = true;
                
                RecursiveApproach(nums, visited);
                
                permutation.pop_back();
                visited[i] = false;
            }
        }
    }
};