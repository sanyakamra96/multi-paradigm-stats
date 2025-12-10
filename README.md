# Multi-paradigm-stats
For C
```
cd c
gcc -o stats stats.c
./stats

```
For ocaml
```
cd ocaml
ocamlc -o stats stats.ml
./stats
```

For Python
```
cd python
python3 stats_calculator.py
```

# Multi-Paradigm Statistics Calculator

This project implements basic statistics (mean, median, and mode)
for a list of integers in **three languages**, each representing
a different programming paradigm:

- **C** – Procedural
- **OCaml** – Functional
- **Python** – Object-Oriented

## Features

For a list of integers, each implementation can compute:

- **Mean**: Average of all integers.
- **Median**: Middle value when the list is sorted.  
  - If the list length is even, the median is the average of the two middle values.
- **Mode**: The most frequently occurring integer (with its frequency).

---

## Directory Structure

```text
c/       # C implementation (procedural)
ocaml/   # OCaml implementation (functional)
python/  # Python implementation (object-oriented)
