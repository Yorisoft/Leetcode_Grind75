class Solution {
public:
    bool isPalindrome(string s) {
        // Check s for non-alphanumeric characters
            // for c in s, if c is not in range of 65 - 90 OR 97 - 122 then delete c
        // for s.size/2 , check the current element i, with s.size()-i
        // if a missmatch is found, break and return false.
        // if loop finishes return true.
        std::string cleanString;      
        // if string is 1 character return true
        if ( s.length() == 1 ){
            return true;
        }

        // clean up string
        for(char c : s){
            if (!(c < 65 || c > 90 && c < 97 || c > 122 ) || !(c < 48 || c > 57))
                cleanString += c;
        }
        std::cout << cleanString << endl;

        // check string is palindrom
        for (int i = 0; i < (cleanString.length()-1/2); i++){
            if( tolower(cleanString[i]) != tolower(cleanString[(cleanString.length()-1)-i]) ){
                return false;
            }
        }        
        
        return true;
    }
};


// Better solution, use isalnum
class Solution {
public:
    bool isPalindrome(string s) {
        string s1 = "";
        for(auto it : s){
            if(isalnum(it)){
                s1 += tolower(it);
            }
        }
        for(int i = 0;i < s1.size()/2;i++){
            if(s1[i] != s1[s1.size() - i - 1]) return false;
        }
        return true;
    }
};