class Solution {
public:
// substring = s[0], totalsum = substring.size();
// for every char in s, starting 1
// if substring.find(c) != npos
// substring = substring.substr(@.find(c) + 1)
// end if 
// substring += c;
// totalsum = max(totalsum, substring.size())
// return totalsum;
    int lengthOfLongestSubstring(string s) {
        if(s.size() < 1){
            return 0;
        }

        std::string substring = std::string(1, s[0]);
        int length = substring.size();

        for (char& c : s){
            if(substring.find(c) != std::string::npos){
                substring = substring.substr(substring.find(c) + 1); 
            }
            substring += c;

            length = std::max(static_cast<size_t>(length), substring.size());
        }
        return length;
    }
};