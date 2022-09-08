### Improvement-1

##### Weighted quick-union

- Modify quick-union to avoid tall trees
- Keep track of size of each tree
- Balance by linking root of smaller tree to root of larger tree (union by rank or height)

```java
public class WeightedQuickUnion {
  private int [] id;
  private int [] sz = {0};
  
  public WeightedQuickUnion(int N){
    id = new int[N];
    for(int i = 0; i < N; i++){
      id[i] = i;
    }
  }
  
  private int root(int i){
    while(i != id[i]) i = id[i];
    return i;
  }
  
  public boolean connected(int p, int q){
    return root(p) == root(q);
  }
  
  public void union(int p, int q){
    int i = root(p);
    int j = root(q);
    if(i == j) return;
    if(sz[i] < sz[j]) {
      id[i] = j;
      sz[j] += sz[i];
    }
    else {
      id[j] = i;
      sz[i] += sz[j];
    }
  }
```

##### Running time
- Find - Takes time proportional to depth of p and q
- Union - Consntant time, O(1)

~ Running time is O(log(N))~
