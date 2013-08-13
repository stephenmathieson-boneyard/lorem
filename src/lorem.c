
//
// lorem.c
//
// Copyright (c) 2013 Stephen Mathieson <me@stephenmathieson.com>
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include "lorem.h"


char *LOREM_WORDS[LOREM_NUM_WORDS] = {
  "dolor", "sit", "amet", "consectetur", "adipisicing", "elit", "sed",
  "do", "eiusmod", "tempor", "incididunt", "ut", "labore", "et", "dolore",
  "magna", "aliqua", "Ut", "enim", "ad", "minim", "veniam", "quis",
  "nostrud", "exercitation", "ullamco", "laboris", "nisi", "ut", "aliquip",
  "ex", "ea", "commodo", "consequat", "Duis", "aute", "irure", "dolor",
  "in", "reprehenderit", "in", "voluptate", "velit", "esse", "cillum",
  "dolore", "eu", "fugiat", "nulla", "pariatur", "Excepteur", "sint",
  "occaecat", "cupidatat", "non", "proident", "sunt", "in", "culpa", "qui",
  "officia", "deserunt", "mollit", "anim", "id", "est", "laboru"
};


/*
 * Get a random Latin word
 */

char *lorem_word() {
  return LOREM_WORDS[rand() % LOREM_NUM_WORDS];
}

/*
 * Return a character array of `count`
 * words, prefixed with "Lorem ipsum".
 */

char *lorem_ipsum(size_t count) {
  char *words[count];
  // strlen("Lorem ipsum") + strlen(".")
  int size = 11;
  int position = 11;

  int i;
  // build the array of words first
  for (i = 0; i < count; i++) {
    words[i] = lorem_word();
    size += strlen(words[i]);
  }

  // add a byte for null
  size++;

  char *res = malloc(sizeof(char) * size);

  strncpy(res, "Lorem ipsum", 11);
  for (i = 0; i < count; i++) {
    int len = strlen(words[i]);
    // pass reference, so `strcat` doesn't have to search for null
    strncat(&res[position], words[i], len);
    // tracking position for a significant performance boost :)
    position += len;
    res[position] = ' ';
  }

  res[position - 2] = '.';
  res[position - 1] = '\0';

  return res;
}