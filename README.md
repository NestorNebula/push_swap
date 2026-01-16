_This project has been created as part of the 42 curriculum by nhoussie_.

---

### Table of Contents

- [Description](#description)
  - [Rules](#rules)
- [Instructions](#instructions)
- [Usage](#usage)
- [Resources](#resources)

---

## Description

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

## Instructions

1. Build the program:

```
make
```

2. Execute the program:

```
./push_swap numbers
```

You can read more about the `numbers` argument in the [usage section](#usage)

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

## Resources

Multiple resources were used to decide which algorithm to use for this project.

Particularly, when considering implementing a Radix sort, [this video](https://www.youtube.com/watch?v=Y95a-8oNqps&pp=ugMGCgJmchABugUEEgJmcsoFCnJhZGl4IHNvcnTYBwE%3D) was very useful.

The algorithm I decided to implement is called the "Turk Algorithm", designed by Yigit Ali Ogun. [This article](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) has been the starting point of my implementation.

AI wasn't used in any part of this project.
