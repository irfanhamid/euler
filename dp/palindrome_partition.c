/**
 * Given a string, determine the minimum number of cuts needed such that each
 * substring is a palindrome, e.g., "aab" needs 1 cut to give "aa" and "b".
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* memo;
int str_len;

int min_cuts_for_palindrome(char* str, int left, int right)
{
    if (left == right)
        return 0;
    if (*(memo + (left * str_len) + right) != -1)
        return *(memo + (left * str_len) + right);
    
    int l = left, r = right;
    while (l <= r) {
        if (str[l] != str[r])
            break;
        ++l; --r;
        if (l >= r)
            return 0;
    }
    
    int min_cuts = right - left;
    for (int i = 0; i < right - left; ++i) {
        int left_mins = min_cuts_for_palindrome(str, left, left +i);
        int right_mins = min_cuts_for_palindrome(str, left + i + 1, right);
        if (min_cuts > left_mins + right_mins + 1)
            min_cuts = left_mins + right_mins + 1;
    }

    *(memo + (left * str_len) + right) = min_cuts;
    return min_cuts;
}

int main()
{
    char str[] = "abcdefa";
    str_len = strlen(str);
    memo = (int*)malloc(str_len * str_len * sizeof(int));
    for (int i = 0; i < str_len * str_len; ++i)
        memo[i] = -1;
    printf("%d\n", min_cuts_for_palindrome(str, 0, str_len - 1));
    free(memo);
    return 0;
}