# Using BFS
# Time Complexity: O(N)


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def addOneRow(self, root: Optional[TreeNode], val: int, depth: int) -> Optional[TreeNode]:
        if depth == 1:
            return TreeNode(val, left = root)
        
        queue = collections.deque([root])
        height, size = 0, 0 
        
        while queue:
            N = len(queue)
            
            while N:
                node = queue.popleft()
                
                if height == depth - 2:
                    temp = node.left
                    node.left, node.left.left = TreeNode(val), temp
                    
                    temp = node.right
                    node.right, node.right.right = TreeNode(val), temp
                
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
                
                N -= 1
            
            height += 1
        
        return root
            
                    
