## 8-Queens with Obstacles — Backtracking Solver

### Overview

This project solves a constrained version of the classic 8-Queens problem using recursive backtracking. The objective is to count all valid ways to place 8 queens on an 8×8 chessboard while respecting both chess constraints and blocked cells.

Each valid configuration must satisfy:

* Exactly one queen per row
* No two queens share the same column
* No two queens share a diagonal
* Queens cannot be placed on blocked cells

The output is the total number of valid configurations.

---

## Problem Definition

Given an 8×8 chessboard:

* `.` represents an empty cell
* `*` represents a blocked cell (cannot place a queen)

You must compute how many ways 8 queens can be placed such that:

* No queen attacks another
* No queen is placed on a blocked cell

Blocked cells only restrict placement. They do not affect attack paths.

---

## Input Format

* 8 lines
* Each line contains exactly 8 characters
* Characters are either:

  * `.` → free cell
  * `*` → blocked cell

Example:

```
*.......
........
........
........
....*...
........
........
.......*
```

---

## Output Format

A single integer:

* Number of valid queen placements

If no valid configuration exists:

```
0
```

No additional text should be printed.

---

## Approach

The solution uses **recursive backtracking**:

1. Process the board row by row
2. Try placing a queen in each column of the current row
3. Validate each placement:

   * Cell is not blocked
   * No column conflict
   * No diagonal conflict
4. Recurse to the next row
5. Count valid completions

---

## State Representation

Instead of storing a full board of queens, we use:

* `queens[row] = col`

This compact representation allows efficient conflict checking.

---

## Safety Check Logic

A position `(row, col)` is valid if:

* It is not blocked (`*`)
* No previous queen shares the same column
* No previous queen lies on the same diagonal

Diagonal condition:

```
abs(row1 - row2) != abs(col1 - col2)
```

---

## Algorithm

* Start from row 0
* For each row:

  * Try all columns
  * If valid, place queen and move to next row
* Base case:

  * If row == 8 → count one valid solution

---

## Complexity

Worst case:

* O(8!) placements (heavily reduced by constraints)

Practical performance:

* Extremely fast due to pruning from:

  * column conflicts
  * diagonal conflicts
  * blocked cells

---

## Key Concept

This is a classic example of:

* Depth-first search (DFS)
* Backtracking
* Constraint satisfaction problem (CSP)

---

## Project Structure

* `readBoard()` → input parsing
* `isSafe()` → constraint validation
* `solve()` → recursive backtracking engine
* `main()` → input/output only

---

## Notes

* Obstacles do not block queen attacks
* Only placement is restricted by `*`
* Output must be a single integer (no extra formatting)

---

## Learning Outcome

This project demonstrates:

* Recursive problem decomposition
* State-space search
* Efficient pruning techniques
* Clean separation of concerns in C++
