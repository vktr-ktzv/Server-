#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "errorprocesing.h"

int main ()
{   
    int serverfd = Socket (AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in adr = {0};
    adr.sin_family  = AF_INET;
    adr.sin_port = htons(34543);

    Bind (serverfd, (struct  sockaddr*) &adr, sizeof(adr));

    Listen (serverfd, 5);

    socklen_t adrlen = sizeof(adr);
    int fd = Accept(serverfd, (struct  sockaddr*) &adr, &adrlen);

    ssize_t nread;
    char buf[256];
    nread = read (fd, buf, 256);

    if (nread == -1)
    {
        perror ("read failed");
        exit(EXIT_FAILURE);
    }

    if (nread == 0)
    {
        printf ("End of file\n");
    }
    write (STDOUT_FILENO, buf, nread);

    write (fd, buf, nread); //answer to client

    sleep(15);

    close (fd);
    close (serverfd);
    return 0;
}