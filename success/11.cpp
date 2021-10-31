class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int lp = 0;
        int rp = height.size() - 1;
        
        int result = 0;
        while (lp < rp) {
            int width = rp - lp;
            int h = min(height[lp], height[rp]);
            result = max(result, width * h);
            
            if (height[lp] < height[rp]) {
                lp++;
            }
            else {
                rp--;
            }
        }
        return result;
    }
};