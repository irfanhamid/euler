#include <iostream>
#include <vector>

using namespace std;

void PrintSet(const vector<char> s)
{
    if (!s.size()) {
        cout << "{}";
    } else {
        cout << "{" << s[0];
        for (size_t i = 1; i < s.size(); ++i) {
            cout << ", " << s[i];
        }
        cout << "}";
    }
}

/**
 * Since we are assuming mathematical sets s will not have any duplicates
 * and will be bound to a maximum of 32 elements for a poset of max 2^32.
 */
vector<vector<char>> PoSet(const vector<char>& s)
{
    vector<vector<char>> poSet;
    if (s.size() > 32)
        return move(poSet);
    
    uint32_t limit = 1 << s.size();
    for (uint32_t c = 0; c < limit; ++c) {
        poSet.push_back(vector<char>());
        uint32_t alias = c;
        for (size_t i = 0; i < s.size(); ++i) {
            if ((alias >> i) & 1)
                poSet[poSet.size() - 1].push_back(s[i]);
        }
    }

    return move(poSet);
}

int main()
{
    vector<char> s = {'a', 'b', 'c', 'd'};
    auto poset = PoSet(s);
    cout << "{";
    PrintSet(poset[0]);
    for (size_t i = 1; i < poset.size(); ++i) {
        cout << ", ";
        PrintSet(poset[i]);
    }
    cout << "}" << endl;

    return 0;
}