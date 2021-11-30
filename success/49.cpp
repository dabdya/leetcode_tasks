class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<string, vector<string>> groups;
        
        for (const auto& s : strs) {
            // string scopy = s;
            // sort(begin(scopy), end(scopy));
            string scopy = CountingSort(s);
            groups[scopy].push_back(s);
        }
        
        vector<vector<string>> result;
        for (const auto& [_, group] : groups) {
            result.push_back(group);
        }
        
        return result;
    }
    
private:
    string CountingSort(const string& s) {
        int count[26] = { };
        for (const char& c : s) {
            count[c - 'a']++;
        }
        
        string result;
        for (int i = 0; i < 26; i++) {
            result += string(count[i], i + 'a');
        }
        return result;
    }
};