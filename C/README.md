
# boot.dev: Learn Memory Management in C

## Overview

this folder contains various problems in the boot.dev course "Learn Memory Management in C"

## Usage

- for each chapter and lesson make a folder structure like `boot.dev/C/CHAPTER/LESSON`
- copy the files used for the chapter and lesson into the above structure
- once you complete the lesson, you must compile an executable to run the tests
    - this is done using something like `clang -I boot.dev/C/ main.c exercise.c boot.dev/C/munit/munit.c`
        - the modified header file `munit.h` is located on `boot.dev/C/` - this allows us to run the test macros that boot.dev uses. I found this modified file [here](https://git.riyyi.com/riyyi/bootdev-c/src/commit/ec77cf9a1d37d12f3166e090f5c6e5b1f1eb1ba0/src/munit.h)
        - `main.c exercise.c` are the names of the files used in the problem, adjust these as necessary
        - `boot.dev/C/munit/munit.c` refers to the `munit.c` file, we need to compile this to run our tests