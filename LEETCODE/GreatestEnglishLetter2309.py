# Simply sort the string.
# Now traverse the array backwards (<--) because the highest char would be in the end.
# Check if both lower and upper case for the character exists in str.
# Return the char in uppercase, else return empty string.


# Time Complexity: O(N) , N = len(s)

class Solution:
    def greatestLetter(self, s: str) -> str:
        s=sorted(s)
        for i in reversed(range(len(s))): 
            if s[i].upper() in s and s[i].lower() in s:
                return s[i].upper()
        return ""
