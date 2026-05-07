# Annex Technologies Technical Assessment

This repository contains my solutions for the Annex Technologies Limited technical assessment (May 2026).

## In Progress
- [x] Repository Setup
- [x] Question 1: Find the p-th Factor (C)
- [ ] Question 2: Top Scoring Students (SQL)
- [ ] Question 3: Top Articles API (C++)

**Author:** Brian Kimeli

### 1. Finding the p-th Factor (C)
- *Constraint Management:* To handle the $n \leq 10^{15}$ constraint, I used an $O(\sqrt{n})$ approach. A standard linear loop would be too slow for this input size.
- *Data Types:* I used `long` as per the function signature, assuming a 64-bit environment to handle the $10^{15}$ constraint. If this were a 32-bit legacy system, I would have used `long long` to prevent overflow.
- *Algorithm Logic:* - The first loop identifies factors from $1$ up to $\sqrt{n}$.
    - The second loop calculates the "partner" factors ($n / i$) in reverse order. This ensures all factors are found in ascending order without the overhead of a sorting algorithm or large memory allocation.
- *Edge Cases:* The implementation correctly handles perfect squares and returns `0` if $n$ has fewer than $p$ factors.

### 2. Top Scoring Students (SQL)
- *Logic:* The query retrieves the `ID` and `NAME` while applying a dual-layer sort. 
- *Sorting Precedence:* - The primary sort is on `SCORE` in descending order (highest scores first). 
    - The secondary sort is on `ID` in ascending order. This acts as a deterministic tie-breaker for students with identical scores (e.g., in the sample data, Dick and Jerry both scored 85.0, but Dick is prioritized because of his lower ID).
- *Optimization:* Used the `LIMIT` clause to ensure only the top three records are processed and returned.