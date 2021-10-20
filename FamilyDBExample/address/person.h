//
//  person.h
//  FamilyDBExample
//
//  Created by Oliver Epper on 20.10.21.
//

#ifndef person_h
#define person_h

#include <stdio.h>

typedef struct person_instance_t *person_t;

person_t address_person_create(char *name, int age);
void address_person_destroy(person_t instance);
void address_person_pp(person_t instance);
char *address_person_name(person_t instance);

#endif /* person_h */
