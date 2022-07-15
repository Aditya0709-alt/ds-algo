# We use a dictionary for storing the decoded characters of the key. We only store the unique characters. 

# Then, we iterate through the message and store the value of the given key present in the dictionary.

# Time Complexity: O(N), where N is len(key)

class Solution:
    def decodeMessage(self, key: str, message: str) -> str:
        keyValue = {}
        curr = 0
        for i in key.replace(" ", ""):
            if i not in keyValue:
                keyValue[i] = chr(curr + ord('a'))
                curr += 1
        
        res = []
        for j in message:
            if j == " ":
                res.append(" ")
            else:
                res.append(keyValue[j])
        
        return "".join(res)
