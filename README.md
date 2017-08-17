```
$ make clean all
rm -f prompt
rm -f parsing
cc -std=c99 -Wall -g prompt.c -ledit -o prompt
cc -std=c99 -Wall -g parsing.c mpc.c -ledit -lm -o parsing
$ ./parsing 
MyLISP v. 0.0.2-SNAPSHOT
Press Ctrl-c to exit.

ml> + 5 12
17
```
