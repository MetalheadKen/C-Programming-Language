#include <stdio.h>

#define OFFSET(TYPE, MEMBER) ((size_t) &((TYPE *) 0)->MEMBER)

typedef struct _Process_State {
    unsigned char create     : 1;
    unsigned char ready      : 1;
    unsigned char running    : 1;
    unsigned char waiting    : 1;
    unsigned char blocked    : 1;
    unsigned char terminated : 1;
} Process_State;

int main(void)
{
    Process_State state;

    state.create = 1;
    printf("Size = %lu\n\n", OFFSET(Process_State, terminated));

    return 0;
}
