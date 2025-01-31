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

/*
We use a set (charSet) to keep track of unique characters in the current substring.
We maintain two pointers, left and right, to represent the boundaries of the current substring.
The maxLength variable keeps track of the length of the longest substring encountered so far.
We iterate through the string using the right pointer.
If the current character is not in the set (charSet), it means we have a new unique character.
We insert the character into the set and update the maxLength if necessary.
If the character is already present in the set, it indicates a repeating character within the current substring.
In this case, we move the left pointer forward, removing characters from the set until the repeating character is no longer present.
We insert the current character into the set and continue the iteration.
Finally, we return the maxLength as the length of the longest substring without repeating characters.
*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLength = 0;
        unordered_set<char> charSet;
        int left = 0;
        
        for (int right = 0; right < n; right++) {
            if (charSet.count(s[right]) == 0) {
                charSet.insert(s[right]);
                maxLength = max(maxLength, right - left + 1);
            } else {
                while (charSet.count(s[right])) {
                    charSet.erase(s[left]);
                    left++;
                }
                charSet.insert(s[right]);
            }
        }
        
        return maxLength;
    }
};


/*
We improve upon the first solution by using an unordered map (charMap) instead of a set.
The map stores characters as keys and their indices as values.
We still maintain the left and right pointers and the maxLength variable.
We iterate through the string using the right pointer.
If the current character is not in the map or its index is less than left, it means it is a new unique character.
6 We update the charMap with the character's index and update the maxLength if necessary.
If the character is repeating within the current substring, we move the left pointer to the next position after the last occurrence of the character.
We update the index of the current character in the charMap and continue the iteration.
At the end, we return the maxLength as the length of the longest substring without repeating characters.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLength = 0;
        unordered_map<char, int> charMap;
        int left = 0;
        
        for (int right = 0; right < n; right++) {
            if (charMap.count(s[right]) == 0 || charMap[s[right]] < left) {
                charMap[s[right]] = right;
                maxLength = max(maxLength, right - left + 1);
            } else {
                left = charMap[s[right]] + 1;
                charMap[s[right]] = right;
            }
        }
        
        return maxLength;
    }
};