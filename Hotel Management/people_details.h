#pragma once

#ifndef PEOPLE_DETAILS
#define PEOPLE_DETAILS

#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"
#include <string.h>

struct Person {
    char name[500];
    char address[500];
    char phonenumber[500];
    char transitdetails[500];
    char checkin[500];
    char checkout[500];

    int id_type;
    char id_name[500];
    char uid[100];

    int room_no_given;

};


// Name of person
void get_name(struct Person *person);

// Address of person
void get_address(struct Person *person);

// Phone Number of person
void get_phonenumber(struct Person *person);

// Transit Details of person
void get_transit_details(struct Person *person);

// Check in time
void get_checkin_time(struct Person *person);

// Check out time
void get_checkout_time(struct Person *person);

// Show room types
int show_room_types(int *data, int argc, char **argv, char **azColName);

// Show room numbers
int show_room_numbers(int *data, int argc, char **argv, char **azColName);

// Get room allocated
int get_room_allocated(sqlite3* db);

// Show id types
int show_id_types(int *data, int argc, char **argv, char **azColName);

// Update id proofs
int update_id_proofs(sqlite3* db,struct Person *person);


void add_to_database(sqlite3 *db, struct Person *person );

void do_nothing(int *data, int argc, char **argv, char **azColName);
#endif // PEOPLE_DETAILS
