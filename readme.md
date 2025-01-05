# Web Server Project

## Overview

This project is a web server written in C that can serve various types of files including HTML, CSS, JavaScript, images (PNG), and music (MP3). It also includes a basic database that logs all files retrieved by the server.

## Features

- **Serve HTML Files**: Handles serving HTML files.
- **Serve CSS Files**: Handles serving CSS files.
- **Serve JavaScript Files**: Handles serving JavaScript files.
- **Serve PNG Images**: Handles serving PNG image files.
- **Serve MP3 Music Files**: Handles serving MP3 music files.
- **Logging**: Logs all file retrievals in a SQLite database.

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

## Installation

1. **Clone the repository**:
    ```sh
    git clone https://github.com/yourusername/web-server-project.git
    cd web-server-project
    ```

2. **Install dependencies**:
    ```sh
    sudo apt-get install build-essential sqlite3
    ```

## Usage

1. **Compile the project**:
    ```sh
    ./compile.sh
    ```

2. **Run the application**:
    ```sh
    ./main
    ```

## Contributing

Contributions are welcome! Please fork the repository and submit a pull request for any improvements or bug fixes.

## License

This project is licensed under the MIT License. See the LICENSE file for details.

## Contact

For any inquiries or support, please contact [chirieacandrei@proton.me](mailto:chirieacandrei@proton.me).
