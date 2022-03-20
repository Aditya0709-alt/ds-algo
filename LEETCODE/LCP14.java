class Solution {
    public String longestCommonPrefix(String[] strs) {
        String prefix = strs[0];
        for(int i = 0; i < strs.length; i++){
            if(prefix.length() == 0){
                    break;
            }
            while(!strs[i].startsWith(prefix)){
                if(prefix.length() == 0){
                    break;
                }
                prefix = prefix.substring(0, prefix.length() - 1);
            }
        }
        return prefix;
    }
    
}
