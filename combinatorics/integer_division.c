/**
 * Compute x/y for integers using only +, - and * operations
 */

#include <stdio.h>
#include <unistd.h>

int divide(int x, int y)
{
  if (!y)
    return -1;
  if (x < y)
    return 0;

  // Keep doubling the denominator while it is leq to the numerator
  int q = 1;
  int y_prime = y;
  while (2*y_prime <= x) {
    q *= 2;
    y_prime *= 2;
  }

  // Keep adding the original denominator while result is leq to the numerator
  // and increment the quotient each time
  while ((y_prime += y) <= x)
    ++q;

  return q;
}

int main()
{
  int x, y;
  while (1) {
    scanf("%d %d", &x, &y);
    if (!y)
      break;
    
    printf("%d/%d = %d\n", x, y, divide(x, y));
  }

  return 0;
}
