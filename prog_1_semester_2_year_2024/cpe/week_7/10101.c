#include <stdio.h>

void bangla(long long int tn)
{
  if (tn >= 10000000)
  {
    bangla(tn / 10000000);
    printf(" kuti");
    tn = tn % 10000000;
  }
  if (tn >= 100000)
  {
    bangla(tn / 100000);
    printf(" lakh");
    tn = tn % 100000;
  }

  if (tn >= 1000)
  {
    bangla(tn / 1000);
    printf(" hajar");
    tn = tn % 1000;
  }

  if (tn >= 100)
  {
    bangla(tn / 100);
    printf(" shata");
    tn = tn % 100;
  }

  if (tn < 100 && tn > 0)
    printf(" %d", tn);
}

int main()
{

  long long int n;
  int c = 1;
  while (scanf("%lld", &n) != EOF)
  {
    printf("%4d.", c++);
    if (n == 0)
    {
      printf(" %d", n);
    }
    bangla(n);
    printf("\n");
  }

  return 0;
}