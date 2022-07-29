# Here, we need to iterate through the lists once and just add it to our sum. Then, we just reverse the number 'sum' and store it in a new linked list. 

# Time Complexity: O(N), where N is the length of the linked list.
# Space Complexity: O(N)

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        sum = 0
        
        resNode = ListNode()
        copyNode = resNode
        
        #start iteration
        while(l1 != None or l2 != None or sum != 0):
            if(l1 != None):
                sum += l1.val
                l1 = l1.next
            
            if(l2!=None):
                sum += l2.val
                l2 = l2.next

            newNode = ListNode()
            newNode.val = sum % 10
            copyNode.next = newNode
            copyNode = newNode
            
            sum = sum // 10
            
        return resNode.next
