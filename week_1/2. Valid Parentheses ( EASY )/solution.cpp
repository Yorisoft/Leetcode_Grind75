class Solution {
public:
    bool isValid(string s) {
        // create a stack - LIFO
        // for each char in the string s, 
        // if its an open char add to stack: ( { [
        // if its a closing char, pop a character from the stack. Check both characters to see if they match
        // if they dont match, break loop, return false. 
        // if they match, continue untill end of loop and if all match return true. 
        
        std::stack<char> myStack;

        if( s.length() <= 1 ){
            return false; 
        } 
        for ( char c : s){
            if( c == '(' | c == '{' | c == '[' ){
                myStack.push(c);
            } else {                
                if (myStack.empty() || myStack.top() != c-1 && myStack.top() != c-2){
                    return false;
                }
                myStack.pop();
            }
        }
        return myStack.empty() ? true : false;
    }
};