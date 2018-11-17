#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define LENGTH 4

extern int errno;

int main(void)
{
    FILE *fd;
    int number = 0x55;
    int address_offset = 0x0A;
    unsigned char string[LENGTH] = { 0x12, 0x34, 0x56, 0x78 };

    if (!(fd = fopen("test-fwrite.bin", "wb"))) {
        fprintf(stderr, "File open operations failed : %s.\n\n", strerror(errno));
        goto FILE_OPEN_FAILURE;
    }

    if (fseek(fd, address_offset, SEEK_SET)) {
        fprintf(stderr, "File seek operations failed : %s.\n\n", strerror(errno));
        goto FILE_SEEK_FAILURE;
    }

    if (!fwrite(&number, sizeof(number), 1, fd)) {
        fprintf(stderr, "File write operations failed : %s.\n\n", strerror(errno));
        goto FILE_WRITE_FAILURE;
    }

    rewind(fd);

    if (!fwrite(string, sizeof(string), 1, fd)) {
        fprintf(stderr, "File write operations failed : %s.\n\n", strerror(errno));
        goto FILE_WRITE_FAILURE;
    }

    fclose(fd);
    
    printf("\n");
    system("hexdump test-fwrite.bin");

    printf("\n");
    system("hexdump -C test-fwrite.bin");
    printf("\n");

    return 0;

FILE_SEEK_FAILURE:
FILE_WRITE_FAILURE:
    fclose(fd);

FILE_OPEN_FAILURE:

    return 0;
}
