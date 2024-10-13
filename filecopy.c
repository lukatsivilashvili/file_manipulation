#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

int file_copy(const char *src_file, const char *dest_file) {
    int src_fd, dest_fd, bytes_read;
    char buffer[BUFFER_SIZE];

    // Open source file
    src_fd = open(src_file, O_RDONLY);
    if (src_fd < 0) {
        perror("Error opening source file");
        return -1;
    }

    // Open destination file (create if it doesn't exist, truncate if it does)
    dest_fd = open(dest_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd < 0) {
        perror("Error opening/creating destination file");
        close(src_fd);
        return -1;
    }

    // Copy content
    while ((bytes_read = read(src_fd, buffer, BUFFER_SIZE)) > 0) {
        if (write(dest_fd, buffer, bytes_read) != bytes_read) {
            perror("Error writing to destination file");
            close(src_fd);
            close(dest_fd);
            return -1;
        }
    }

    if (bytes_read < 0) {
        perror("Error reading from source file");
    }

    close(src_fd);
    close(dest_fd);

    return (bytes_read < 0) ? -1 : 0;
}
