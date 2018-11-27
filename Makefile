CC = gcc
src = $(wildcard *.c)
obj = $(src:.c=.o)

main: clean $(obj)
	$(CC) -o test $(obj)

.PHONY: clean
clean:
	rm -f $(obj) main
