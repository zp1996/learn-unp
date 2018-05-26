#include "stdio.h"
#include "unp.h"

int ipv4_inet_pton(int family, const char *strptr, void *addrptr) {
  if (family == AF_INET) {
    struct in_addr in_val;

    if (inet_aton(strptr, &in_val)) {
      memcpy(addrptr, &in_val, sizeof(struct in_addr));
      return 1;
    }

    return 0;
  }
  errno = EAFNOSUPPORT;
  return -1;
}

const char* ipv4_inet_ntop(int family, const void *addrptr, char *strptr, size_t len) {
  const u_char *p = (const u_char *) addrptr;
  if (family == AF_INET) {
    char temp[INET_ADDRSTRLEN];

    printf("%d.%d.%d.%d\n", p[0], p[1], p[2], p[3]);

    if (strlen(temp) >= len) {
      errno = ENOSPC;
      return NULL;
    }
    strcpy(strptr, temp);

    return strptr;
  }

  errno = EAFNOSUPPORT;
  return NULL;
}

int main() {
  struct sockaddr_in servaddr;

  if (ipv4_inet_pton(AF_INET, "0.0.0.0", &servaddr.sin_addr) <=0) {
    err_quit("ipv4_inet_pton error");
  } else {
    printf("%s\n", "to addrptr success");
  }

  char *str;
  ipv4_inet_ntop(AF_INET, &servaddr.sin_addr, &str, INET_ADDRSTRLEN);
}
