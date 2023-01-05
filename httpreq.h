#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char* method;
    char* path;
    char* http_version;
} parsed_req;

void req_path(char* request, char* path_buff);