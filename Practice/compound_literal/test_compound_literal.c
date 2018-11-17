#include <stdio.h>

typedef struct _Person {
    int id;
    char *name;
} Person;

/* 
 * Error: Compound literal is not a constant, it is an lvalue and has 
 * static storage duration.
 * But the GNU extension allow and support it.
 */
Person p1 = (Person) { .id = 1 };
/* 
 * Works fine: An address constant is a constant, that can be a pointer to 
 * an lvalue designating an obect of static storage duration.
 */
Person *p2 = (&(Person) { .id = 1, .name = (char []) { "Sam" } });

int *p = (int []) {2, 4};

int main(void)
{
    /*
     * Works fine: A compound literal can be a const-qualified types, that 
     * has automatic storage duration associated with the enclosing block.
     */
    const Person a = (const Person) { .id = 1 };
    p2 = (&(Person) { .id = p2->id, .name = (char []) { "Saa" } });
    p2->name[1] = 'b';
    printf("id = %s\n", p2->name);
    return 0;
}
