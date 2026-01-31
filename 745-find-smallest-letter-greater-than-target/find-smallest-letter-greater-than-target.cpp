class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int mins = INT_MAX;
        for(char c: letters){
            if(c - target > 0){
                mins = min(mins, c - target);
            }
        }
        if(mins == INT_MAX) return letters[0];
        return (target + mins);
    }
};