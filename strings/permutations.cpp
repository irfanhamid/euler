#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

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
  return 0;
}
