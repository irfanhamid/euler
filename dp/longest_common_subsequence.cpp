#include <algorithm>
#include <iostream>
#include <memory>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

string LongestCommonSubseqNR(const string& a, const string& b)
{
    string lcs;
    size_t lenA = a.length();
    size_t lenB = b.length();
    if (!(lenA && lenB))
        return move(lcs);

    vector<vector<uint32_t>> m;
    m.resize(lenA + 1);
    for (size_t i = 0; i <= lenA; ++i)
        m[i].resize(lenB + 1);

    for (size_t i = 0; i < lenA; ++i) {
        for (size_t j = 0; j < lenB; ++j) {
            if (a[i] == b[j]) {
                m[i+1][j+1] = m[i][j] + 1;
            } else {
                m[i+1][j+1] = max(m[i][j+1], m[i+1][j]);
            }
        }
    }

    size_t lcsLen = m[lenA][lenB];
    lcs.resize(lcsLen);

    for (int16_t i = lenA; i >= 0; ) {
        for (int16_t j = lenB; j >= 0; ) {
            if (a[i-1] == b[j-1]) {
                lcs[--lcsLen] = a[i-1];
                --i, --j;
            } else if (i == 0) {
                --j;
            } else if (j == 0) {
                --i;
            } else if (m[i-1][j] > m[i][j-1]) {
                --i;
            } else {
                --j;
            }
        }
    }
    return move(lcs);
}

string LongestCommonSubseqR2(const string& a, string::iterator itA,
                             const string& b, string::iterator itB)
{
    string lcs;
    if (itA == a.end() || itB == b.end())
        return move(lcs);

    if (*itA == *itB) {
        lcs += *itA;
        ++itA, ++itB;
        lcs.append(LongestCommonSubseqR2(a, itA, b, itB));
    } else {
        string lcsA = LongestCommonSubseqR2(a, itA, b, itB + 1);
        string lcsB = LongestCommonSubseqR2(a, itA + 1, b, itB);
        if (lcsA.length() > lcsB.length())
            lcs.append(lcsA);
        else
            lcs.append(lcsB);
    }

    return move(lcs);
}

char* LongestCommonSubseqR(const char* a, const char* b)
{
    size_t lenA = a ? strlen(a) : 0;
    size_t lenB = b ? strlen(b) : 0;
    size_t maxLcs = min(lenA, lenB);
    if (!maxLcs)
        return nullptr;
    
    unique_ptr<char> lcs(new char[maxLcs + 1]);
    lcs.get()[0] = '\0';

    if (a[0] == b[0]) {
        lcs.get()[0] = a[0];
        char* tailLcs = LongestCommonSubseqR(a + 1, b + 1);
        if (tailLcs) {
            strcpy(lcs.get() + 1, tailLcs);
            delete tailLcs;
        } else {
            lcs.get()[1] = '\0';
        }
        return lcs.release();
    }

    char* aLcs = LongestCommonSubseqR(a, b + 1);
    char* bLcs = LongestCommonSubseqR(a + 1, b);
    lenA = aLcs ? strlen(aLcs) : 0;
    lenB = bLcs ? strlen(bLcs) : 0;
    if (lenA && lenA > lenB) {
        strcpy(lcs.get(), aLcs);
        delete aLcs;
        delete bLcs;
    } else if (lenB) {
        strcpy(lcs.get(), bLcs);
        delete aLcs;
        delete bLcs;
    }

    return lcs.release();
}

int main()
{
    //string a("babghjj");
    //string b("baacbjj");
    string a("abgj");
    string b("aabj");
    cout << LongestCommonSubseqR(a.c_str(), b.c_str()) << endl;
    cout << LongestCommonSubseqR2(a, a.begin(), b, b.begin()) << endl;
    cout << LongestCommonSubseqNR(a, b) << endl;
    return 0;
}
