#include <boost/test/included/unit_test.hpp>
#include <sqlite3.h>

int initDb(sqlite3 *db)
{
    char *sql = "CREATE TABLE COMPANY("
                "ID INT PRIMARY KEY  NOT NULL,"
                "NAME           TEXT NOT NULL,"
                "AGE            INT  NOT NULL,"
                "ADDRESS        TEXT NOT NULL,"
                "SALARY         INT  NOT NULL);";
    return sqlite3_exec(db, sql, NULL, NULL, NULL);
}

BOOST_AUTO_TEST_CASE(db_test)
{
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;

    /* Open database */
    rc = sqlite3_open("test.db", &db);

    initDb(db);

    if (rc)
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return;
    }
    else
    {
        fprintf(stderr, "Opened database successfully\n");
    }

    /* Create SQL statement */
    sql = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "
          "VALUES (1, 'Paul', 32, 'California', 20000.00 ); "
          "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "
          "VALUES (2, 'Allen', 25, 'Texas', 15000.00 ); "
          "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)"
          "VALUES (3, 'Teddy', 23, 'Norway', 20000.00 );"
          "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)"
          "VALUES (4, 'Mark', 25, 'Rich-Mond ', 65000.00 );";

    /* Execute SQL statement */
    auto callback = [](void *a, int b, char **c, char **d)
    { return 0; };
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
    {
        fprintf(stdout, "Records created successfully\n");
    }

    sqlite3_close(db);
}