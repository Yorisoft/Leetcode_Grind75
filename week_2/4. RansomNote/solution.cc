class Solution {
public:
// create map<char, int> char_map
// for each char in ransomNote,
// if it exist in char_map
// add to char_map[char] +1;
// else add to char_map[char] = 1;


    bool canConstruct(string ransomNote, string magazine) {
        std::map<char, int> char_map;

        for(char c : ransomNote){
            char_map[c]++;  
        }

        for (char c : magazine){
            
            if(char_map.find(c) != char_map.end()){
                char_map[c]--;
                if (char_map[c] == 0)
                    char_map.erase(c);

                if(char_map.empty())
                    break;
            } 
        }
        return char_map.empty();
    }
};


/*
Complexity
Time complexity: O(n)
Space complexity: O(1)
*/
class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    vector<int> count(26);
    for (const char c : magazine)
      ++count[c - 'a'];
    for (const char c : ransomNote) {
      if (count[c - 'a'] == 0)
        return false;
      --count[c - 'a'];
    }
    return true;
  }
};