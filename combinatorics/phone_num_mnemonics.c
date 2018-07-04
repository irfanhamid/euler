/**
 * Provided a mapping of phone number digits to sets of characters, generate all
 * possible words (not just valid words, just strings) against a given phone
 * number
 */

#include <stdio.h>
#include <unistd.h>

const char* map[] = {
  "",
  "",
  "ABC",
  "DEF",
  "GHI",
  "JKL",
  "MNO",
  "PQRS",
  "TUV",
  "WXYZ"
};

void enumerate_phone_mnemonic(char* acc, int acc_idx, const char* pn, int pn_idx)
{
  if (!pn[pn_idx]) {
    acc[acc_idx] = '\0';
    printf("%s\n", acc);
    return;
  }

  if (pn[pn_idx] == '0' || pn[pn_idx] == '1') {
    enumerate_phone_mnemonic(acc, acc_idx, pn, ++pn_idx);
    return;
  }

  int digit = (int) (pn[pn_idx] - '0');
  for (int i = 0; map[digit][i]; ++i) {
    acc[acc_idx] = map[digit][i];
    enumerate_phone_mnemonic(acc, acc_idx + 1, pn, pn_idx + 1);
  }
}

int main(int argc, const char** argv)
{
  char str[1024];
  enumerate_phone_mnemonic(str, 0, argv[1], 0);
  return 0;
}
