# C++ Code Exercises and other Miscellaneous Code

This repository contains the solutions developed for solving various exercises
in the "C++ How to Program" textbook by Paul and Harvey Dietel.

The purpose is to document all the code written, and also catalog it for
future reuse.

Note: This does not solve _all_ the problems in the book. Only the interesting
ones or the ones worth solving have been solved. Special focus given to
problems regarding creating reusable C++ classes.

## The Repository Layout

The ``lib`` folder contains all the reusable classes (headers and
implementations) along with a driver program file ``main.cpp`` which you can
use to test those classes.

The ``solutions`` folder contains standalone programs each labelled with an
exercise number.

## How to use the repository

Within the ``lib`` directory, you can use the classes as follows:

1. Make necessary changes to the ``main.cpp`` to create a driver program.

2. Use the ``MakeFile`` to automatically compile all the library code and run
the executable

```bash
make all
```

This compiles all the files including the ``main.cpp`` and runs it to show the
output.

