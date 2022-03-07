#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

// зашлю, чтобы хоть что-то было :(

int
main(int argc, char ** argv) {
    if (argc < 2) {
        write(2, "ERROR: Wrong number of arguments\n", 33);
        exit(1);
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        write(2, "ERROR: Cannot open file\n", 24);
        exit(1);
    }
    char filename[10] = "tmpXXXXXX";
    int tmp = mkstemp(filename);

    int len = 2; 
    char *split = malloc(len * sizeof(char));

    if (argc == 2) {
        strcpy(split, ",");
    } else {
        if (strlen(argv[2]) > len) {
            len = strlen(argv[2]);
            split = realloc(split, len * sizeof(char));
        }
        strcpy(split, argv[2]);
    }

    int buf_size = 100;
    char buf[buf_size];
    char *ptr1, ptr2, max_ptr;
    int n; // количество прочитанных символов
    while ((n = read(fd, buf, buf_size)) > 0) {
        if (errno) {
            write(2, "ERROR: Cannot read from file\n", 29);
            exit(1);
        }
        /// не написала
    }

    unlink(filename);
    free(split);
    return 0;
}