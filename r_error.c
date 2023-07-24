#include <stdio.h>
#include <string.h>
#include <unistd.h>

char *response;
int response_length;
#define ERROR_MSG "HTTP/1.1 404 Not Found\nContent-Type: text/plain\nContent-Length: 14\n\nPage not found!"

void R_ERROR(int socket)
{
    response = ERROR_MSG;
    response_length = strlen(response);
    write(socket, response, response_length);
}