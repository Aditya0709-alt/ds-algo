
```python
import functools

@functools.lru_cache(maxsize=None)
def fib(num):
  if num < 2:
    return num
  else:
    return fib(num-1) + fib(num-2)
```
