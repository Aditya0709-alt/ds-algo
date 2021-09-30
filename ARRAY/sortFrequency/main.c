#include <stdio.h>
#include <stdlib.h>
int *freq_sort_array(int *, int);
int main()
{
  int a[10] = {1, 4, 9, 1, 2, 4, 3, 1, 7, 4};
  int *b, i;
  printf("Input Array\n");
  for (i = 0; i < 10; i++)
    printf("%d ", a[i]);
  b = freq_sort_array(a, 10);
  printf("\nOutput array\n");
  for (i = 0; i < 10; i++)
    printf("%d ", b[i]);
}

int *freq_sort_array(int *a, int len)
{
  int i, j, temp, count, k = 0, s = 0, t = 0;
  int *b = (int *)malloc(len * sizeof(int));
  int *c = (int *)malloc(len * sizeof(int));
  for (i = 0; i < len; i++)
  {
    for (j = i + 1; j < len; j++)
    {
      if (a[j] == a[i])
      {
        temp = a[j];
        for (j; j > i + 1; j--)
        {
          a[j] = a[j - 1];
        }
        a[++i] = temp;
      }
    }
  }
  for (i = 0; i < len; i++)
  {
    a[j] = a[i];
    count = 1;
    if (i != len - 1)
    {
      while (a[++i] == a[j] && i < len)
        count++;
      i = i - 1;
    }
    b[k] = a[j];
    c[k++] = count;
  }
  for (i = 1; i < k; i++)
  {
    for (j = 0; j < k - i; j++)
    {
      if (c[j] < c[j + 1])
      {
        c[j] = c[j] + c[j + 1] - (c[j + 1] = c[j]);
        b[j] = b[j] + b[j + 1] - (b[j + 1] = b[j]);
      }
    }
  }
  for (i = 0; i < k; i++)
  {
    for (j = 0; j < c[i]; j++)
      a[s++] = b[i];
  }
  return a;
}