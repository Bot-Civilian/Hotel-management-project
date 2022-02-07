#include "people_details.h"
#include <conio.h>
#include "ANSI-color-codes.h"

int main() {
    sqlite3 *db;

    int rc;

   // Open the database
    rc = sqlite3_open("Hotel_Management_System.db", &db);

    if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
    }

    struct Person user;

    get_name(&user);
    get_address(&user);
    get_phonenumber(&user);
    get_transit_details(&user);
    get_checkin_time(&user);
    get_checkout_time(&user);

    user.room_no_given = get_room_allocated(db);

    user.id_type = update_id_proofs(db,&user);


    printf("%s \n" reset,user.name);
    printf("%s \n" reset,user.address);
    printf("%s \n" reset,user.phonenumber);
    printf("%s \n" reset,user.transitdetails);
    printf("%s \n" reset,user.checkin);
    printf("%s \n" reset,user.checkout);
    printf( CYN"The room allocated is  : %d \n",user.room_no_given);
    printf( RED"The id proof type is  : %d \n",user.id_type);
    printf( YEL"The id proof given is  : %s \n",user.id_name);
    printf( WHT"The UID is  : %s \n",user.uid);

    add_to_database(db, &user);
    sqlite3_close(db);
    return 0;

   // TODO : insert values into database.

}
