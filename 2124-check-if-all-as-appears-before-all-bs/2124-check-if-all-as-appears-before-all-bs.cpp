class Solution {
public:
    bool checkString(string s) {
        int count = 0;
        for(int c : s){
            if(c == 'b') count++;
            if(c == 'a' && count > 0) return false;
        }
        return true;
    }
};