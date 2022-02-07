#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"
#include <string.h>


void get_name(char* name){

    printf("Please enter your name : \n");
    scanf("%[^\n]",name);
    scanf("%*c");

}

void get_address(char* address){

    printf("Please enter your address : \n");
    scanf("%[^\n]",address);
    scanf("%*c");
}

void get_phonenumber(char* phonenumber){

    printf("Please enter your phone number : \n");
    scanf("%[^\n]",phonenumber);
    scanf("%*c");
}

void get_transit_details(char* transitdetails){

    printf("Please enter your transit details : \n");
    scanf("%[^\n]",transitdetails);
    scanf("%*c");
}

void get_checkin_time(char* checkin){

    printf("Please enter your check in details DD-MM-YYYY HH:MM:SS : \n");
    scanf("%[^\n]",checkin);
    scanf("%*c");
}

void get_checkout_time(char* checkout){

    printf("Please enter your check out details DD-MM-YYYY HH:MM:SS : \n");
    scanf("%[^\n]",checkout);
    scanf("%*c");
}




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

    printf(" ROOM Types in Hotel : \n");

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


int show_id_types(int *data, int argc, char **argv, char **azColName){


    for(int i = 0; i<argc; i++){
        printf("%d : %s",(*data), argv[i] ? argv[i] : "NULL");
        (*data) += 1;
   }

   printf("\n");

   return 0;
}


int update_id_proofs(sqlite3* db,char* id_name, char *uid){

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

    return id_type;

}



int main(){

    sqlite3 *db;
    int rc;

    char name[200];
    char address[500];
    char phonenumber[10];
    char transitdetails[500];
    char checkin[19];
    char checkout[19];

    int id_type;
    char id_name[16];
    char uid[25];

    int room_no_given;

   // Open the database
    rc = sqlite3_open("Hotel_Management_System.db", &db);

    if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
    }


    get_name(name);
    get_address(address);
    get_phonenumber(phonenumber);
    get_transit_details(transitdetails);
    get_checkin_time(checkin);
    get_checkout_time(checkout);

    room_no_given = get_room_allocated(db);

    id_type = update_id_proofs(db,id_name,uid);

    printf("%s \n",name);
    printf("%s \n",address);
    printf("%s \n",phonenumber);
    printf("%s \n",transitdetails);
    printf("%s \n",checkin);
    printf("%s \n",checkout);
    printf("The room allocated is  : %d \n",room_no_given);

    printf("The id proof type is  : %d \n",id_type);
    printf("The id proof given is  : %s \n",id_name);
    printf("The UID is  : %s \n",uid);

   sqlite3_close(db);
   return 0;

   // TODO : insert values into database.

}

