# Web Server Project

## Overview
This project is a web server written in C that can serve various types of files including HTML, CSS, JavaScript, images (PNG), and music (MP3). It also includes a basic database that logs all files retrieved by the server.

## Features
- Serve HTML files
- Serve CSS files
- Serve JavaScript files
- Serve PNG images
- Serve MP3 music files
- Log all file retrievals in a SQLite database

## Project Structure
```plaintext
.
├── compile.sh
├── create.c
├── create.o
├── CSS/
│   ├── style.css
│   ├── styleAccount.css
│   ├── styleGame.css
├── css_js.c
├── css_js.o
├── handle_html.c
├── handle_html.o
├── HTML/
│   ├── account.html
│   ├── index.html
│   ├── tic_tac_toe.html
├── image_music.c
├── image_music.o
├── IMG/
├── INCLUDE/
│   ├── create.h
│   ├── css_js.h
│   ├── handle_html.h
│   ├── image_music.h
│   ├── logs.h
│   ├── r_error.h
│   ├── w_error.h
├── JS/
│   ├── function.js
│   ├── functionAccount.js
│   ├── functionGame.js
│   ├── musicplayer.js
├── logs.c
├── logs.o
├── main
├── main.c
├── MUSIC/
├── r_error.c
├── r_error.o
├── readme.md
├── w_error.c
├── w_error.o
```

## File Descriptions
- **compile.sh**: Shell script to compile the C source files and link them into an executable.
- **create.c**: Contains the function to create a socket and bind it to a port.
- **css_js.c**: Handles serving CSS and JavaScript files.
- **handle_html.c**: Handles serving HTML files.
- **image_music.c**: Handles serving image and music files.
- **logs.c**: Logs file retrievals to a SQLite database.
- **main.c**: The main entry point of the server application.
- **r_error.c**: Handles 404 errors.
- **w_error.c**: Handles write errors.

## HTML Files
- **HTML/account.html**: Account page.
- **HTML/index.html**: Home page.
- **HTML/tic_tac_toe.html**: Tic Tac Toe game page.

## CSS Files
- **CSS/style.css**: General styles.
- **CSS/styleAccount.css**: Styles for the account page.
- **CSS/styleGame.css**: Styles for the Tic Tac Toe game page.

## JavaScript Files
- **JS/function.js**: Placeholder for general JavaScript functions.
- **JS/functionAccount.js**: Placeholder for account page JavaScript functions.
- **JS/functionGame.js**: JavaScript for the Tic Tac Toe game.
- **JS/musicplayer.js**: JavaScript for the music player.

## Headers
- **INCLUDE/create.h**: Header for `create.c`.
- **INCLUDE/css_js.h**: Header for `css_js.c`.
- **INCLUDE/handle_html.h**: Header for `handle_html.c`.
- **INCLUDE/image_music.h**: Header for `image_music.c`.
- **INCLUDE/logs.h**: Header for `logs.c`.
- **INCLUDE/r_error.h**: Header for `r_error.c`.
- **INCLUDE/w_error.h**: Header for `w_error.c`.

## How to Compile
To compile the project, run the following command:
```sh
./compile.sh
```

## How to Run
After compiling, the server can be started with:
```sh
./main
```

## Contributing
Contributions are welcome! Please fork the repository and submit a pull request for any improvements or bug fixes.

## License
This project is licensed under the MIT License. See the LICENSE file for details.

## Contact
For any inquiries or support, please contact [chirieacandrei@proton.me](mailto:chirieacandrei@proton.me).
