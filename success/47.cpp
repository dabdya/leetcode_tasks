class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> visited;
        visited.assign(nums.size(), false);
        RecursiveApproach(nums, visited);
        
        vector<vector<int>> result;
        for (const auto& permutation: permutations) {
            result.push_back(permutation);
        }
        return result;
    }

private:
    set<vector<int>> permutations;
    vector<int> permutation;
    
    void RecursiveApproach(vector<int>& nums, vector<bool>& visited) {
        
        if (permutation.size() == nums.size()) {
            vector<int> sorted_perm(nums.size());
            partial_sort_copy(
                begin(permutation), end(permutation), 
                begin(sorted_perm), end(sorted_perm));
            
            permutations.insert(permutation);
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