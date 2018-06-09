/**
 * Fun little problem to compute the approximate value of pi given just
 * an PRNG. Assume a unit circle centered at the origin and check how
 * many random points fall within it while choosing from the sample of
 * unit square centered at the origin.
*/

#include <iostream>
#include <random>

using namespace std;

int main(int argc, const char** argv)
{
  if (argc != 2) {
    cout << "Usage: pi_montecarlo <samplecount>" << endl;
    return 1;
  }

  size_t cnt = atoi(argv[1]);
  cout << "Running " << cnt << " samples" << endl;
  
  uniform_real_distribution<double> urd(-1.0D, 1.0D);
  default_random_engine re;
  double x, y;
  size_t interiors = 0;
  for (size_t i = 0; i < atoi(argv[1]); ++i) {
    x = urd(re);
    y = urd(re);
    if (sqrt(x*x + y*y) <= 1.0D) {
      ++interiors;
    }
  }

  double ratio = interiors / (double)cnt;
  cout << "Pi = " << ratio * 4.0D << endl;

  return 0;
}
