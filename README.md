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
ml> def {fun} (\ {args body} {def (head args) (\ (tail args) body)})
()
ml> fun {add-two x y} {+ x y}
()
ml> add-two 5
(\ {y} {+ x y})
ml> add-two 5 6
11
ml> fun {true a b} {a}
()
ml> fun {false a b} {b}
()
ml> fun {if p a b} {p a b}
()
ml> if true 5 6
5
ml> if false 5 6
6
ml> fun {not p} {p false true}
()
ml> not true
(\ {a b} {b})
ml> not false
(\ {a b} {a})
ml> not (not true)
(\ {a b} {a})
ml> (not (not true)) 5 6
5
ml> (not (not (not true))) 5 6
6
ml> if (< 5 6 5) 1 0
0
ml> if (< 5 6) 1 0
1
ml> fun {if p a b} {eval (p a b)}
()
ml> if (< 6 7) {6} {7}
6
ml> if (< 6 7) {+ 6 8} {+ 8 7}
14
ml> "hello"
"hello"
ml> {"hello" "world"}
{"hello" "world"}
ml> head {"hello" "world"}
{"hello"}
ml> eval (head {"hello" "world"})
"hello"
```
