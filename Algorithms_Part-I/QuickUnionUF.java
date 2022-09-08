public class QuickUnionUF {
  private int [] id;
  
  public QuickUnionUF(int N){
    id = new int[N];
    for(int i = 0; i < N; i++){
      // set id of each object to itself (N array accesses)
      id[i] = i;
    }
  }
  
  private int root(int i){
    // chase parent pointers until each root (depth of i array accesses)
    while(i != id[i]) i = id[i];
    return i;
  }
  
  public boolean connected(int p, int q){
    // check if p and q have the same root
    return root(p) == root(q);
  }
  
  public void union(int p, int q){
    // change root of p to point to root of q
    int i = root(p);
    int j = root(q);
    id[i] = j;
  }
}


Cost model 
- Trees can get tall 
- Find operation can get expensive
- Complexity -> O(N^2)
  
  Thus, quick-union is too slow
  
