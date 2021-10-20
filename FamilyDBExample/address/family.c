//
//  family.c
//  FamilyDBExample
//
//  Created by Oliver Epper on 20.10.21.
//

#include <stdlib.h>
#include <stdbool.h>
#include "family.h"

struct family_instance_t {
    char *name;
    size_t size;
    person_t members[];
};

family_t address_family_create(char *name)
{
    family_t instance = calloc(1, sizeof(struct family_instance_t));
    if (instance) {
        instance->name = name;
        instance->size = 0;
    }
    return instance;
}

void address_family_destroy(family_t instance)
{
    for (int i=0; i<instance->size; i++)
        address_person_destroy(instance->members[i]);
    free(instance);
}

bool address_family_add_member(family_t *instance, person_t member)
{
    *instance = realloc(*instance, sizeof(struct family_instance_t) + (((family_t) *instance)->size + 1) * sizeof(person_t));
    if (*instance) {
        ((family_t)*instance)->members[((family_t)*instance)->size] = member;
        ((family_t)*instance)->size++;
        return true;
    }
    return false;
}

bool is_member(family_t instance, person_t member)
{
    for (int i=0; i<instance->size; i++) {
        if (instance->members[i] == member)
            return true;
    }
    return false;
}

bool address_family_remove_member(family_t *instance, person_t member)
{
    if(is_member(*instance, member)) {
        family_t new_instance = calloc(1, sizeof(struct family_instance_t) + (((family_t) *instance)->size - 1) * sizeof(person_t));
        if (new_instance) {
            new_instance->name = ((family_t) *instance)->name;
            new_instance->size = ((family_t) *instance)->size - 1;
            int j=0;
            for (int i=0; i<((family_t) *instance)->size; i++) {
                if (((family_t) *instance)->members[i] != member) {
                    new_instance->members[j] = ((family_t) *instance)->members[i];
                    j++;
                }
            }
            *instance = new_instance;
            return true;
        }
        return false;
    }
    return false;
}

void address_family_pp(family_t instance)
{
    printf("Family %s:\n", instance->name);
    for (int i=0; i<instance->size; i++)
        address_person_pp(instance->members[i]);
}

size_t address_family_size(family_t instance)
{
    return instance->size;
}

person_t address_family_get(family_t instance, uint8_t position)
{
    return instance->members[position];
}
