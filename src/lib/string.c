#include "include/string.h"
#include <stdlib.h>
#include <string.h>

char *strjoin(const char *s1, const char *s2) {
  char *str;
  int len1;
  int len2;

  if (!s1 && !s2) {
    return (NULL);
  } else if (!s1) {
    return ((char *)s2);
  } else if (!s2) {
    return ((char *)s1);
  }

  len1 = strlen(s1);
  len2 = strlen(s2);

  str = (char *)malloc((len1 + len2 + 1) * sizeof(char));

  if (!str) {
    return (NULL);
  }

  strcpy(str, s1);
  strcat(str, s2);

  return (str);
}
