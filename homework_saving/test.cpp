#include <stdio.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#define MAX_LINE 32

/* readline() - read a line (ended with '\n') from a file descriptor
 *	. return the number of chars read, -1 on errors
 */
int readline(SOCKET fd, char *ptr, int maxlen) {
    int	n, rc;
    char	c;

    for (n = 1; n < maxlen; n++) {
        if ((rc = recv(fd, &c, 1, 0)) == 1) {
            *ptr++ = c;
            if (c == '\n') break;
        } else if (rc == 0) {
            if (n == 1) return (0);	/* EOF, no data read	*/
            else break;		/* EOF, some data read	*/
        } else return (-1);		/* Error		*/
    }
    *ptr = 0;
    return (n);
}

int tcp_open_client(char *host, char *port) {
    SOCKET sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    /* Initialize Winsock */
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        printf("Failed to initialize Winsock.\n");
        return -1;
    }

    /* Open a TCP socket (an Internet stream socket). */
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Failed to create socket.\n");
        WSACleanup();
        return -1;
    }

    server = gethostbyname(host);
    if (server == NULL) {
        printf("Failed to get host.\n");
        WSACleanup();
        return -1;
    }

    /* Fill in "serv_addr" with the address of the server */
    memset((char *)&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy((char *)&serv_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(port));

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Failed to connect.\n");
        WSACleanup();
        return -1;
    }

    return sockfd;
}

int main(int argc, char *argv[]) {
    WSADATA wsaData;
    int iResult;
    
    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed: %d\n", iResult);
        return 1;
    }
    
    SOCKET sockfd;
    int len, ret;
    char buf[MAX_LINE];

    sockfd = tcp_open_client(argv[1], argv[2]);
    while (1) {
        printf(
            "test ouput\n"
        );
        if ((ret = recv(sockfd, buf, sizeof(buf), 0)) <= 0) break;
        printf("%s", buf);
        if (fgets(buf, MAX_LINE, stdin) == NULL) break;
        len = strlen(buf);
        send(sockfd, buf, len, 0);
        if (strncmp(buf, "QUIT", 4) == 0) break;
    }
    printf(
        "test end\n"
    );
    closesocket(sockfd);
    WSACleanup();
    return 0;
}