//
//  Tests.m
//  Tests
//
//  Created by Oliver Epper on 20.10.21.
//

#import <XCTest/XCTest.h>
#include "address.h"

@interface Tests : XCTestCase

@end

@implementation Tests

- (void)setUp {
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
}

- (void)testCreatePerson {
    person_t oli = address_person_create("Oliver", 42);
    assert(oli != NULL);
}

- (void)testDeleteLastPersonFromFamily {
    // given
    person_t oli = address_person_create("Oliver", 42);
    person_t maike = address_person_create("Maike", 42);
    family_t epper = address_family_create("Epper");
    address_family_add_member(&epper, oli);
    address_family_add_member(&epper, maike);
    assert(address_family_size(epper) == 2);

    // when
    address_family_remove_member(&epper, maike);

    // then
    assert(address_family_size(epper) == 1);
    assert(address_family_get(epper, 0) == oli);
}

- (void)testDeleteFirstPersonFromFamily {
    // given
    person_t oli = address_person_create("Oliver", 42);
    person_t maike = address_person_create("Maike", 42);
    family_t epper = address_family_create("Epper");
    address_family_add_member(&epper, oli);
    address_family_add_member(&epper, maike);
    assert(address_family_size(epper) == 2);

    // when
    address_family_remove_member(&epper, oli);

    // then
    assert(address_family_size(epper) == 1);
    assert(address_family_get(epper, 0) == maike);
}

- (void)testPerformanceExample {
    [self measureBlock:^{
        family_t test_family = address_family_create("Test");
        for (int i=0; i<1000000; i++) {
            address_family_add_member(&test_family, address_person_create("Person", i));
        }
    }];
}

@end
