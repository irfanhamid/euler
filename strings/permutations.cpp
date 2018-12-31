#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

/**
 * Calculates and prints all permutations of s in-place. Modifies the
 * input string and does not create any new data structures.
 */
void Permutations2(char* s, size_t startIdx)
{
  if (!s)
    return;

  char* s2 = s + startIdx;
  size_t len = strlen(s2);
  if (len == 1) {
    cout << s << endl;
    return;
  }

  Permutations2(s, startIdx + 1);
  char tmp = s2[0];
  for (size_t i = 1; i < len; ++i) {
    if (s2[0] == s2[i])
      continue;
    s2[0] = s2[i];
    s2[i] = tmp;
    Permutations2(s, startIdx + 1);
    s2[i] = s2[0];
    s2[0] = tmp;
  }
}

vector<string> Permutations(const string& s)
{
  vector<string> strs;

  if (!s.length()) {
    return move(strs);
  } else if (s.length() == 1) {
    strs.emplace_back(s);
    return move(strs);
  }

  unordered_set<string::traits_type::char_type> seen;
  for (auto it = s.begin(); it != s.end(); ++it) {
    if (seen.find(*it) != seen.end())
      continue;
    seen.insert(*it);
    auto s2(s);
    s2.erase(find(s2.begin(), s2.end(), *it));
    auto subPermutations = Permutations(s2);
    for (auto& subPermutation : subPermutations) {
      strs.push_back(move(subPermutation += *it));
    }
  }

  return move(strs);
}

int main()
{
  auto permutations = Permutations("test");
  for (auto& p : permutations)
    cout << p << endl;

  cout << endl << endl;
  
  char s[] = "test";
  Permutations2(s, 0);
  return 0;
}
