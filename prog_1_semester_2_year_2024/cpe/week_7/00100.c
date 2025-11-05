#include <stdio.h>

#include <stdlib.h>

int main()
{
  int a, b, value;
  int max = 0;
  int temp = 1;
  int temp2;
  int temp3, flag;

  while (scanf("%d %d", &a, &b) != EOF)
  {
    if (a > b)
    {
      temp3 = a;
      a = b;
      b = temp3;
      flag = 1;
    }
    temp2 = a;
    while (a <= b)
    {
      value = a;
      while (value != 0)
      {
        if ((value % 2) == 0)
        {
          value = value / 2;
        }
        else
        {
          value = value * 3 + 1;
        }
        temp++;
        if (value == 1)
        {
          break;
        }
        else
        {
        }
      }

      if (temp > max)
      {
        max = temp;
      }
      temp = 1;
      a++;
    }

    if (flag == 1)
    {
      printf("%d %d %d\n", b, temp2, max);
    }
    else
    {
      printf("%d %d %d\n", temp2, b, max);
    }
    max = 0;
    flag = 0;
  }

  return 0;
}