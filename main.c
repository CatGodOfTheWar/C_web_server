#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sqlite3.h>
#include <time.h>
#include "INCLUDE/create.h"
#include "INCLUDE/handle_html.h"
#include "INCLUDE/w_error.h"
#include "INCLUDE/r_error.h"
#include "INCLUDE/image_music.h"
#include "INCLUDE/css_js.h"
#include "INCLUDE/logs.h"

//port in use
int PORT = 6969;

typedef struct routing
{
    char img[5];
    char js[5];
    char css[5];
    char music[5];
    char *img_route;
    char *js_route;
    char *css_route;
    char *music_route;
    char *route_start;
    char *route_end;
    int route_length;
} routing;

int main(int argc, char **argv)
{
    int incercari = 3;
    int initial = 1;
    int server_fd;
    int new_socket;
    int valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    size_t bufferSize = 1024;
    char *buffer = (char *)calloc(bufferSize, sizeof(char));
    routing *r;
    r = (routing *)calloc(1, sizeof(routing));
    strcpy(r[0].img, "png");
    strcpy(r[0].css, "css");
    strcpy(r[0].js, "js");
    strcpy(r[0].music, "mp3");
    
    // The function that will create our local web server 
    server_fd = create(PORT);

    // wee listen for conection -> max 100
    if (listen(server_fd, 100) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Conecting to a client and serving the right file 
    while (1)
    {
        // Acepting conection to a client 
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        // Reading the browser GET request from your server
        valread = read(new_socket, buffer, 1024);
        printf("%s\n", buffer);

        // Extracting the name of the file browser wants from GET request
        r[0].route_start = strstr(buffer, "GET ") + 4;
        r[0].route_end = strstr(r[0].route_start, " HTTP/1.1");
        r[0].route_length = r[0].route_end - r[0].route_start;
        char route[r[0].route_length + 1];
        strncpy(route, r[0].route_start, r[0].route_length);
        route[r[0].route_length] = '\0';
        r[0].img_route = strstr(route, r[0].img);
        r[0].css_route = strstr(route, r[0].css);
        r[0].js_route = strstr(route, r[0].js);
        r[0].music_route = strstr(route, r[0].music);

        // Deciding the file type and using the right file for concatenating
        // And in parallel saving what file was request on the database  
        if (r[0].img_route != NULL)
        {
            image_music(new_socket, route);
            logs(PORT,route);
        }
        else if (r[0].css_route != NULL)
        {
            css_js(new_socket, route);
            logs(PORT,route);
        }
        else if (r[0].js_route != NULL)
        {
            css_js(new_socket, route);
            logs(PORT,route);
        }
        else if (r[0].music_route != NULL)
        {
            image_music(new_socket, route);
            logs(PORT,route);
        }
        else
        {
            handle_html(new_socket, route);
            logs(PORT,route);
        }

        // Closing
        close(new_socket);
    }
    // Free the memory
    free(buffer);
    free(r);
    return 0;
}
