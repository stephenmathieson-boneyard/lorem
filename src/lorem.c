
//
// lorem.c
//
// Copyright (c) 2013 Stephen Mathieson <me@stephenmathieson.com>
//

#include <string.h>
#include <stdio.h>
#include <time.h>
#include "lorem.h"

/*
 * Get a random `lorem` word
 */

char *lorem_word() {
  return lorem_words[rand() % lorem_word_count];
}

/*
 * Fill `buf` with "Lorem ipsum" plus `count` words
 */

void lorem_ipsum(char *buf, size_t count) {

  srand(time(0));

  // always start with Lorem ipsum
  strcpy(buf, "Lorem ipsum");

  int i;
  char *last = lorem_word();
  for (i = 0; i < count; ++i) {
    char *thing = lorem_word();

    // don't put two of the same words next to each other
    while (strcmp(last, thing) == 0) {
      thing = lorem_word();
    }

    strcat(buf, " ");
    strcat(buf, thing);
    last = thing;
  }

  strcat(buf, ".");
}

/*
 * Print "Lorem ipsum..." with the number of
 * given words.  Defaults to 100 words.
 */

int main(int argc, char *argv[]) {
  int count = 100;

  if (argc == 2) {
    count = atoi(argv[1]);
  }

  char lorem[13 * count];

  lorem_ipsum(lorem, count);

  printf("%s\n", lorem);
  return 0;
}
