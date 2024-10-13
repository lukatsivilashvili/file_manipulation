#include "filecopy.h"
#include <stdio.h>
#include <unistd.h>

void parse_args(int argc, char *argv[], char **src_file, char **dest_file) {
  int opt;

  while ((opt = getopt(argc, argv, "s:d:")) != -1) {
    switch (opt) {
    case 's':
      *src_file = optarg;
      break;
    case 'd':
      *dest_file = optarg;
      break;
    default:
      fprintf(stderr, "Usage: %s -s source_file -d destination_file\n",
              argv[0]);
      exit(EXIT_FAILURE);
    }
  }

  if (*src_file == NULL || *dest_file == NULL) {
    fprintf(stderr, "Both source and destination files must be specified\n");
    exit(EXIT_FAILURE);
  }
}
