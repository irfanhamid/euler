/**
 * https://leetcode.com/problems/trapping-rain-water/
 */

#include <iostream>
#include <vector>

using namespace std;

uint32_t TrapRainwater(const vector<uint32_t>& elev)
{
  if (elev.size() <= 2)
    return 0;

  size_t len = elev.size();
  vector<int32_t> slope;
  slope.resize(len);
  if (elev[0] > elev[1])
    slope[0] = 1;
  else if (elev[0] < elev[1])
    slope[0] = -1;
  else
    slope[0] = 0;

  if (elev[len-1] > elev[len-2])
    slope[len-1] = 1;
  else if (elev[len-1] < elev[len-2])
    slope[len-1] = -1;
  else
    slope[len-1] = 0;

  for (size_t i = 1; i < elev.size() - 1; ++i) {
    if (elev[i-1] < elev[i] && elev[i+1] < elev[i])
      slope[i] = 1;
    else if (elev[i-1] > elev[i] && elev[i+1] > elev[i])
      slope[i] = -1;
    else
      slope[i] = 0;
  }

  uint32_t volume = 0;
  for (size_t i = 0; i < len; ) {
    if (slope[i] > 0) {
      size_t start = i++;
      while (i < len && slope[i] <= 0) ++i;
      if (i < len) {
        uint32_t brim = min(elev[start], elev[i]);
        for (size_t j = start; j <= i; ++j)
          volume += (brim > elev[j] ? brim - elev[j] : 0);
        cout << "(" << start << ", " << i << ") = (" << brim << ", " << volume << ")" << endl;        
      }
    } else {
      ++i;
    }
  }
  return volume;
}

int main()
{
  vector<uint32_t> v = {0,1,0,2,1,0,1,3,2,1,2,1};
  cout << TrapRainwater(v) << endl;
  return 0;
}
