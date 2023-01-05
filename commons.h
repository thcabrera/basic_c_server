#ifndef _COMMON_H_
#define _COMMON_H_

#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <inttypes.h>
#include <arpa/inet.h>
#include <stdarg.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <netdb.h>

#define MAXLINE 4096
#define SERVER_PORT 9990
#define SA struct sockaddr

void err_n_die(const char *fmt, ...);

#endif