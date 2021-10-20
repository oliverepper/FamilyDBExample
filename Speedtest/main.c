//
//  main.c
//  Speedtest
//
//  Created by Oliver Epper on 20.10.21.
//

#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include "address.h"

int main(int argc, const char * argv[]) {
    family_t test = address_family_create("Test");

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    for (int i=0; i<1000000; i++) {
        address_family_add_member(&test, address_person_create("Test Person", i));
    }
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);

    printf("Family size: %zu members\n", address_family_size(test));

    uint64_t delta_us = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec) / 1000;

    printf("delta %llu microseconds ", delta_us);
    printf("or %llu milliseconds\n", delta_us/1000);

    return EXIT_SUCCESS;
}
