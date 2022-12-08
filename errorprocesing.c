#include "errorprocesing.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int Socket (int domain, int type, int protocol)
{
    int res = socket (domain, type, protocol);

    if (res == -1)
    {
        perror("socket failed");
        exit (EXIT_FAILURE);
    }

    return res;
}

void Bind(int sockfd, const struct  sockaddr *addr, socklen_t addrlen)
{
    int res = bind (sockfd, addr, addrlen);

    if (res == -1)
    {
        perror("Bind failed");
        exit (EXIT_FAILURE);        
    }
}

void Listen (int socketfd, int backlog)
{
    int res = listen (socketfd, backlog);
    if (res == -1)
    {
        perror ("Listen lailed\n");
        exit (EXIT_FAILURE);
    }
}

int Accept (int sockfd, struct sockaddr* addr, socklen_t *addrlen)
{
    int res = accept (sockfd, addr, addrlen);
    if (res == -1)
    {
        perror("accept failed");
        exit (EXIT_FAILURE);
    }

    return res;
}

void Connect (int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
    int res = connect(sockfd, addr, addrlen);

    if (res == -1)
    {
        perror("connect failed");

        exit (EXIT_FAILURE);
    }
}

void Inet_pton (int af, const char *src, void *dst)
{
    int res = inet_pton (af, src, dst);

    if (res == 0)
    {
        printf ("inet_pton failed: src does not contain a character"
                "string representing a valid network address in the specified"
                " address family\n");
        exit (EXIT_FAILURE);
    }

    if (res == -1)
    {
        perror ("inet_pton failed");
        exit(EXIT_FAILURE);
    }
}