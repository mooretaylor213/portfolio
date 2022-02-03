/* Example TCP Client Program.
 * Covered in Course - Computer Networking
*/


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

#define SERVER_PORT 5432
#define MAX_LINE 256

int
main(int argc, char *argv[])
{
    struct sockaddr_in sin;
    char buf[MAX_LINE];
    char *host;
    struct hostent *hp;
    int s;
    size_t len;

    /* "get" host's name from command line */
    if (argc == 2) {
        host = argv[1];
    } else {
        err(EXIT_FAILURE, "usage: simplex-talk host\n");
    }

    /* translate host name into peer's IP address */
    hp = gethostbyname(host);
    if (hp == NULL) {
        err(EXIT_FAILURE, "simplex-talk: unknown host: %s\n", host);
    }

    /* build address data structure */
    memset(&sin, '\0', sizeof sin);
    sin.sin_family = AF_INET;
    memcpy((char *)&sin.sin_addr, hp->h_addr, hp->h_length);
    sin.sin_port = htons(SERVER_PORT);

    /* active open */
    if ((s = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
        err(EXIT_FAILURE, "simplex-talk: socket");
    }

    if (connect(s, (struct sockaddr *)&sin, sizeof sin) < 0) {
        warn("simplex-talk: connect");
        goto done;
    }

    /* main loop: get and send lines of text */
    while (1) {
        memset(buf, '\0', sizeof buf);
        fgets(buf, sizeof buf, stdin);

        if (strncmp(buf, "QUIT\n", sizeof buf) == 0)
            goto done;

        len = strnlen(buf, sizeof buf);
        send(s, buf, len, 0);
    }

    done:
    close(s);

    return EXIT_SUCCESS;
}
