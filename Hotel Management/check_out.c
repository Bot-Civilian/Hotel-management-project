#include <stdio.h>
#include <time.h>
#include "sqlite3.h"
#include "people_details.h"

int get_check_in_time(int *data, int argc, char **argv, char **azColName){

    char time_str[4000];
    for(int i = 0; i<argc; i++){
        strcpy(time_str,argv[i]);

   }
    strcpy(data,time_str);
    printf("\n");


   return 0;
}

void calculate_bill(sqlite3 *db){

    char *zErrMsg = 0;
    int rc;
    char sql[400];
    int room_number = 0;
    char time_str[4000];
    char buffer[40];
    int ret;

    char year[4000];
    char month[4000];
    char day[4000];
    char hour[4000];
    char minutes[4000];
    char seconds[40000];

    printf("Please enter your room number : ");
    scanf("%d",&room_number);

    snprintf(sql,400,"SELECT \"Check In Date\" FROM People \
                      WHERE \"Allocated Room\" = %d",room_number);
    // Execute SQL statement
    rc = sqlite3_exec(db, sql, get_check_in_time, time_str, &zErrMsg);

    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
   }

    struct tm check_in_time;
    time_t check_in_secs;


    strncpy(year,time_str+6,4);
    strncpy(month,time_str+3,2);
    strncpy(day,time_str,2);
    strncpy(hour,time_str+11,2);
    strncpy(minutes,time_str+14,2);
    strncpy(seconds,time_str+17,2);

    check_in_time.tm_year = atoi(year) - 1900;
    check_in_time.tm_mon = atoi(month) - 1;
    check_in_time.tm_mday = atoi(day);
    check_in_time.tm_hour = atoi(hour);
    check_in_time.tm_min = atoi(minutes);
    check_in_time.tm_sec = atoi(seconds);
    check_in_time.tm_isdst = -1;

    check_in_secs = mktime(&check_in_time);

    time_t check_out_time;
//
//
    check_out_time = time(NULL);
//
    double diff_t;
    diff_t = difftime(check_out_time,check_in_secs);
    printf("%f hours passed",diff_t/3600);


}

int main(){
    sqlite3 *db;
    int rc;

   // Open the database
    rc = sqlite3_open("Hotel_Management_System.db", &db);

    if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
    }
    calculate_bill(db);
    sqlite3_close(db);
    return 0;
}
#include "ANSI-color-codes.h"
#include <stdio.h>

int main(){

	printf(BRED "Hey this is the color red, and it's bold! \n" reset);
	printf(RED "If" BLU "you" YEL "are" GRN "bored" CYN "do" MAG "this! \n" reset);
	printf(BRED "If" BBLU "you" BYEL "are" BGRN "bored" BCYN "do" BMAG "this! \n" reset);
	printf(URED "If" UBLU "you" UYEL "are" UGRN "bored" UCYN "do" UMAG "this! \n" reset);
return 0;};
