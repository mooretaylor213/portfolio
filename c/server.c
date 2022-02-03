#include <sys/socket.h>
#include <sys/types.h>

#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>

#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SERVER_PORT  4225
#define MAX_PENDING  5
#define MAX_LINE     256

int
main(void)
{
    struct sockaddr_in sin;
    char buf[MAX_LINE];
    socklen_t addr_len;
    int buf_len;
    int s;
    int new_s;

    /* build address data structure */
    memset(&sin, '\0', sizeof sin);
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(SERVER_PORT);

    /* setup passive open */
    if ((s = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
        errx(EXIT_FAILURE, "simplex-talk: socket");
    }

    if ((bind(s, (struct sockaddr *)&sin, sizeof sin )) < 0) {
        warnx("simplex-talk: bind");
        goto done;
    }

    listen(s, MAX_PENDING);

     /* wait for connection (blocking), then receive and print text */
    while(1) {
        if ((new_s = accept(s, (struct sockaddr *)&sin, &addr_len)) < 0) {
            warnx("simplex-talk: accept");
            goto done;
        }

        memset(buf, '\0', sizeof buf);
        if ((buf_len = recv(new_s, buf, (sizeof buf) - 1, 0)) > 0)
            puts(buf);

        close(new_s);

        if (strncmp(buf, "QUIT\n", sizeof buf) == 0)
            goto done;
    }

    done:
    close(s);

    return EXIT_SUCCESS;
}
