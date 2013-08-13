
PREFIX ?= /usr/local

lorem: src/*.h src/*.c
	gcc src/lorem.h src/lorem.c src/main.c -o lorem

install: lorem
	cp -f lorem $(PREFIX)/bin/lorem

uninstall:
	rm -f $(PREFIX)/bin/lorem

clean:
	rm lorem

.PHONY: clean install uninstall
