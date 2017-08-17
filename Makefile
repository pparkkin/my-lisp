
.PHONY: all
all: prompt parsing

prompt: prompt.c
	cc -std=c99 -Wall -g prompt.c -ledit -o prompt

parsing: parsing.c mpc.c
	cc -std=c99 -Wall -g parsing.c mpc.c -ledit -lm -o parsing

.PHONY: clean
clean:
	rm -f prompt
	rm -f parsing
