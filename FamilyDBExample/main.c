//
//  main.c
//  FamilyDBExample
//
//  Created by Oliver Epper on 20.10.21.
//

#include <stdio.h>
#include <stdlib.h>
#include "address.h"

int main(int argc, const char * argv[]) {
    family_t epper = address_family_create("Epper");

    person_t bingo = address_person_create("Bingo", 7);
    address_family_add_member(&epper, bingo);

    person_t oli = address_person_create("Oliver", 42);
    address_family_add_member(&epper, oli);

    person_t maike = address_person_create("Maike", 42);
    address_family_add_member(&epper, maike);

    person_t elja = address_person_create("Elja", 6);
    address_family_add_member(&epper, elja);

    person_t juna = address_person_create("Juna", 4);
    address_family_add_member(&epper, juna);

    address_family_remove_member(&epper, bingo);

    address_family_pp(epper);
    
    address_family_destroy(epper);

    return EXIT_SUCCESS;
}
