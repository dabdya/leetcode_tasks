public class Solution {
    public string FrequencySort(string s) {
        
        var counter = new Dictionary<char, int>();

        for (var i = 0; i < s.Length; i++)
        {
            if (!counter.ContainsKey(s[i]))
            {
                counter[s[i]] = 0;
            }
            counter[s[i]] += 1;
        }

        var result = new List<string>();
        foreach (var pair in counter.OrderByDescending(k => k.Value))
        {
            result.Add(new string(pair.Key, pair.Value));
        }

        return string.Join("", result);
    }
}