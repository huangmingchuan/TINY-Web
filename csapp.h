#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

#define RIO_BUFSIZE 8192
#define MAXLINE 8192
#define MAXBUF 8192
#define LISTENQ 1024

typedef struct sockaddr SA;

typedef struct {
    int rio_fd;
    int rio_cnt;
    char *rio_bufptr;
    char rio_buf[RIO_BUFSIZE];
} rio_t;


struct hostent *Gethostbyname(const char *name);
struct hostent *Gethostbyaddr(const char *addr, int len, int type);

void dns_error(char *msg);

void unix_error(char *msg);

void app_error(char *msg);

int open_clientfd(char *hostname, int port);

int open_listenfd(int port);

int Open_clientfd(char *hostname, int port);

int Open_listenfd(int port);

void rio_readinitb(rio_t *rp, int fd);

void Rio_readinitb(rio_t *rp, int fd);

char *Fgets(char *ptr, int n, FILE *stream);

ssize_t rio_writen(int fd, void *buf, size_t n);

void Rio_writen(int fd, void *buf, size_t n);

ssize_t rio_readlineb(rio_t *rp, void *buf, size_t maxlen);

ssize_t Rio_readlineb(rio_t *rp, void *buf, size_t maxlen);

void Fputs(const char *ptr, FILE *stream);

void Close(int fd);

int Accept(int s, struct sockaddr *addr, socklen_t *len);

int Open(const char *pathname, int flags, mode_t mode);

void *Mmap(void *addr, size_t len, int port, int flags, int fd, off_t offet);

void Munmap(void *start, size_t length);

pid_t Fork(void);
