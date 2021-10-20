//
//  person.c
//  FamilyDBExample
//
//  Created by Oliver Epper on 20.10.21.
//

#include <stdlib.h>
#include "person.h"

struct person_instance_t {
    char *name;
    int age;
};

person_t address_person_create(char *name, int age)
{
    person_t instance = calloc(1, sizeof(struct person_instance_t));
    if (instance) {
        instance->name = name;
        instance->age = age;
    }
    return instance;
}

void address_person_destroy(person_t instance)
{
    free(instance);
}

void address_person_pp(person_t instance)
{
    printf("My name is %s and I am %d years old.\n", instance->name, instance->age);
}

char *address_person_name(person_t instance)
{
    return instance->name;
}
