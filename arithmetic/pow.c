/**
 * Compute pow(x, n) to give x^n.
 * -100.0 < x < 100.0
 *  -2^31 < n < 2^31-1
 */

#include <stdio.h>

double power(double x, int32_t n)
{
  if (n < 0)
    return 1 / power(x, -n);

  if (n == 0)
    return 1;

  if (n == 1)
    return x;

  double res = power(x, n >> 1);
  res *= res;
  
  if (n % 2)
    res *= x;

  return res;
}

int main(int argc, const char** argv)
{
  double x;
  int32_t n;
  
  while (1) {
    scanf("%lf\t%d", &x, &n);
    if (!n)
      return 0;
    
    printf("%f\n", power(x, n));
  }

  return 0;
}
