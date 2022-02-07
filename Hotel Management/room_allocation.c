//show the user differnet room types
// ask user the room type..
// show the rooms available in room type
// return the allocated room

#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"
#include "ANSI-color-codes.h"

int show_room_types(int *data, int argc, char **argv, char **azColName){


    for(int i = 0; i<argc; i++){
        printf("%d : %s",(*data), argv[i] ? argv[i] : "NULL");
        (*data) += 1;
   }

   printf("\n");

   return 0;
}

int show_room_numbers(int *data, int argc, char **argv, char **azColName){


    for(int i = 0; i<argc; i++){
        printf("%s ,", argv[i] ? argv[i] : "NULL");
   }

   return 0;
}

int get_room_allocated(sqlite3* db){

    char *zErrMsg = 0;
    int rc;
    char *sql;

    int room_type = 1;

    printf( UCYN" ROOM Types in Hotel : \n" );

    // Select All distinct room types
    sql = "SELECT DISTINCT \"Room Type\" from Rooms";
    // Execute SQL statement
    rc = sqlite3_exec(db, sql, show_room_types, &room_type, &zErrMsg);

    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
   }

    printf("Select room types from above : ");
    scanf("%d",&room_type);
    printf("Showing Available rooms for selected type ... \n");

    switch(room_type){

    case 1:
        sql = "SELECT \"Room Number\" from Rooms \
               WHERE \"Room Type\" = \"1 Seater\" \
               AND \
               Allocated = 0";
        break;

    case 2:
        sql = "SELECT \"Room Number\" from Rooms \
               WHERE \"Room Type\" = \"1 Seater\" \
               AND \
               Allocated = 0";
        break;

    case 3:
        sql = "SELECT \"Room Number\" from Rooms \
               WHERE \"Room Type\" = \"1 Seater\" \
               AND \
               Allocated = 0";
        break;

    default:
        sql = "SELECT * from Rooms";
        break;
    }

    // Execute SQL statement
    rc = sqlite3_exec(db, sql, show_room_numbers, 0, &zErrMsg);
    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
   }

    printf("\n");
    printf("Select required room from above : ");
    scanf("%d",&room_type);

    return room_type;


}



int main() {
    sqlite3 *db;
    int rc;
    int room_no_given;
    const char* data = "";

   // Open the database
   rc = sqlite3_open("Hotel_Management_System.db", &db);

   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
   }

   room_no_given = get_room_allocated(db);

    printf("The room allocated is  : %d",room_no_given);


   sqlite3_close(db);
   return 0;
}
