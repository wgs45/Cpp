#include <stdio.h>

int main()
{
  int N;
  int L;
  int train[50] = {0};
  int i, j;
  int temp;

  scanf("%d", &N);

  while (N--)
  {
    scanf("%d", &L);
    int count = 0;

    for (i = 0; i < L; i++)
    {
      scanf("%d", &train[i]);
    }

    for (i = 0; i < L - 1; i++)
    {
      for (j = 0; j < L - 1 - i; j++)
      {
        if (train[j] > train[j + 1])
        {
          temp = train[j];
          train[j] = train[j + 1];
          train[j + 1] = temp;
          count++;
        }
      }
    }
    printf("Optimal train swapping takes %d swaps.\n", count);
  }

  return 0;
}