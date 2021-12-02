class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        std::transform(
            s.begin(), s.end(), s.begin(),
            [](char c){ return tolower(c); });
        
        vector<char> v(begin(s), end(s));
        search(v, 0);
        return permutations;
    }
    
private:
    vector<string> permutations;
    
    void search(vector<char>& s, int i) {
        
        if (i == s.size())  {
            string permutation = string(begin(s), end(s));
            permutations.push_back(permutation);
            return;
        }
        
        if (isdigit(s[i])) 
            search(s, i + 1);
        else {
            search(s, i + 1);
            s[i] = toupper(s[i]);
            search(s, i + 1);
            s[i] = tolower(s[i]);
        }        
    }
};