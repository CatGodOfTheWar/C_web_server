#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <time.h>

void logs(int PORT, char *file)
{
  sqlite3 *db;
  char *errMsg;
  int fp;
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  char *create;
  char *add;
  char *date;
  char *time;
  // We allocate memory
  create = (char *)calloc(300, sizeof(char));
  add = (char *)calloc(200, sizeof(char));
  date = (char *)calloc(10, sizeof(char));
  time = (char *)calloc(10, sizeof(char));
  // We convert our date and time in a string
  sprintf(date, "%d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
  sprintf(time, "%d:%02d:%02d", tm.tm_hour, tm.tm_min, tm.tm_sec);
  // We create a string with sql code
  strcpy(create, "CREATE TABLE IF NOT EXISTS LOGS( "
                 "id         INTEGER    PRIMARY KEY AUTOINCREMENT,"
                 "log_date   DATE        NOT NULL,"
                 "log_hour   TIME        NOT NULL,"
                 "port       INT         NOT NULL,"
                 "data       VARCHAR(50) NOT NULL )");

  // We open the db
  fp = sqlite3_open("log_data.db", &db);
  // We verify if databse was opened
  if (fp)
  {
    fprintf(stderr, "Can't open the database : ", sqlite3_errmsg(db));
  }
  else
  {
    fprintf(stdout, "Opened databse successfully \n");
  }
  // We execute the sql code
  fp = sqlite3_exec(db, create, NULL, 0, &errMsg);
  free(create);
  // We verify if table was created
  if (fp != SQLITE_OK)
  {
    fprintf(stderr, "SQL error : %s\n", errMsg);
    sqlite3_free(errMsg);
  }
  else
  {
    fprintf(stdout, "Table created successfully\n");
  }
  // We create a string with sql code
  sprintf(add, "INSERT INTO LOGS (log_date , log_hour , port , data)"
               "VALUES ('%s' , '%s' , '%d' , '%s' );",
          date, time, PORT, file);

  free(date);
  free(time);
  // We execute the sql code
  fp = sqlite3_exec(db, add, NULL, 0, &errMsg);
  free(add);
  // We verify if records are created
  if (fp != SQLITE_OK)
  {
    fprintf(stderr, "SQL error: %s\n", errMsg);
  }
  else
  {
    fprintf(stdout, "Records created successfully\n");
  }
  // close
  sqlite3_close(db);
}
