#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <fcntl.h>
#include "INCLUDE/r_error.h"

void image_music(int socket, char *name)
{
    char *response;
    int response_length;
    // Location to the folder with Images/Music files
    char var[5];
    strcpy(var, "png");
    char location[30];
    char *file_type = strstr(name, var);
    if (file_type != NULL)
    {
        char location[30] = "IMG";
    }
    else
    {
        char location[30] = "MUSIC";
    }
    char *result = strcat(location, name);
    FILE *file;
    // We open the Image/music file to be read
    file = fopen(result, "rb");
    if (file == NULL)
    {
        R_ERROR(socket);
        return;
    }
    // We determine de dimension of the music/image file
    fseek(file, 0L, SEEK_END);
    long int size = ftell(file);
    rewind(file);
    // We allocate memory
    char *_buffer = (char *)malloc(size);
    if (_buffer == NULL)
    {
        fclose(file);
        R_ERROR(socket);
        return;
    }
    fread(_buffer, 1, size, file);
    fclose(file);
    // We printf a valid response on the console
    printf("HTTP/1.1 200 OK\r\n");
    printf("Content-Type: image/jpeg\r\n");
    printf("Content-Length: %ld\r\n", size);
    printf("\r\n");
    // Close and free the memory
    write(socket, _buffer, size);
    free(_buffer);
}