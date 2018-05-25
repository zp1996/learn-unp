#include <stdio.h>
#include <time.h>
#include <unp.h>

/**
 * 服务端生成,请求本机的日期服务接口
 */
int main(int argc, char **argv) {
  int listenfd, connfd;
  struct sockaddr_in servaddr;
  char buff[MAXLINE];
  time_t ticks;           // 声明一个日历存储类型
  // 创建一个TCP套接字
  listenfd = Socket(AF_INET, SOCK_STREAM, 0);

  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  // INADDR_ANY为0.0.0.0, htonl将ip地址进行端序转换,在头文件netinet/in.h中定义
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(13);
  // 将本地地址与日期协议套接口捆绑
  Bind(listenfd, (SA *) &servaddr, sizeof(servaddr));
  // 把套接字转换成监听套接字,外来链接可在该套接字上由内核接受
  Listen(listenfd, LISTENQ);

  printf("listen success\n");

  while (1) {
    // accept之后进程睡眠,知道出现连接时
    connfd = Accept(listenfd, (SA *) NULL, NULL);
    ticks = time(NULL);
    snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
    // 写入已连接描述符
    Write(connfd, buff, strlen(buff));
    // 关闭连接
    Close(connfd);
  }

}
