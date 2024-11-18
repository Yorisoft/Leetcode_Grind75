class Solution {
public:
    bool isPalindrome(int x) {
        // Convert x into a string of char. 1243421
        // get size of x as string. ex 121 equal size 3. 
        // loop through half of the string
        // for each index of the string, check it with its corresponding opposite index. 

        // if both index match, move on to next untill end of loop.
        // if end of loop is reached before a missmatch is found, return true. 
        // if a missmatch is found before end of loop, return false. 

        // O(n/2). Only iterating through half of the string in worse case scenario. 
 
        std::string intToString = std::to_string(x);
        int length = intToString.length();

        for( int y = 0; y <= (length/2); y++){
            if ( intToString[y] != intToString[(length-1)-y] ){               
                return false;
            }                  
        }
        return true; 
    }
};