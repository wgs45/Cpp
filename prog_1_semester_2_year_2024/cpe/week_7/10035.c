#include <stdio.h>

int main()
{
  unsigned long long a, b;

  while (1)
  {
    scanf("%llu %llu", &a, &b);

    // Stop condition
    if (a == 0 && b == 0)
    {
      break;
    }

    int carry = 0, carryCount = 0;

    while (a > 0 || b > 0)
    {
      int digitA = a % 10;
      int digitB = b % 10;

      if (digitA + digitB + carry >= 10)
      {
        carry = 1;
        carryCount++;
      }
      else
      {
        carry = 0;
      }

      a /= 10;
      b /= 10;
    }

    if (carryCount == 0)
    {
      printf("No carry operation.\n");
    }
    else if (carryCount == 1)
    {
      printf("1 carry operation.\n");
    }
    else
    {
      printf("%d carry operations.\n", carryCount);
    }
  }

  return 0;
}