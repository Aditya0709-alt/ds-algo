# Approach
# - We check if the left node is present
# - If left node is present, we store the right subtree, add the left subtree to the right of the root, 
#   finally add the stored right subtree to the rightmost node of current tree.
# - If left node is absent, move to the next right node. 


# Time Complexity: O(N) (Recursive approach)
# Space Complexity: O(1)

class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        
        def rightmost(root):
            if (root.right):
                return rightmost(root.right)
            return root
        
        if root:
            nextright = None
            rightMOST = None
        
        while root:
            if root.left:
                rightMOST = rightmost(root.left);
                nextright = root.right;
                root.right = root.left;
                root.left = None;
                rightMOST.right = nextright;
            root=root.right
