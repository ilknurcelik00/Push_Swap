*This activity has been created as part of the 42 curriculum by <ilcelik>, <ssarican>*

---

# push_swap

A program that sorts a stack of integers using a limited set of operations, with four distinct sorting strategies and an optional benchmark mode.

---

## Description

**push_swap** takes a list of integers as arguments and outputs the sequence of operations needed to sort them in ascending order using two stacks (`a` and `b`) and the following operations:

| Operation | Effect |
|-----------|--------|
| `sa` | Swap the top 2 elements of stack a |
| `sb` | Swap the top 2 elements of stack b |
| `ss` | `sa` and `sb` at the same time |
| `pa` | Push top of b to top of a |
| `pb` | Push top of a to top of b |
| `ra` | Rotate stack a upward (first becomes last) |
| `rb` | Rotate stack b upward (first becomes last) |
| `rr` | `ra` and `rb` at the same time |
| `rra` | Reverse rotate stack a (last becomes first) |
| `rrb` | Reverse rotate stack b (last becomes first) |
| `rrr` | `rra` and `rrb` at the same time |

---

## Instructions

### Compilation

```bash
make
```

Requires `cc` with `-Wall -Wextra -Werror`. Produces the `push_swap` binary.

Other make rules:

```bash
make clean    # Remove object files
make fclean   # Remove object files and binary
make re       # Full rebuild
```

### Usage

```bash
./push_swap [FLAGS] <integers>
```

**Strategy flags (optional):**

```bash
./push_swap --simple   5 4 3 2 1   # O(n²) selection sort
./push_swap --medium   5 4 3 2 1   # O(n√n) chunk-based sort
./push_swap --complex  5 4 3 2 1   # O(n log n) radix sort
./push_swap --adaptive 5 4 3 2 1   # Auto-selects based on disorder
./push_swap            5 4 3 2 1   # Default: --adaptive
```

**Mode flags (optional):**

```bash
./push_swap --bench 5 4 3 2 1        # Show benchmark metrics on stderr
```

Flags can be combined:

```bash
./push_swap --bench --simple 5 4 3 2 1
```

**Verify correctness with checker:**

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
```

---

## Algorithms

### Simple — O(n²)

Selection sort adaptation. Repeatedly finds the minimum element in stack a, rotates it to the top using `ra`, pushes it to b with `pb`, then pushes everything back with `pa`. This generates at most O(n²) operations since each of the n elements requires at most n rotations.

**Used when:** `--simple` flag is given, or disorder < 0.2 in adaptive mode (after threshold check hands off to medium).

---

### Medium — O(n√n)

Chunk-based sorting. Divides the normalized index range into √n chunks. Phase 1: iterates through stack a and pushes elements belonging to the current chunk to b (using `ra` to skip non-matching elements), processing chunks in order. Phase 2: repeatedly finds the maximum element in b, rotates it to the top using `rb`/`rrb` (choosing the shorter direction), and pushes it to a with `pa`. This yields O(n√n) operations since each of the √n chunks requires O(√n) rotations on average.

**Used when:** `--medium` flag is given, or 0.2 ≤ disorder < 0.5 in adaptive mode.

---

### Complex — O(n log n)

LSD Radix sort adaptation. Normalizes values to indices 0..n-1, then sorts bit by bit from least significant to most significant bit (requiring ⌈log₂n⌉ passes). In each pass: if the current bit of the top element is 1, rotate with `ra`; if 0, push to b with `pb`. After processing all elements, push everything back from b to a with `pa`. The total number of operations is O(n log n) since each of the ⌈log₂n⌉ passes touches all n elements.

**Used when:** `--complex` flag is given, or disorder ≥ 0.5 in adaptive mode.

---

### Adaptive — Custom Design

Measures the **disorder** of the input first, then delegates to the appropriate strategy:

| Disorder range | Strategy selected | Complexity |
|---------------|-------------------|------------|
| disorder < 0.2 | Simple | O(n²) |
| 0.2 ≤ disorder < 0.5 | Medium | O(n√n) |
| disorder ≥ 0.5 | Complex | O(n log n) |

**Disorder metric:** Counts the number of inverted pairs (pairs where a larger value appears before a smaller one) divided by the total number of pairs. A perfectly sorted stack has disorder 0.0; a reverse-sorted stack has disorder 1.0.

**Rationale for thresholds:** When disorder is low (< 0.2), the stack is nearly sorted and a simple O(n²) strategy terminates quickly with very few operations in practice. For medium disorder (0.2–0.5), chunk-based sorting is efficient because partial ordering reduces the number of rotations needed per chunk. For high disorder (≥ 0.5), the radix sort's guaranteed O(n log n) regardless of input distribution gives the best worst-case performance.

**Space complexity:** All strategies operate in O(n) space (the two stacks).

---

## Benchmark Mode

When `--bench` is passed, the program prints the following metrics to **stderr** after sorting:

```
=== push_swap benchmark ===
Disorder: 51.14%
Strategy: Adaptive (O(adaptive))
Total operations: 6784
  sa:0 sb:0 ss:0
  pa:2284 pb:2284
  ra:2216 rb:0 rr:0
  rra:0 rrb:0 rrr:0
```

---

## Performance Targets

| Input size | Pass (< ops) | Good (< ops) | Excellent (< ops) |
|------------|-------------|--------------|-------------------|
| 100 numbers | 2000 | 1500 | 700 |
| 500 numbers | 12000 | 8000 | 5500 |

---

## Error Handling

The program prints `Error` to stderr and exits with code 1 when:
- An argument is not a valid integer
- An argument is outside the INT range (< -2147483648 or > 2147483647)
- There are duplicate values
- An argument is an empty string or whitespace-only

When no arguments are given or the input is already sorted, the program prints nothing and exits cleanly.

---

## Resources

- [42 push_swap subject](en_subject_push_swap.pdf)
- [Radix sort — Wikipedia](https://en.wikipedia.org/wiki/Radix_sort)
- [Insertion/Selection sort with two stacks](https://en.wikipedia.org/wiki/Selection_sort)
- [Counting inversions (disorder metric)](https://en.wikipedia.org/wiki/Inversion_(discrete_mathematics))

**AI usage:** AI was used to assist with:
- Debugging the `parse_args` token parsing logic (`parse_args.c`)
- Reviewing the disorder metric formula (`disorder.c`)
- Generating and verifying the benchmark output format (`bench.c`)

---

## Contributions

| File | Primary author |
|------|---------------|
| `main.c` | ilcelik |
| `parse_args.c` | ilcelik |
| `parse_token.c` | ilcelik |
| `ft_utils.c` | ilcelik |
| `ft_utils2.c` | ilcelik |
| `stack_utils.c` | ssarican |
| `stack_utils2.c` | ssarican |
| `stack_utils3.c` | ssarican |
| `ops_push.c` | ssarican |
| `ops_rotate.c` | ssarican |
| `ops_rev_rotate.c` | ssarican |
| `ops_swap.c` | ssarican |
| `sort_simple.c` | ilcelik |
| `sort_medium.c` | ssarican |
| `sort_complex.c` | ilcelik |
| `sort_adaptive.c` | ilcelik |
| `disorder.c` | ssarican |
| `bench.c` | ssarican |
| `push_swap.h` | ilcelik & ssarican |

Both learners understand and can explain all parts of the codebase.
