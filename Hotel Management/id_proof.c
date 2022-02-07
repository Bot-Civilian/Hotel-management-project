//show the user differnet room types
// ask user the room type..
// show the rooms available in room type
// return the allocated room

#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"
#include <string.h>

int show_id_types(int *data, int argc, char **argv, char **azColName){


    for(int i = 0; i<argc; i++){
        printf("%d : %s",(*data), argv[i] ? argv[i] : "NULL");
        (*data) += 1;
   }

   printf("\n");

   return 0;
}


void update_id_proofs(sqlite3* db,char* id_name, char *uid){

    char *zErrMsg = 0;
    int rc;
    char *sql;

    int id_type = 1;
    printf("Allowed ID Types in Hotel : \n");

    // Select All distinct room types
    sql = "SELECT DISTINCT \"ID Proof Name\" from \"ID Proofs\"";
    // Execute SQL statement
    rc = sqlite3_exec(db, sql, show_id_types, &id_type, &zErrMsg);

    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
   }

    printf("Select ID type from above : ");
    scanf("%d",&id_type);
    printf("Enter UID of selected ID Type : \n");

    scanf("%*c");
    scanf("%[^\n]",uid);
    scanf("%*c");

    switch(id_type){

    case 1:
        strcpy(id_name,"Aadhar");
        break;

    case 2:
        strcpy(id_name,"PAN");
        break;

    case 3:
        strcpy(id_name,"Driving License");
        break;

    case 4:
        strcpy(id_name,"Passport");
        break;

    default:
        break;
    }


}



int main() {
    sqlite3 *db;
    int rc;
    const char* data = "";

    char id_name[16];
    char uid[12];

   // Open the database
   rc = sqlite3_open("Hotel_Management_System.db", &db);

   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
   }

    update_id_proofs(db,id_name,uid);

    printf("%s \n",id_name);
    printf("%s \n",uid);

   sqlite3_close(db);
   return 0;
}

