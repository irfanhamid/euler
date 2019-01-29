/**
 * https://leetcode.com/problems/sliding-window-maximum/
 * Slightly different than the sliding_window_max.cpp problem
 */

#include <iostream>
#include <vector>

using namespace std;

struct Result {
    size_t left;
    size_t right;
    int32_t sum;
};

Result MaxSlidingWindow(const vector<int32_t>& v, size_t k)
{
    if (v.size() < k)
        throw new underflow_error("Window is smaller than vector");

    int32_t sum = 0;
    Result res;
    for (size_t i = 0; i < k; ++i) {
        sum += v[i];
    }
    res.left = 0;
    res.right = k-1;
    res.sum = sum;
    for (size_t i = k; i < v.size(); ++i) {
        sum += v[i];
        sum -= v[i-k];
        if (sum > res.sum) {
            res.left = i-k+1;
            res.right = i;
            res.sum = sum;
        }
    }

    return res;
}

int main()
{
    vector<int32_t> v = {1,3,-1,-3,5,3,6,7};
    Result res = MaxSlidingWindow(v, 3);
    cout << "(" << res.left << ", " << res.right << ") = " << res.sum << endl;
    return 0;
}