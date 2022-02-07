#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"
#include <string.h>

#include "people_details.h"
#include "ANSI-color-codes.h"



void get_name(struct Person *person){
        //printf("\t\t########################################################################################################################### \n");

        printf("\n 1. ");
        printf( WHTB UCYN"Please enter your name : \n"reset);
        printf( WHTB RED"\n  > "reset);
        scanf("%[^\n]",person->name);
        scanf("%*c");

}

void get_address(struct Person *person){

    printf( WHT"\n 2. "reset);
    printf( UYEL"Please enter your address : \n"reset);
    printf( CYN"\n  > "reset);
    scanf("%[^\n]",person->address);
    scanf("%*c");
}

void get_phonenumber(struct Person *person){

    printf( WHT"\n 3. "reset);
    printf( UBLU"Please enter your phone number : \n"reset);
    printf( YEL"\n  > "reset);
    scanf( "%[^\n]",person->phonenumber);
    scanf("%*c");
}

void get_transit_details(struct Person *person){

    printf( WHT"\n 4. "reset);
    printf( URED"Please enter your transit details : \n"reset);
    printf( BLU"\n  > "reset);
    scanf("%[^\n]",person->transitdetails);
    scanf("%*c");
}

void get_checkin_time(struct Person *person){

    printf( WHT"\n 5. "reset);
    printf( UWHT"Please enter your check in details DD-MM-YYYY HH:MM:SS : \n"reset);
    printf( GRN"\n  > "reset);
    scanf("%[^\n]",person->checkin);
    scanf("%*c");
}

void get_checkout_time(struct Person *person){
    printf("\n    "reset);
    printf( UWHT"Please enter your check out details DD-MM-YYYY HH:MM:SS : \n"reset);
    printf( GRN"\n  > "reset);
    scanf("%[^\n]",person->checkout);





int show_room_types(int *data, int argc, char **argv, char **azColName){


    for(int i = 0; i<argc; i++){
        printf("\t %d : %s",(*data), argv[i] ? argv[i] : "NULL");
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

    printf( WHT"\n 6. "reset);

    printf( CYN"ROOM Types in Hotel : \n");


    // Select All distinct room types
    sql = "SELECT DISTINCT \"Room Type\" from Rooms";
    // Execute SQL statement
    rc = sqlite3_exec(db, sql, show_room_types, &room_type, &zErrMsg);

    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
   }

    printf( "\t Select room types from above : ");
    scanf("%d",&room_type);
    printf( GRN"\n  > "reset);
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
               WHERE \"Room Type\" = \"2 Seater\" \
               AND \
               Allocated = 0";
        break;

    case 3:
        sql = "SELECT \"Room Number\" from Rooms \
               WHERE \"Room Type\" = \"3 Seater\" \
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
    printf( CYN"Select required room from above : "reset);
    scanf("%d",&room_type);

    return room_type;


}


int show_id_types(int *data, int argc, char **argv, char **azColName){


    for(int i = 0; i<argc; i++){
        printf("\t\t %d : %s",(*data), argv[i] ? argv[i] : "NULL");
        (*data) += 1;
   }

   printf("\n");

   return 0;
}

int update_id_proofs(sqlite3* db,struct Person *person){

    char *zErrMsg = 0;
    int rc;
    char *sql;

    int id_type = 1;
    printf( UBLU"Allowed ID Types in Hotel : \n"reset);

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
    scanf("%[^\n]",person->uid);
    scanf("%*c");

    switch(id_type){

    case 1:
        strcpy(person->id_name,"Aadhar");
        break;

    case 2:
        strcpy(person->id_name,"PAN");
        break;

    case 3:
        strcpy(person->id_name,"Driving License");
        break;

    case 4:
        strcpy(person->id_name,"Passport");
        break;

    default:
        break;
    }

    return id_type;

}
}


