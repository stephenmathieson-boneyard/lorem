
//
// lorem.h
//
// Copyright (c) 2013 Stephen Mathieson <me@stephenmathieson.com>
//


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>

#ifndef SRC_LOREM_H_
#define SRC_LOREM_H_

#define LOREM_VERSION "0.0.1"

#define LOREM_NUM_WORDS 67

extern char *LOREM_WORDS[LOREM_NUM_WORDS];

extern char *lorem_ipsum(size_t count);

#endif  // SRC_LOREM_H_
