/**
 * Find the minimum window in string src that contains all
 * characters in the string tgt
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>

using namespace std;

bool IsSubstring(const map<char, uint32_t>& h)
{
    return all_of(h.begin(), h.end(),
                  [](pair<char, uint32_t> e) { return e.second > 0; });
}

pair<size_t, size_t> MinWindow(const string& src, const string& tgt)
{
    pair<size_t, size_t> ret;
    map<char, uint32_t> h;
    set<char> tgts(tgt.begin(), tgt.end());
    for (char c : tgt)
        h.insert(pair<char, size_t>(c, 0));

    size_t l = 0, r = 0;
    size_t minLeft = 0, minRight = SIZE_MAX;
    if (tgts.find(src[0]) != tgts.end())
        ++h[src[0]];

    while (r < src.length()) {
        if (IsSubstring(h)) {
            if ((r - l) < (minRight - minLeft)) {
                minLeft = l;
                minRight = r;
            }
            if (tgts.find(src[l]) != tgts.end())
                --h[src[l]];
            ++l;
        } else {
            ++r;
            if (tgts.find(src[r]) != tgts.end())
                ++h[src[r]];
        }
    }

    ret.first = minLeft;
    ret.second = minRight;
    return ret;
}

int main()
{
    pair<size_t, size_t> window;
    string src = "ADOBECODEBANC";
    string tgt = "ABC";
    window = MinWindow(src, tgt);
    cout << "(" << window.first << ", " << window.second << ")" << endl;
    if (window.second != SIZE_MAX) {
        for (size_t i = window.first; i <= window.second; ++i)
            cout << src[i];
    }
    cout << endl;
    return 0;
}