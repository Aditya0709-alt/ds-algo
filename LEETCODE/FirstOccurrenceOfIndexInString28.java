class Solution {
    public int strStr(String haystack, String needle) {
        int ans = -1;
        
        int j = needle.length();
        
        for(int i = 0; i <= haystack.length() - j; i++){
            String temp = haystack.substring(i, i + j);
            
            if(temp.equals(needle)){
                ans = i;
                break;
            }
        }
        return ans;
    }       
}
