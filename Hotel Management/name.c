#include <stdio.h>

void get_name(char* name){

    printf("Please enter your name : \n");
    scanf("%s",name);

}

void get_address(char* address){

    printf("Please enter your address : \n");
    scanf("%s",address);
}

void get_phonenumber(char* phonenumber){

    printf("Please enter your phone number : \n");
    scanf("%s",phonenumber);
}

void get_transit_details(char* transitdetails){

    printf("Please enter your transit details : \n");
    scanf("%s",transitdetails);
}

void get_checkin_time(char* checkin){

    printf("Please enter your check in details DD-MM-YYYY_HH:MM:SS : \n");
    scanf("%s",checkin);
}

void get_checkout_time(char* checkout){

    printf("Please enter your check out details DD-MM-YYYY_HH:MM:SS : \n");
    scanf("%s",checkout);
}

int main(){

    char name[20];
    char address[500];
    char phonenumber[13];
    char transitdetails[500];
    char checkin[19];
    char checkout[19];

    get_name(name);
    get_address(address);
    get_phonenumber(phonenumber);
    get_transit_details(transitdetails);
    get_checkin_time(checkin);
    get_checkout_time(checkout);

    printf("%s \n",name);
    printf("%s \n",address);
    printf("%s \n",phonenumber);
    printf("%s \n",transitdetails);
    printf("%s \n",checkin);
    printf("%s \n",checkout);
}
