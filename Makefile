var := $(patsubst %.c,%.o,$(wildcard *.c))

# Generate executable
a.out: $(var)
	gcc -o $@ $^