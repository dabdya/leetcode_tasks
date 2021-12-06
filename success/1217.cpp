class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        
        int n = static_cast<int>(position.size());
        int result = INT_MAX;
            
        for (int i = 0; i < n; i++) {
            
            int cost = 0;
            
            for (int j = i + 1; j < n; j++) {
                
                int shift = abs(position[j] - position[i]);
                if (shift % 2 != 0) {
                    cost += 1;
                }
            }
            
            for (int j = i - 1; j >= 0; j--) {
                
                int shift = abs(position[j] - position[i]);
                if (shift % 2 != 0) {
                    cost += 1;
                }
            }
            
            result = min(result, cost);
        }
        
        return result;
    }
};