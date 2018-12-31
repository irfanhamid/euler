/**
 * Find the first non-repeating character in a stream
 */

#include <iostream>
#include <cstring>

using namespace std;

class Stream
{
public:
    Stream()
    {
        memset(encountered, 0, sizeof(int) * 26);
    }

    void ingest(const char e)
    {
        ++cursor;
        if (encountered[e - 'a'] > 0) {
            encountered[e - 'a'] = -encountered[e - 'a'];
            return;
        }

        encountered[e - 'a'] = cursor;
    }

    char fnr()
    {
        int min = INT32_MAX;
        char min_char = 0;
        for (int i = 0; i < 25; ++i) {
            if (encountered[i] > 0 && encountered[i] < min) {
                min = encountered[i];
                min_char = 'a' + i;
            }
        }

        return min_char;
    }

private:
    int encountered[26];
    int cursor = 0;
};

int main()
{
    char ch;
    Stream s;
    do {
        cin >> ch;
        if (ch == 'X') {
            ch = s.fnr();
            if (!ch)
                cout << "no non-repeating char" << endl;
            else
                cout << ch << endl;
        } else {
            s.ingest(ch);
        }
    } while (true);

    return 0;
}