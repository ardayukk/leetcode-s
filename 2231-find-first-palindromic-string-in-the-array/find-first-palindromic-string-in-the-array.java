class Solution {
    public String firstPalindrome(String[] words) {
        for(int i = 0; i < words.length; i++)
        {
            if(isPalindromic(words[i]))return words[i];
        }
        return "";
    }
    public boolean isPalindromic(String str)
    {
        int strLen = str.length();
        for(int i = 0; i < strLen / 2; i++)
        {
            if(str.charAt(i) != str.charAt(strLen - i - 1))return false;
        }
        return true;
    }  
}