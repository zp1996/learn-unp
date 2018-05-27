#include "unp.h"

int main(int argc, char **argv) {
  union {
    short s;
    char c[sizeof(short)];
  } un;

  printf("%s\n", CPU_VENDOR_OS);

  un.s = 0x0102;
  if (sizeof(short) == 2) {
    if (un.c[0] == 1 && un.c[1] == 2) {
      printf("%s\n", "big-endian");
    } else if (un.c[0] == 2 && un.c[1] == 1) {
      printf("%s\n", "small-endian");
    } else {
      printf("%s\n", "unknown");
    }
  }

  return 0;
}
