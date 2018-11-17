#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 20

typedef struct _Student {
    int id;
    char name[LENGTH];
} Student;

int main(void)
{
    int now_size = 0, max_size = 1;
    char string[LENGTH];

    Student *student = (Student *) malloc(max_size * sizeof(Student));

    setbuf(stdin, NULL);
    while (fgets(string, LENGTH, stdin) != NULL) {
        if (now_size == max_size) {
            max_size += 1;
            student = (Student *) realloc(student, max_size * sizeof(Student));
        }

        student[now_size].id = now_size;
        memcpy(student[now_size].name, string, LENGTH);

        now_size++;      
    }

    printf("Realloc memory times = %d.\n\n", max_size - 1);
    for (Student *ptr = student; ptr - student < now_size; ptr++) {
        printf("id = %02d name = %s", ptr->id, ptr->name);
    }

    return 0;
}
