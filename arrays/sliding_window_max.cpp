#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Window {
public:
    Window(size_t l, const vector<int>& a) : array(a)
                                           , begin(0)
                                           , end(l-1)
    {
        backingStore.resize(l);
        for (size_t i = 0; i < min(l, a.size()); ++i)
            backingStore[i] = array[i];

        sort(backingStore.begin(), backingStore.end());
        for (int e : backingStore)
            cout << e << endl;
    }

    bool Inc()
    {
        if (end == array.size() - 1)
          return false;

        int disappearing = array[begin];
        ++begin;
        int appearing = array[++end];

        auto p = equal_range(backingStore.begin(), backingStore.end(), disappearing);
        backingStore.erase(p.first);
        backingStore.push_back(appearing);
        sort(backingStore.begin(), backingStore.end());

        return true;
    }

    int Largest() const
    {
        return backingStore[backingStore.size() - 1];
    }

private:
    const vector<int>& array;
    size_t begin;
    size_t end;

    vector<int> backingStore;
};

int main()
{
    vector<int> v = {5, 4, 2, 6, 7, 4, 8};
    Window w(4, v); 
    cout << endl << endl;
    cout << w.Largest() << endl;
    w.Inc();
    cout << w.Largest() << endl;
    w.Inc();
    cout << w.Largest() << endl;
    w.Inc();
    cout << w.Largest() << endl;

    return 0;
}
