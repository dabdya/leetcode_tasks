#include <algorithm>

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        int n = s.size();
        int m = p.size();
        
        if (m > n) return {};
        
        vector<char> p_counter(26, 0);
        vector<char> s_counter(26, 0);
        
        for (int i = 0; i < m; i++) {
            p_counter[p[i]-'a']++;
            s_counter[s[i]-'a']++;
        }
        
        vector<int> anagrams;
        
        if (p_counter == s_counter) {
            anagrams.push_back(0);
        }
        
        for (int i = m; i < n; i++) {
            
            s_counter[s[i - m]-'a']--;
            s_counter[s[i]-'a']++;
            
            if (p_counter == s_counter) {
                anagrams.push_back(i - m + 1);
            }
        }
        
        return anagrams;
        
    }
};