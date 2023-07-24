#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <fcntl.h>
#include "INCLUDE/w_error.h"
#include "INCLUDE/r_error.h"

#define BUFFER_SIZE 4096
#define OK_MSG "HTTP/1.1 200 OK\nContent-Type: text/html\n\n"

void handle_html(int socket, char *route)
{
    char *response;
    int response_length;

    if (strcmp(route, "/") == 0)
    {
        FILE *fp;
        char *buffer = (char *)calloc(BUFFER_SIZE, sizeof(char));
        int n;
        // We open the HTML file to be read
        fp = fopen("HTML/index.html", "r");
        if (fp == NULL)
        {
            R_ERROR(socket);
            return;
        }
        // We respond to the server with a Ok message
        response = OK_MSG;
        response_length = strlen(response);
        write(socket, response, response_length);
        // We write doctype to your HTML file for browser to know that we use HTML5
        char *doctype = "<!DOCTYPE html>";
        n = write(socket, doctype, strlen(doctype));
        ERROR(n);
        // We write the Header tag that contains the link with our ICONS and CSS
        char *header_file = "<html>\n<head>\n<title>Home</title>\n <link rel=\"stylesheet\" type=\"text/css\" href=\"style.css\">    <link rel=\"icon\" type=\"image/x-icon\" href=\"Home_icon.png\">\n  </head>\n<body>\n";
        n = write(socket, header_file, strlen(header_file));
        ERROR(n);
        // we write the HTML file
        while (fgets(buffer, BUFFER_SIZE, fp) != NULL)
        {
            n = write(socket, buffer, strlen(buffer));
            ERROR(n);
        }
        // We write the Script tag that conatins the link with our JS file
        char *bottom_file = "<script src=\"function.js\"></script>\n</body>\n</html>\n";
        n = write(socket, bottom_file, strlen(bottom_file));
        ERROR(n);
        // Close and free the memory
        fclose(fp);
        free(buffer);
    }
    else if (strcmp(route, "/account") == 0)
    {
        FILE *fp;
        char *buffer = (char *)calloc(BUFFER_SIZE, sizeof(char));
        int n;
        // We open the HTML file to be read
        fp = fopen("HTML/account.html", "r");
        if (fp == NULL)
        {
            R_ERROR(socket);
            return;
        }

        // We respond to the server with a Ok message
        response = OK_MSG;
        response_length = strlen(response);
        write(socket, response, response_length);
        // We write doctype to your HTML file for browser to know that we use HTML5
        char *doctype = "<!DOCTYPE html>";
        n = write(socket, doctype, strlen(doctype));
        ERROR(n);
        // We write the Header tag that contains the link with our ICONS and CSS
        char *header_file = "<html>\n<head>\n<title>Account</title>\n<link rel=\"stylesheet\" type=\"text/css\" href=\"styleAccount.css\">\n  <link rel=\"icon\" type=\"image/x-icon\" href=\"Account_icon.png\">\n   <link rel=\"preconnect\" href=\"https://fonts.gstatic.com\">\n    <link href=\"https://fonts.googleapis.com/css2?family=Montserrat:wght@300;400;500&display=swap\" rel=\"stylesheet\">\n  </head>\n<body>\n";
        n = write(socket, header_file, strlen(header_file));
        ERROR(n);
        // we write the HTML file
        while (fgets(buffer, BUFFER_SIZE, fp) != NULL)
        {
            n = write(socket, buffer, strlen(buffer));
            ERROR(n);
        }
        // We write the Script tag that conatins the link with our JS file
        char *bottom_file = "<script src=\"functionAccount.js\"></script>\n</body></html>\n";
        n = write(socket, bottom_file, strlen(bottom_file));
        ERROR(n);
        // Close and free the memory
        fclose(fp);
        free(buffer);
    }
    else if (strcmp(route, "/tic_tac_toe") == 0)
    {
        FILE *fp;
        char *buffer = (char *)calloc(BUFFER_SIZE, sizeof(char));
        int n;
        // We open the HTML file to be read
        fp = fopen("HTML/tic_tac_toe.html", "r");
        if (fp == NULL)
        {
            R_ERROR(socket);
            return;
        }
        // We respond to the server with a Ok message
        response = OK_MSG;
        response_length = strlen(response);
        write(socket, response, response_length);
        // We write doctype to your HTML file for browser to know that we use HTML5
        char *doctype = "<!DOCTYPE html>";
        n = write(socket, doctype, strlen(doctype));
        ERROR(n);
        // We write the Header tag that contains the link with our ICONS and CSS
        char *header_file = "<html>\n<head>\n<title>Game</title>\n<link rel=\"stylesheet\" type=\"text/css\" href=\"styleGame.css\">\n  <link rel=\"icon\" type=\"image/x-icon\" href=\"Icon_game.png\">\n <script src=\"https://kit.fontawesome.com/bc47cdb13d.js\" crossorigin=\"anonymous\"></script>\n </head>\n<body>\n";
        n = write(socket, header_file, strlen(header_file));
        ERROR(n);
        // we write the HTML file
        while (fgets(buffer, BUFFER_SIZE, fp) != NULL)
        {
            n = write(socket, buffer, strlen(buffer));
            ERROR(n);
        }
        // We write the Script tag that conatins the link with our JS file
        char *bottom_file = "<script src=\"functionGame.js\"></script>\n</body>\n</html>\n <script src=\"musicplayer.js\"></script>\n </body>\n</html>\n";
        n = write(socket, bottom_file, strlen(bottom_file));
        ERROR(n);
        // Close and free the memory
        fclose(fp);
        free(buffer);
    }
    else
    {
        R_ERROR(socket);
    }
}
