# Makefile

all: demo.ihx

%.rel: %.c
	sdcc -c $<

demo.ihx: main.rel serial.rel
	sdcc -o $@ $^

clean:
	rm -f *.lst *.rel *.rst *.sym *.asm *.ihx *.lk *.lst *.map *.mem

.PHONY: all clean
