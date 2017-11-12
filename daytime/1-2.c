#include <stdio.h>
#include <unp.h>

/**
 * 客户端请求某ip地址的日期服务接口
 */
int main(int argc, char **argv) {
  int sockfd, n;
  char recvline[MAXLINE + 1];
  struct sockaddr_in servaddr;

  if (argc != 2) {
    err_quit("usage: ./1-2 <IPAddress>");
  }
  // 创建一个tcp套接字
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    err_sys("socket error");
  }
  // 指定目的地址和端口，ip可以从http://tf.nist.gov/tf-cgi/servers.cgi找
  bzero(&servaddr, sizeof(servaddr));     // bzero 用于清除结构
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(13);
  if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
    err_quit("inet_pton error for %s", argv[1]);
  }
  // 进行socket连接
  if (connect(sockfd, (SA *) &servaddr, sizeof(servaddr)) < 0) {
    err_quit("connect error");
  }

  while ((n = read(sockfd, recvline, MAXLINE)) > 0) {
    recvline[n] = 0;
    if (fputs(recvline, stdout) == EOF) {
      err_sys("fputs error");
    }
  }
  if (n < 0) {
    err_sys("read error");
  }

  exit(0);
}
