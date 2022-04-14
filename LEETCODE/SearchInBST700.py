# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def searchBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        current = root
        
        while current is not None:
            if current.val == val:
                return current
            elif current.val < val:
                current = current.right
            else:
                current = current.left
        return None
    
