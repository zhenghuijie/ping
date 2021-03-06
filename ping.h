#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in_systm.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <unistd.h>
#include <stddef.h>
#include <ifaddrs.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <pthread.h>
#include <assert.h>

#define BUFSIZE 1024

char sendbuf[BUFSIZE];

int datalen;
char *host;
int nsent;
pid_t pid;
int sockfd;
int verbose;

void init_v6(void);
void proc_v4(char *, ssize_t, struct msghdr *, struct timeval *);
void proc_v6(char *, ssize_t, struct msghdr *, struct timeval *);
void send_v4(void);
void send_v6(void);
void readloop(void);
void sig_alrm(int);
void tv_sub(struct timeval *, struct timeval*);


struct proto{
	void (*fproc)(char *, ssize_t, struct msghdr *, struct timeval *);
	void (*fsend)(void);
	void (*finit)(void);
	struct sockaddr *sasend;
	struct sockaddr *sarecv;
	socklen_t salen;
	int icmpproto;
}*pr;


















