#ifndef INLINE_H_
#define INLINE_H_

#include <stdint.h>

//extern int add(int , int);
static inline int add(int a, int b)
{
    return a + b;
}

#endif /* INLINE_H_ */
