#include "commons.h"

int main(){

    int listenfd, connfd, n;
    struct sockaddr_in serveraddr;
    uint8_t buff[MAXLINE +1 ];
    uint8_t recvline[MAXLINE + 1];

    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        err_n_die("socket_error.");
    
    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    inet_aton("127.0.0.1", &serveraddr.sin_addr.s_addr);
    serveraddr.sin_port = SERVER_PORT;
    if ((bind(listenfd, (SA *) &serveraddr, sizeof(serveraddr))) < 0)
        err_n_die("bind error.");
    
    if ((listen(listenfd, 10)) < 0)
        err_n_die("listen error.");
    
    for( ; ; ){

        struct sockaddr_in addr;
        socklen_t addr_len = sizeof(struct sockaddr_in);
        char client_address [MAXLINE + 1];
        printf("Waiting for a connection on port %d\n", SERVER_PORT);
        fflush(stdout);
        // ultimos dos arg NULL NULL son para recuperar
        // address de la conexion
        connfd = accept(listenfd, (SA *) &addr, &addr_len);

        inet_ntop(AF_INET, &addr, client_address, MAXLINE);
        printf("CLIENT ADDRESS: %s\n", client_address);

        memset(recvline, 0, MAXLINE);
        while((n = read(connfd, recvline, MAXLINE-1)) > 0){
            fprintf(stdout, recvline);
            if (recvline[n - 1] == '\n')
                break;
            memset(recvline, 0, MAXLINE);
        }
        if (n < 0)
            err_n_die("read error.");
        snprintf((char*)buff, sizeof(buff), "HTTP/1.0 409 TODO MAL :(\r\n\r\nHOLA!!");
        write(connfd, (char*)buff,strlen((char*)buff));
        close(connfd);
    }
    
}