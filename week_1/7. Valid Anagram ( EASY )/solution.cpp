class Solution {
public:
    bool isAnagram(string s, string t) {
        // for every char in s, save to table
        // then loop through t, for every char in t, query table for that char
        // if current char isnt in table, return false
        // remove current char from table and move on to next
        // after looping through t and checking ever char agaist table, 
        // check if table is empty, return true if it is, false if it is not. 
        
        for( char c : t){
            if(s.find(c) != std::string::npos){
                s.erase(s.find(c), 1);
            } else {
                return false;
            }
        }

        return s.empty();
    }
};


// Better Solutions: counts char frequency
class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> ms, mt;
        for (char c: s) ms[c]++;
        for (char c: t) mt[c]++;
        return ms == mt;
    }
};