#include <stdio.h>
#include <string.h>

#define STRLEN 128

int anagram(char* const str1, char* const str2)
{
  if (!str1)
    return !str2;
  else if (!str2)
    return !str1;

  int hist[26];
  memset(hist, 0, sizeof(int)*26);

  char* ch = str1;
  while (*ch) {
    ++hist[*ch - 'a'];
    ++ch;
  }

  ch = str2;
  while (*ch) {
    --hist[*ch - 'a'];
    ++ch;
  }

  for (int i = 0; i < 26; ++i) {
    if (hist[i])
      return 0;
  }

  return 1;
}

int main()
{
  char str1[STRLEN];
  char str2[STRLEN];

  printf("%d\n", anagram("", "test"));
  printf("%d\n", anagram(NULL, "test"));
  printf("%d\n", anagram(NULL, NULL));
  
  while (1) {
    scanf("%s", str1);
    scanf("%s", str2);

    printf("%s\t%s\n", str1, str2);

    if (anagram(str1, str2))
      printf("anagram\n");
    else
      printf("not anagram\n");
  }

  return 0;
}
