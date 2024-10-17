#include <cstdio>

int main() {

  char str[20] = "Today-is-terrible!";
  int i;
  for (i = 6; i <= 10; i++)
    if (str[i] == '-') str[i - 1] = 'x';

  for (i = 12; i >= 0; i--)

    if (str[i] == 't') str[i + 1] = 'e';

  printf("%s\n", str);

  return 0;

}