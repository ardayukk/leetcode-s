class Solution {
    public boolean isMatch(String s, String p) {
        return isMatchHelper(s, p, 0, 0);
    }
    
    private boolean isMatchHelper(String s, String p, int sIndex, int pIndex) {
        // Base case: if pattern is fully matched
        if (pIndex == p.length()) {
            return sIndex == s.length();
        }
        
        // Check if we have a direct character match or '.'
        boolean currentMatch = (sIndex < s.length() &&
                                (p.charAt(pIndex) == '.' || p.charAt(pIndex) == s.charAt(sIndex)));
        
        // Check for '*' case
        if (pIndex + 1 < p.length() && p.charAt(pIndex + 1) == '*') {
            // If we have a '*', we can choose to skip the character in pattern or repeat it
            return (isMatchHelper(s, p, sIndex, pIndex + 2) ||  // skip the '*' and its preceding character
                    (currentMatch && isMatchHelper(s, p, sIndex + 1, pIndex)));  // repeat the preceding character
        } else {
            // Normal character match or '.', move to the next character in both strings
            return currentMatch && isMatchHelper(s, p, sIndex + 1, pIndex + 1);
        }
    }
}
