import java.util.Collections;

class AddAllElements1305 {
    public static void traverse(TreeNode root, List<Integer> l) {
      while(root != null){
        traverse(root.left,l);

        l.add(root.val);

        traverse(root.right, l);
    }

   public List<Integer> addAll(TreeNode root1, TreeNode root2){
       List<Integer> l = new ArrayList<>();

       traverse(root1,l);

       traverse(root2,l);

       Collections.sort(l);

       return l;
      }
}
