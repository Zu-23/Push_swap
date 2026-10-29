# Push_swap

A 42 sorting project in C that generates stack operations to sort integers using two stacks. The repository also includes a checker that reads and applies an operation sequence.

## Features

- Linked-list stack representation.
- Swap, push, rotate, reverse-rotate, and combined operations.
- Separate sorting paths for small inputs and larger chunk-based inputs.
- Integer-range and duplicate checks.
- A bonus checker accepting operations from standard input.

See [main.c](main.c), [actions](actions), and [functions](functions) for the sorting implementation.

## Build

Requires GCC, Make, and `ar`:

```sh
make          # push_swap and its supporting archives
make bonus    # checker; run make first to build ft_printf
```

`make clean`, `make fclean`, and `make re` are available.

## Usage

```sh
./push_swap 3 2 1
printf 'sa\nrra\n' | ./checker 3 2 1
```

`push_swap` prints operations such as `sa`, `pb`, and `ra`. The checker reports `OK` or `KO` for the resulting ordering and reports invalid operations as errors.

## Platform note

The current `main.c` calls `system("leaks push_swap")` after sorting. `leaks` is a macOS diagnostic tool; on Linux this produces a command-not-found message. On macOS its diagnostic output can also mix with the operation output. Account for that before piping the program into a checker or another tool.

## Concepts practiced

Stack operations, linked lists, parsing, integer boundaries, sorting strategies, operation counts, and ownership of dynamically allocated nodes.
