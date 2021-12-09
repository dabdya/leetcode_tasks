class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        return search(arr, start);
    }
    
private:
    
    bool search(vector<int>& arr, int start) {
        
        
        if (arr[start] == 0) {
            return true;
        }
        
        arr[start] *= -1;
        
        int n = static_cast<int>(arr.size());
        
        if (start + arr[start] >= 0 && arr[start + arr[start]] >= 0) {
            if (search(arr, start + arr[start])) {
                return true;
            }
        }
        
        if (start - arr[start] < n && arr[start - arr[start]] >= 0) {
            if (search(arr, start - arr[start])) {
                return true;
            }
        }

        return false;
    }
};