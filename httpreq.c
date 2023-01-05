#include "httpreq.h"

void req_path(char* request, char* path_buff){
    char *space = strstr(request, " ");
    int space_position = space - request;
    printf("%d\n", space_position);
    int i = space_position + 1;
    int cont = 0;
    char character = request[i];
    printf("Character [%d] = %c\n", cont, character);
    while(character != '\0' && character != ' '){
        path_buff[cont] = character;
        cont++;
        i++;
        character = request[i];
        printf("Character [%d] = %c\n", cont, character);
    }
    path_buff[cont] = '\0';
}

void req_method(char* request, char* method_buff){
    char *space = strstr(request, " ");
    int space_position = space - request;
    printf("%d\n", space_position);
    strncpy(method_buff, request, space_position);
}

void parse_request(char* request){
   printf( "Original string: %s\n", request);
   // Extract the first token
   char * token1 = strtok(request, "\n");
   char * token2 = strtok(NULL, "\n");
   char * token3 = strtok(NULL, "\n");
   char * token4 = strtok(NULL, "\n");
   char * token5 = strtok(NULL, "\n");
   char * token6 = strtok(NULL, "\n");
   char * token7 = strtok(NULL, "\n");
   char * token8 = strtok(NULL, "\n");
   char * token9 = strtok(NULL, "\n");
   char * token10 = strtok(NULL, "\n");
   parsed_req* req = malloc(strlen(token1));
   req->method = strtok(token1, " ");
   req->path = strtok(NULL, " ");
   req->http_version = strtok(NULL, " ");
   printf("METHOD: \"%s\"\nPATH: \"%s\"\nHTTP VERSION: \"%s\"\n",req->method,
    req->path, req->http_version);
}

int main(){
    char* s = "GET /patricia_sosa HTTP/1.1\nHost: 127.0.0.1:1575\nUser-Agent: Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:107.0) Gecko/20100101 Firefox/107.0\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,*/*;q=0.8\nAccept-Language: en-US,en;q=0.5\nAccept-Encoding: gzip, deflate, br\nConnection: keep-alive\nUpgrade-Insecure-Requests: 1\nSec-Fetch-Dest: document\nSec-Fetch-Mode: navigate\nSec-Fetch-Site: none\nSec-Fetch-User: ?1";
    char* s_copied = malloc(strlen(s));
    strcpy(s_copied, s);
    printf("%s\n", s);
    char* path = malloc(500);
    req_path(s, path);
    printf("PATH: \"%s\"\n", path);
    free(path);
    char* method = malloc(500);
    req_method(s, method);
    printf("METHOD: \"%s\"\n", method);
    parse_request(s_copied);


}