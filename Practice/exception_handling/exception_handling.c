#include <stdio.h>
#include <setjmp.h>

#define TRY       do { jmp_buf exce_buf; switch (setjmp(exce_buf)) { case 0: do {
#define CATCH(X)  break; case (X):
#define FINALLY   break; } while(0); default: do {
#define END       } while(0); } } while(0)
#define THROW(X)  longjmp(exce_buf, (X))

#define EXCEPTION_A (1)
#define EXCEPTION_B (2)
#define EXCEPTION_C (3)

int main(void)
{
    TRY {
        printf("In TRY statment.\n");
        THROW(EXCEPTION_B);
        printf("Here will not be printed.\n");
    } CATCH (EXCEPTION_A) {
        printf("Exception handling A.\n");
    } CATCH (EXCEPTION_B) {
        printf("Exception handling B.\n");
    } CATCH (EXCEPTION_C) {
        printf("Exception handling C.\n");
    } FINALLY {
        printf("In FINALLY statment.\n");
    }
    END;

    return 0;
}
