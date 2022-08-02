# Makefile

all:
	$(MAKE) -C src
	cp src/demo.ihx .

clean:
	$(MAKE) -C src clean

.PHONY: all clean
