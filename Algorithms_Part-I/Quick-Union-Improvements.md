## Improvement-1

### Weighted Quick-Union / Union By Rank

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

**Running time: O(log(N))**



## Improvement-2

### Path compression
- Just after computing the root of p, set the id of each examined root to point to that root

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
    while(i != id[i]) {
    // Make every other node in the path point to its grandparent
    id[i] = id[id[i]];
    i = id[i];
    }
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

|            Algorithm           | Running Time |
|:------------------------------:|--------------|
|           quick find           |      MN      |
|           quick union          |      MN      |
|           weighted QU          |  N + M log N |
|      QU + path compression     |  N + M log N |
| weighted QU + path compression | N + M log* N |
