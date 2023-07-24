#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <fcntl.h>
#include "INCLUDE/w_error.h"
#include "INCLUDE/r_error.h"

#define BUFFER_SIZE 4096
#define OK_MSG_CSS "HTTP/1.1 200 OK\nContent-Type: text/css\n\n"
#define OK_MSG_JS "HTTP/1.1 200 OK\nContent-Type: text/javascript\n\n"

void css_js(int socket, char *name)
{
    char *response;
    int response_length;

    // Location to the folder with CSS/JS files
    char var[5];
    strcpy(var, "css");
    char location[30];
    char *file_type = strstr(name, var);
    if (file_type != NULL)
    {
        char location[30] = "CSS";
        response = OK_MSG_CSS;
    }
    else
    {
        char location[30] = "JS";
        response = OK_MSG_JS;
    }
    char *result = strcat(location, name);
    FILE *fp;
    char *css_buffer = (char *)calloc(BUFFER_SIZE, sizeof(char));
    int n;
    // We open the CSS file to be read
    fp = fopen(result, "r");
    if (fp == NULL)
    {
        R_ERROR(socket);
        return;
    }
    // We respond to the server with a Ok message
    response_length = strlen(response);
    write(socket, response, response_length);
    // we write the CSS file
    while (fgets(css_buffer, BUFFER_SIZE, fp) != NULL)
    {
        n = write(socket, css_buffer, strlen(css_buffer));
        ERROR(n);
    }
    // Close and free the memory
    fclose(fp);
    free(css_buffer);
}