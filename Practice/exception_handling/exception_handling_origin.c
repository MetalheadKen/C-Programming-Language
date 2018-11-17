#include <stdio.h>
#include <setjmp.h>

#define TRY    do { jmp_buf exce_buf; if (!setjmp(exce_buf)) {
#define CATCH  } else {
#define END    } } while(0)
#define THROW  longjmp(exce_buf, 1)

int main(void)
{
    TRY {
        printf("In TRY statment.\n");
        THROW;
        printf("Here will not be printed.\n");
    } CATCH {
        printf("Exception handling.\n");
    }
    END;

    return 0;
}
