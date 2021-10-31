class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        
        int lp = 0;
        int rp = 0;
        
        vector<vector<int>> intersections;
        
        while (lp < firstList.size() && rp < secondList.size()) {
            
            int startpoint = max(firstList[lp][0], secondList[rp][0]);
            int endpoint = min(firstList[lp][1], secondList[rp][1]);
            
            if (startpoint <= endpoint) {
                intersections.push_back({startpoint, endpoint});
            }
            
            if (firstList[lp][1] < secondList[rp][1]) {
                lp += 1;
            }
            else {
                rp += 1;
            }
        }
        return intersections;
//         int n = firstList.size();
//         int m = secondList.size();
        
//         int first_pointer = 0;
//         int second_pointer = 0;
        
//         vector<vector<int>> intersections;
        
//         while (first_pointer < n && second_pointer < m) {
            
//             const vector<int>& first_interval = firstList[first_pointer];
//             const vector<int>& second_interval = secondList[second_pointer];
            
//             if (first_interval == second_interval) {
//                 intersections.push_back(first_interval);
//                 first_pointer++;
//                 second_pointer++;
//             }
//             else {
//                 vector<int> intersection = GetIntersection(first_interval, second_interval);
//                 if (intersection.size() > 0) {
//                     intersections.push_back(intersection);
//                 }
                
//                 if (intersection == first_interval) {
//                     first_pointer++;
//                 }
//                 else if (intersection == second_interval) {
//                     second_pointer++;
//                 }
//                 else {
                    
//                     const vector<int>& left_interval = GetLeftInterval(first_interval, second_interval);
//                     if (left_interval == first_interval) {
//                         first_pointer++;
//                     }
//                     else {
//                         second_pointer++;
//                     }
                    
//                 }
//             }
            
//         }
        
//         return intersections;
    }

// private:
    
//     vector<int> GetLeftInterval(
//         const vector<int>& first_interval, const vector<int>& second_interval) {
        
//         if (first_interval[0] < second_interval[0]) {
//             return first_interval;
//         }
        
//         if (first_interval[0] > second_interval[0]) {
//             return second_interval;
//         }
        
//         if (first_interval[1] < second_interval[1]) {
//             return first_interval;
//         }
//         return second_interval;
        
//     }
    
//     vector<int> GetIntersection(
//         const vector<int>& first_interval, const vector<int>& second_interval) {
        
//         const vector<int>& left_interval = GetLeftInterval(first_interval, second_interval);
        
//         const vector<int>& right_interval = 
//             (left_interval == first_interval) ? second_interval : first_interval;
        
//         if (left_interval[0] == right_interval[0]) {
//             return { left_interval[0], min(left_interval[1], right_interval[1]) };
//         }
        
//         if (left_interval[1] < right_interval[0]) {
//             return { };
//         }
        
//         if (left_interval[1] >= right_interval[0] && left_interval[1] <= right_interval[1]) {
//             return { right_interval[0], left_interval[1] };
//         }
        
//         return { right_interval[0], right_interval[1] };
//     }
    
};