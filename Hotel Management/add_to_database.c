#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"
#include <string.h>

#include "people_details.h"

void do_nothing(int *data, int argc, char **argv, char **azColName){

}

void add_to_database(sqlite3 *db, struct Person *person ){
    char *zErrMsg = 0;
    int rc;
    char sql[4000];

    int id_type = 1;
    printf("Allowed ID Types in Hotel : \n");

    // Select All distinct room types
    snprintf(sql,4000,"INSERT INTO People \
                        Values (\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",%d,%d,\"%s\")",
             person->name,
             person->address,
             person->phonenumber,
             person->transitdetails,
             person->checkin,
             person->checkout,
             person->room_no_given,
             person->id_type,
             person->uid);

    // Execute SQL statement
    rc = sqlite3_exec(db, sql, do_nothing,0, &zErrMsg);

    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
   }

   snprintf(sql,4000,"UPDATE Rooms \
                      SET Allocated = 1 \
                      WHERE \"Room Number\" = %d",
             person->room_no_given);

    // Execute SQL statement
    rc = sqlite3_exec(db, sql, do_nothing,0, &zErrMsg);

    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
   }

}
