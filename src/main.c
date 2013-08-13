
//
// main.c
//
// Copyright (c) 2013 Stephen Mathieson <me@stephenmathieson.com>
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include "lorem.h"

void usage() {
  printf("lorem <number of words>\n");
  exit(1);
}

void version() {
  printf("lorem version %s\n", LOREM_VERSION);
  exit(1);
}

/*
 * Print "Lorem ipsum..." with the number of
 * given words.  Defaults to 100 words.
 */

int main(int argc, char *argv[]) {

  srand(time(0));

  int count = 100;
  if (argc == 2) {
    if (strcmp(argv[1], "--help") == 0) {
      usage();
    } else if (strcmp(argv[1], "--version") == 0) {
      version();
    } else {
      count = atoi(argv[1]);
    }
  }

  char *lorem = lorem_ipsum(count);
  printf("%s\n", lorem);
  free(lorem);

  return 0;
}
