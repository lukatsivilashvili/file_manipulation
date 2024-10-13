#include <stdio.h>
#include <stdlib.h>
#include "filecopy.h"

void parse_args(int argc, char *argv[], char **src_file, char **dest_file);

int main(int argc, char *argv[]) {
    char *src_file = NULL;
    char *dest_file = NULL;

    parse_args(argc, argv, &src_file, &dest_file);

    if (file_copy(src_file, dest_file) == 0) {
        printf("File copied successfully!\n");
    } else {
        fprintf(stderr, "File copy failed!\n");
        return EXIT_FAILURE;
    }
}