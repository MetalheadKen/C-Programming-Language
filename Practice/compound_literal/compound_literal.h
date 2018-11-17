#ifndef COMPOUND_LITERAL_H_
#define COMPOUND_LITERAL_H_

#include <stdint.h>

typedef struct _Person {
    int id;
    char *name;
} Person;

extern Person person;
extern Person *person1;
extern int *p;

#endif /* COMPOUND-LITERAL_H_ */
