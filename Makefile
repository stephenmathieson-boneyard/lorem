
PREFIX ?= /usr/local

lorem: src/*.h src/*.c

install: lorem
	cp -f lorem $(PREFIX)/bin/lorem

uninstall:
	rm -f $(PREFIX)/bin/lorem

clean:
	rm lorem

.PHONY: clean install uninstall
