<a id="top"></a>

<div align="center">
    <h3>Push_swap</h3>
</div>

---

### Table of Contents

- [Description](#description)
  - [Rules](#rules)
  - [Built With](#built-with)
- [Getting Started](#getting-started)
  - [Installation](#installation)
  - [Tests](#tests)
- [Usage](#usage)
  - [Checker](#checker)
  - [Disclaimer](#disclaimer)
- [License](#license)
- [Contact](#contact)
- [Acknowledgments](#acknowledgments)

---

## Description

This project is my implementation of the "Push_swap" 42 project.

This project is an algorithmic project consisting of sorting a given set of integers using 2 stacks and a set of allowed operations.

The goal of the project is to create a program that manages to sort the data using as few operations as possible.

### Rules

At program start, there are two stacks named `a` and `b`. `a` containing a random number of unique negative and/or positive integers, `b` being empty.

The goal is to sort the stack `a` in ascending order. To do so, there are 11 different operations that can be used:

- `sa` (swap `a`): Swap the first 2 elements at the top of stack `a`.
  Do nothing if there is only one element or none.
- `sb` (swap `b`): Swap the first 2 elements at the top of stack `b`.
  Do nothing if there is only one element or none.
- `ss` : `sa` and `sb` at the same time.
- `pa` (push `a`): Take the first element at the top of `b` and put it at the top of `a`.
  Do nothing if `b` is empty.
- `pb` (push `b`): Take the first element at the top of `a` and put it at the top of `b`.
  Do nothing if `a` is empty.
- `ra` (rotate `a`): Shift up all elements of stack `a` by 1.
  The first element becomes the last one.
- `rb` (rotate `b`): Shift up all elements of stack `b` by 1.
  The first element becomes the last one.
- `rr` : `ra` and `rb` at the same time.
- `rra` (reverse rotate `a`): Shift down all elements of stack `a` by 1.
  The last element becomes the first one.
- `rrb` (reverse rotate `b`): Shift down all elements of stack `b` by 1.
  The last element becomes the first one.
- `rrr` : `rra` and `rrb` at the same time.

### Built With

[![C](https://skillicons.dev/icons?i=c&theme=light)](https://www.c-language.org/)

## Getting Started

### Installation

1. Fork the [repository](https://github.com/NestorNebula/push_swap)
2. Clone the forked repository to your local machine
   ```
   git clone git@github.com:<your username>/<repo name>.git
   ```
3. Update the remote URL

   ```
   # SSH:
   git remote add upstream git@github.com:NestorNebula/push_swap.git

   # HTTPS:
   git remote add upstream https://github.com/NestorNebula/push_swap.git
   ```

4. From the project's root directory, build the program
   ```
   make
   ```
5. Execute the program:
   ```
   ./push_swap numbers
   ```

You can read more about the `numbers` argument in the [usage section](#usage)

### Tests

Tests are provided for helpers functions in the `tests` directory.

1. Go to the tests directory
   ```
   cd tests
   ```
2. Build the tests
   ```
   make
   ```

The Makefile provides differents rules to run different tests based on what needs to be tested.

Rule to run tests on helpers functions:

```
make f
```

Rule to run tests on helpers functions with valgrind:

```
make fe
```

The other rules provided by the Makefile aren't of any use in this project

## Usage

The program's arguments should only be valid integers. There shouldn't be any duplicates in the provided integers.

The program's arguments can be formatted in three different ways:

1. All integers in one argument

```
./push_swap "2 1 3 6 5 8"
```

2. One integer per argument

```
./push_swap 2 1 3 6 5 8
```

3. A mix of both ways

```
./push_swap 2 1 "3 6 5" 8
```

In any way, each argument provided to the program should have at least one valid integer inside of it.

### Checker

A checker program is also provided to check that a list of instructions sort a stack correctly.

To build the checker program from the project's root repository:

```
make bonus
```

The program can the be used by reading commands from the terminal:

```
./checker 3 2 1 0
rra
pb
sa
rra
pa
OK

./checker 3 2 1 0
sa
rra
pb
KO
```

It can also be used to check that the push_swap program outputs a correct list of instructions:

```
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
OK
```

### Disclaimer

Please note that this project has been made public only to display my work and for learning purpose.

If you decide to use my project as your own personal work, you will be fully responsible for any repercussion that could occur.

Particularly, if you decide to use my work in any 42 project, this is considered as cheating by the 42 rules and can lead to sanctions.

## License

[![MIT License](https://img.shields.io/badge/License-MIT-darkcyan.svg?style=for-the-badge)](https://github.com/NestorNebula/push_swap/blob/main/LICENSE)

## Contact

Noa Houssier: [Github](https://github.com/NestorNebula) - [LinkedIn](www.linkedin.com/in/noahoussier)

## Acknowledgments

This project was done as a student of the [42](https://42.fr) Paris school.

To learn more about it, you can read the [subject](https://cdn.intra.42.fr/pdf/pdf/192339/en.subject.pdf).

Multiple resources were used to decide which algorithm to use for this project.

Particularly, when considering implementing a Radix sort, [this video](https://www.youtube.com/watch?v=Y95a-8oNqps&pp=ugMGCgJmchABugUEEgJmcsoFCnJhZGl4IHNvcnTYBwE%3D) was very useful.

The algorithm I decided to implement is called the "Turk Algorithm", designed by Yigit Ali Ogun. [This article](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) has been the starting point of my implementation.

<p align='right'>(<a href='#top'>go back to the top</a>)</p>
