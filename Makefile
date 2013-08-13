
PREFIX ?= /usr/local

lorem:
	gcc src/lorem.h src/lorem.c -o lorem

install: lorem
	cp -f lorem $(PREFIX)/bin/lorem

uninstall:
	rm -f $(PREFIX)/bin/lorem

clean:
	rm lorem

.PHONY: clean install uninstall
