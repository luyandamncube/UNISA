# UNISA

## COS2601 - Theoretical Computer Science II 	
- This was a module I completed while studying at the University of South Africa.

## Resources
- [NESO Academy's](https://www.youtube.com/watch?v=58N2N7zJGrQ&list=PLBlnK6fEyqRgp46KUv4ZY69yXmpwKOIev) playlist on youtue was a great source for a crash course on this topic
- [GraphViz](https://graphviz.gitlab.io/_pages/Download/Download_windows.html) provides a good tool for drawing Finite Automata:

 <p align="center">
  <img src="../../src/fa.png"/>
</p>

* [GraphViz Pocket Reference](https://graphs.grevian.org/example)  provides examples of the types of drawings you can do with GraphViz.
* [](https://martin-thoma.com/how-to-draw-a-finite-state-machine/) shows examples of how to draw DFA and NFA

### Deterministic Finite Automata:

```
digraph finite_state_machine {
    rankdir=LR;
    size="8,5"

    node [shape = doublecircle, label="{f}", fontsize=12] f;
    node [shape = doublecircle, label="{q2, f}", fontsize=10] q2f;

    node [shape = circle, label="S", fontsize=14] S;
    node [shape = circle, label="{q1}", fontsize=12] q1;
    node [shape = circle, label="{q2}", fontsize=12] q2;

    node [shape = point ]; qi
    qi -> S;

    S   -> q1  [ label = "a" ];
    S   -> q2f [ label = "b" ];
    S   -> q2  [ label = "c" ];

    q1  -> q2  [ label = "b" ];

    q2f -> f   [ label = "b" ];
    q2f -> q2  [ label = "c" ];

    q2  -> f   [ label = "b" ];
    q2  -> q2  [ label = "c" ];
}
```
### Non-Deterministic Finite Automata:

```
digraph finite_state_machine {
    rankdir=LR;
    size="8,5"

    node [shape = doublecircle]; S;
    node [shape = point ]; qi

    node [shape = circle];
    qi -> S;
    S  -> q1 [ label = "a" ];
    S  -> S  [ label = "a" ];
    q1 -> S  [ label = "a" ];
    q1 -> q2 [ label = "b" ];
    q2 -> q1 [ label = "b" ];
    q2 -> q2 [ label = "b" ];
}
```


### Assignment 1
* [Languages, Recursive Definitions, Regular Expressions](https://github.com/luyandamncube/UNISA/tree/master/year2/COS2601/ASS1)

### Assignment 2
* [Finite Automata, Transition Graphs](https://github.com/luyandamncube/UNISA/tree/master/year2/COS2601/ASS2)

### Assignment 3
* [Kleene's Theorem, Finite Automata with Output, Regular Languages, Nonregular Languages, Decidability](https://github.com/luyandamncube/UNISA/tree/master/year2/COS2601/ASS3)


### Exam
- All the above concepts tested
