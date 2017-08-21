```
$ make clean all
rm -f prompt
rm -f parsing
cc -std=c99 -Wall -g prompt.c -ledit -o prompt
cc -std=c99 -Wall -g parsing.c mpc.c -ledit -lm -o parsing
$ ./parsing
MyLISP v. 0.0.10-SNAPSHOT
Press Ctrl-c to exit.

ml> list + 6 5
{+ 6 5}
ml> eval (list + 6 5)
11
ml> eval {+ 6 5}
11
ml> eval {+ 6 5 (- 5 6)}
10
ml> eval (head {+ 6 5 (- 5 6)})
+
ml> eval {head (list 6 7 8)}
{6}
ml> eval (eval {head (list 6 7 8)})
6
ml> (eval {+ tail (list 6 7 8)})
ERROR: Cannot operate on non-number.
ml> eval {+ tail (list 6 7 8)}
ERROR: Cannot operate on non-number.
ml> + (eval {tail (list 6 7 8)})
ERROR: Cannot operate on non-number.
ml> {tail (list 6 7 8)}
{tail (list 6 7 8)}
ml> eval {tail (list 6 7 8)}
{7 8}
ml> join {+} (eval {tail (list 6 7 8)})
{+ 7 8}
ml> eval (join {+} (eval {tail (list 6 7 8)}))
15
ml> def {x y} 250 100
()
ml> - x y
150
ml> + x y
350
```
