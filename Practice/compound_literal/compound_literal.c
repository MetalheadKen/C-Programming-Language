#include "compound_literal.h"

Person person = (Person) { 1, "name" };
Person *person1 = (&(Person) { .id = 1, .name = "Sam" });
int *p = (int []) {2, 4};
