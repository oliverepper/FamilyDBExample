//
//  family.h
//  FamilyDBExample
//
//  Created by Oliver Epper on 20.10.21.
//

#ifndef family_h
#define family_h

#include <stdio.h>
#include <stdbool.h>
#include "person.h"

typedef struct family_instance_t *family_t;

family_t address_family_create(char *name);
void address_family_destroy(family_t instance);
bool address_family_add_member(family_t *instance, person_t member);
bool address_family_remove_member(family_t *instance, person_t member);
void address_family_pp(family_t instance);
size_t address_family_size(family_t instance);
person_t address_family_get(family_t instance, uint8_t position);

#endif /* family_h */
