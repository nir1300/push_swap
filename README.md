# push_swap

A C program that sorts a stack of integers using only a restricted set of stack operations, printing the instruction sequence it finds. It is built around a **doubly linked list**, a dedicated routine for tiny inputs, and a **chunk-based push-and-insert algorithm** for larger ones.

Written for the 42 curriculum.

## The problem

Two stacks, `a` and `b`, start with all numbers in `a` and `b` empty. The goal is to leave `a` sorted in ascending order (smallest on top) using only:

| Instruction | Effect |
|-------------|--------|
| `sa` | swap the top two elements of `a` |
| `pa` / `pb` | move the top element from `b` to `a` / from `a` to `b` |
| `ra` | rotate `a` up: the first element becomes the last |
| `rra` | reverse rotate `a` down: the last element becomes the first |

(and their `b` counterparts). The program prints one instruction per line.

## Build and run

```bash
make            # builds libft, then ./push_swap
./push_swap 3 2 1
./push_swap "4 67 3 87 23"      # a single quoted string also works
```

```
$ ./push_swap 3 2 1
sa
rra
```

Count the instructions:

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
```

Other targets: `make clean`, `make fclean`, `make re`. The project is compiled with `-Wall -Wextra -Werror` and links against the bundled `libft`.

## Input handling

Input is accepted either as separate arguments or as one space-separated string (split with `ft_split`). It is validated before anything is sorted:

- every token must be an optional `+`/`-` sign followed by digits only,
- every value must fit in an `int` (the `ft_atoi` and `ft_atol` results must agree),
- there must be no duplicates.

Any violation prints `Error` to stderr and exits with status 1, freeing the split array first. With no arguments, or when the input is **already sorted**, the program exits silently without printing any instruction.

## How it sorts

`main` picks a strategy from the stack size:

| Size | Strategy | Function |
|------|----------|----------|
| 2-3 | direct case handling | `up_to_3` |
| 4-5 | push the smallest values to `b`, sort 3, push back | `up_to_5` |
| 6+ | chunking, then insertion back into `a` | `up_to_500` |

### 2-3 elements: `up_to_3`

At most three instructions: swap the top two if they are out of order, stop if the stack is now sorted, otherwise `rra`, then swap again if needed. This covers all six permutations of three numbers.

### 4-5 elements: `up_to_5`

While `a` has more than three elements, `cheapest()` brings the current **minimum** to the top by choosing `ra` or `rra`, whichever direction is shorter, and `pb` pushes it away. The three remaining elements are sorted with `up_to_3`, and everything in `b` is pushed back with `pa`. Because the smallest values were pushed first, they come back in the right order on top of `a`.

### 6+ elements: `up_to_500`

**1. Rank and chunk.** `positions()` gives every element its rank (1 = smallest) by counting how many values are smaller, then assigns it a chunk number: `chunk_nb = rank / chunk_len`. The chunk size scales with the input:

| Stack size | `chunk_len` |
|------------|-------------|
| up to 50 | 3 |
| 51 - 199 | 18 |
| 200+ | 40 |

**2. Push chunks to `b`.** For each chunk, from the highest down to the lowest, `split_chunks` walks through `a`: elements that belong to the current chunk are pushed to `b` (`pb`), everything else is rotated past with `ra`. When it finishes, `b` is organised by chunk with the **lowest values on top** and the highest at the bottom, and `a` has been reduced to a single element.

**3. Insert back into `a` (`pushback`).** `a` is kept sorted as a circular list. For the element on top of `b`:

- if it is a new **minimum or maximum**, `cheapest()` rotates the minimum to the top of `a` (shortest direction) and the element is pushed with `pa`, which places it at the correct boundary of the circular order;
- if it already fits between the top of `a` and the bottom of `a` (it is smaller than the top and larger than the last), it is pushed directly;
- otherwise `least_moves()` finds the insertion point by scanning `a` for the neighbours that bracket the value, and takes **one rotation step in the nearer direction** (`ra` if the point is in the first half, `rra` otherwise). The decision is re-evaluated on the next iteration.

When `b` is empty, a final `cheapest()` rotates the minimum to the top and `a` is sorted.

The chunking means the elements arrive in `b` roughly in increasing blocks, so each insertion only needs a short, directional rotation of `a` rather than a search from scratch.

## Project structure

| File | Contents |
|------|----------|
| `main.c` | argument parsing and validation (`error_handling`, `duplicate_check`, `error_mgm`), strategy selection |
| `algo_5.c` | `up_to_3`, `up_to_5` and `cheapest` |
| `algo_500.c` | chunk sorting: `positions`, `split_chunks`, `pushback`, `least_moves`, `up_to_500` |
| `bidirectional.c` | doubly linked list (`t_lst` with `content`, `next`, `prev`, `pos`, `chunk_nb`): create, add front/back, last, free |
| `operations.c` | the stack instructions (`sa`, `pa`, `pb`, `ra`, `rra`, ...) |
| `helpers.c` | small stack utilities |
| `tester.c` | list construction from the parsed arguments, `lstsize`, array cleanup |
| `push_swap.h` | types and prototypes |
| `libft/` | bundled `libft` |

## Memory handling

Both stacks are freed before exit, and the split-argument array is released on every error path. Allocation failure while building the list frees what was already allocated and exits.
