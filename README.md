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